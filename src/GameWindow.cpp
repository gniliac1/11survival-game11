#include "pch.h"
#include "GameWindow.h"


GameWindow::GameWindow(size_t width, size_t height, cdouble frameRate, cstring windowTitle)
	: _map( std::make_unique<tmx::MapLoader>("../graphics/maps") ),
	_player( std::make_unique<Player>() ) ,
	_window( std::make_unique<sf::RenderWindow>( sf::VideoMode(width,height) , windowTitle) )
{
	// window options
	_window->setFramerateLimit(frameRate);

	// load the map
	_map->load("markt.tmx");
}

GameWindow::~GameWindow()
{
}

void GameWindow::run()
{
	// main loop
	while (_window->isOpen())
	{
		manageEvents();

		logic();

		render();
	}
}

void GameWindow::manageEvents()
{
	sf::Event event;
	while (_window->pollEvent(event))
	{
		// window resized
		if (event.type == sf::Event::Resized)
		{
			// update the view to the new size of the window
			sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
			_window->setView(sf::View(visibleArea));
		}

		// window closed
		if (event.type == sf::Event::Closed)
		{
			_window->close();
		}
	}
}

void GameWindow::logic()
{
	_player->move();
	check_collisions();
}

void GameWindow::check_collisions()
{
	// get current size of the window
	sf::Vector2u windowSize = _window->getSize();
	sf::FloatRect screen(0.0,0.0,windowSize.x,windowSize.y);
	// update the quad tree
	_map->updateQuadTree(screen);
	// query the quad tree with the bounding box of the player
	std::vector<tmx::MapObject*> objects = _map->queryQuadTree(_player->getBoundingBox());
	//std::cerr << "Collision objects: " << objects.size() << std::endl;
	bool collision = false;
	tmx::MapObject* collisionObject;
	for (const tmx::MapObject* object : objects)
	{
		if (object->getAABB().intersects(_player->getBoundingBox()))
		{
			if (object->getParent() == "market")
			{
				std::cout << object->getName() << std::endl;
			}
			_player->resetLastMove();
			
			break;
		}
	}
}

void GameWindow::render()
{
	_window->clear();

	// draw the scene
	_window->draw( *_map ); // map
	_window->draw( *_player->getSprite() ); // player

	_window->display();
}
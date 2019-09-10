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

	// Load the font for printing log messages
	_statusFont.loadFromFile("arial.ttf");

	// create the GameLog instance
	GameLog::Get()->setMaxEntries(25);
	GameLog::Get()->createLogEntry("Starting GameLog... SUCCESS");
}

GameWindow::~GameWindow()
{
	// delete the GameLog instance
	GameLog::Del();
}

void GameWindow::run()
{
	// main loop
	while (_window->isOpen())
	{
		manageEvents();

		logic();

		render();

		_interactionRequest = false;
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

		// buy items
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Space) {
				_interactionRequest = true;
				GameLog::Get()->createLogEntry("You've issued an interaction ...");
			}
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
	// iterate over all objects in the map
	for (const tmx::MapObject* object : objects)
	{
		if (object->getAABB().intersects(_player->getBoundingBox()))
		{
			if (object->getParent() == "market")
			{
				_objectLabel = object->getName();
				if (_interactionRequest)
				{
					GameLog::Get()->createLogEntry("Congrats, you bought an item!", 16, sf::Color::Red, sf::Text::Bold);
				}
			}
			else if (object->getParent() == "NPC" || object->getParent() == "NPC2")
			{
				_objectLabel = object->getName();
				if (_interactionRequest)
				{
					GameLog::Get()->createLogEntry(std::string("Hello adventurer! My name is ") + _objectLabel + std::string(". Nice to meet you."));
				}
			}
			else
			{
				_player->resetLastMove();
				break;
			}
		}
	}
}

void GameWindow::render()
{
	_window->clear();

	// draw the scene
	_window->draw( *_map ); // map
	_window->draw( *_player->getSprite() ); // player

	if (_objectLabel != "0")
	{
		showObjectLabel(_objectLabel);
		_objectLabel = "0";
	}

	showStatusMessages();

	_window->display();
}

void GameWindow::showObjectLabel(std::string label)
{
	sf::Text text;

	text.setFont(_statusFont);
	text.setString(label);
	text.setPosition(_player->getBoundingBox().left -20. , _player->getBoundingBox().top - 50.);
	text.setCharacterSize(12);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);

	_window->draw(text);
}

void GameWindow::showStatusMessages()
{
	/*const std::deque<sf::Text> logEntries = GameLog::Get()->getLogMessages();
	for ( const sf::Text& entry : logEntries )
	{
		_window->draw(entry);
		std::cout << entry.getString().toAnsiString() << std::endl;
	}*/

	_window->draw(GameLog::Get()->getLogMessages());
}

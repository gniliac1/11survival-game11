#include "pch.h"
#include "EventManager.h"


EventManager::EventManager()
{
}


EventManager::~EventManager()
{
}

void EventManager::checkForEvents()
{
	sf::Event event;
	while (_gameWindow->pollEvent(event))
	{
		// window resized
		if (event.type == sf::Event::Resized)
		{
			// update the view to the new size of the window
			sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
			_gameWindow->setView(sf::View(visibleArea));
		}

		// window closed
		if (event.type == sf::Event::Closed)
		{
			_gameWindow->close();
		}

		// buy items
		if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Space) 
			{
				//_interactionRequest = true;
				//addStatusMessage("You've issued an interaction ...");
			}
		}
	}
}

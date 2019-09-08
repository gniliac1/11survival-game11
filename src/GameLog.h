#pragma once

// standard c++ header
#include<deque> // for deque

// sfml headers
#include <SFML/Graphics.hpp>

// own headers
#include "Singleton.h"

class GameLog : public Singleton<GameLog>
{

public:

	// Empty standard constructor to be called inside the singleton class
	GameLog();
	~GameLog();

	// Add an entry to the game log for user information
	void createLogEntry(const std::string& text, unsigned int size = 15, const sf::Color& color = sf::Color::Black, sf::Uint32 style = sf::Text::Regular);

private:

	// Vector containing the log messages of the last 5 seconds
	std::deque<sf::Text> _logMessages;

	// Font for writing log messages
	sf::Font _logFont;

public:

	// Get list of current log messages
	const std::deque<sf::Text>& getLogMessages() const;
};


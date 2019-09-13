#pragma once

// standard c++ header
#include <deque> // for deque
#include <iostream> // for cerr

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

	// Add an entry to the game log for user information using default text size, color and style
	void createLogEntry(const std::string& text);
	void createLogEntry(const char* text);

	// Add an entry to the game log for user information specifying individual text size, color and style
	void createLogEntry(const std::string& text, unsigned int size, const sf::Color& color, sf::Uint32 style);
	void createLogEntry(const char* text, unsigned int size, const sf::Color& color, sf::Uint32 style);

private:

	// Buffer for rendering the GameLog into a buffer, which is updated every 5s, instead of rendering each text to the screen separately
	std::shared_ptr<sf::RenderTexture> _logBuffer;

	// Clock to check whether the old log messages can be removed from the log messages queue
	sf::Clock _logClock;

	// Color for the log messages (default: sf::Color::Black)
	sf::Color _logColor;

	// Font for writing log messages
	sf::Font _logFont;

	// Vector containing the log messages of the last _nMaxEntries seconds
	std::deque<std::string> _logMessages;

	// Size of the log messages (default: 15)
	unsigned int _logSize;

	// Style for the log messages (default: sf::Text::Regular)
	sf::Uint32 _logStyle;

	// Maximum number of entries which are allowed
	unsigned int _nMaxEntries;

	// Determine the position of every log message on the screen
	void determinePositions();

	// 
	void updateBuffer();

	// Check wehther old log messages can be removed from the log messages queue and remove them eventually
	void updateLogMessages();

public:

	const std::shared_ptr<sf::RenderTexture> getLogBuffer();

	// Get list of current log messages
	const sf::Text getLogMessages();

	// Set a new default log color 
	void setLogColor(const sf::Color& color);

	// Set a new default log size 
	void setLogSize(unsigned int size);

	// Set a new default log sytle 
	void setLogStyle(sf::Uint32 style);

	// Set the maximum number of allowed entries
	void setMaxEntries(unsigned int nMaxEntries);
};


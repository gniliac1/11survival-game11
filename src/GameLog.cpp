#include "pch.h"
#include "GameLog.h"


GameLog::GameLog()
	: _logColor(sf::Color::Black),
	_logSize(15),
	_logStyle(sf::Text::Regular)
{
	// Load the font for printing log messages
	_logFont.loadFromFile("arial.ttf");
}


GameLog::~GameLog()
{
}


void GameLog::createLogEntry(const std::string & text)
{
	createLogEntry(text,_logSize,_logColor,_logStyle);
}


void GameLog::createLogEntry(const char * text)
{
	createLogEntry(text, _logSize, _logColor, _logStyle);
}


void GameLog::createLogEntry(const std::string& text, unsigned int size, const sf::Color& color, sf::Uint32 style)
{
	sf::Text logText;
	logText.setFont(_logFont);
	logText.setString(text);
	logText.setCharacterSize(size);
	logText.setFillColor(color);
	logText.setStyle(style);
	_logMessages.push_back(logText);
}


void GameLog::createLogEntry(const char * text, unsigned int size, const sf::Color & color, sf::Uint32 style)
{
	sf::Text logText;
	logText.setFont(_logFont);
	logText.setString(text);
	logText.setCharacterSize(size);
	logText.setFillColor(color);
	logText.setStyle(style);
	_logMessages.push_back(logText);
}


void GameLog::determinePositions()
{
	int i = 0;
	for (sf::Text& entry : _logMessages)
	{
		entry.setPosition(50, 50 + i++ * 25);
	}
}


void GameLog::updateLogMessages()
{
	if (_logClock.getElapsedTime().asSeconds() > 5.f || _logMessages.size() > _nMaxEntries)
	{
		if (_logMessages.size() > 0)
		{
			_logMessages.pop_front();
		}
		_logClock.restart();
	}
}


const std::deque<sf::Text> GameLog::getLogMessages()
{
	updateLogMessages();
	determinePositions();
	return _logMessages;
}


void GameLog::setLogColor(const sf::Color & color)
{
	_logColor = color;
}


void GameLog::setLogSize(unsigned int size)
{
	_logSize = size;
}


void GameLog::setLogStyle(sf::Uint32 style)
{
	_logStyle = style;
}

void GameLog::setMaxEntries(unsigned int nMaxEntries)
{
	_nMaxEntries = nMaxEntries;
}

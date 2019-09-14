#include "pch.h"
#include "GameLog.h"


GameLog::GameLog()
	: _logBuffer(std::make_shared<sf::RenderTexture>()),
	_logChanged(true), // in order to make sure, that the GameLog is drawn for the first time 
	_logColor(sf::Color::Black),
	_logSize(15),
	_logStyle(sf::Text::Regular)
{
	// Allocate the memory for the buffer
	if (!_logBuffer->create(250, 500))
	{
		std::cerr << "Unable to create the buffer for the GameLog" << std::endl;
	}

	// Load the font for printing log messages
	_logFont.loadFromFile("arial.ttf");
}


GameLog::~GameLog()
{
}


void GameLog::createLogEntry(const std::string & text)
{
	// delegate to void GameLog::createLogEntry(const char * text, unsigned int size, const sf::Color & color, sf::Uint32 style)
	createLogEntry(text.c_str(),_logSize,_logColor,_logStyle);
}


void GameLog::createLogEntry(const char * text)
{
	// delegate to void GameLog::createLogEntry(const char * text, unsigned int size, const sf::Color & color, sf::Uint32 style)
	createLogEntry(text, _logSize, _logColor, _logStyle);
}


void GameLog::createLogEntry(const std::string& text, unsigned int size, const sf::Color& color, sf::Uint32 style)
{
	// delegate to void GameLog::createLogEntry(const char * text, unsigned int size, const sf::Color & color, sf::Uint32 style)
	createLogEntry(text.c_str(), size, color, style);
}


void GameLog::createLogEntry(const char * text, unsigned int size, const sf::Color & color, sf::Uint32 style)
{
	// create an sf::Text instance with the specified properties
	sf::Text logText;
	logText.setFont(_logFont);
	logText.setString(text);
	logText.setCharacterSize(size);
	logText.setFillColor(color);
	logText.setStyle(style);
	// add the instance to the list of messages
	_logMessages.push_back(logText);
	// the log has changed
	_logChanged = true;
}


void GameLog::updateBuffer()
{
	// clear the buffer
	_logBuffer->clear(sf::Color(255,255,255,100));

	// determine the positions of each message
	int i = 0;
	for (sf::Text& entry : _logMessages)
	{
		entry.setPosition(0.0f, i++ * 25.0f);

		// draw text to the buffer
		_logBuffer->draw(entry);
	}

	// We're done drawing to the texture
	_logBuffer->display();

	// the buffer has been updated, no changes to be accounted for
	_logChanged = false;
}


void GameLog::updateLogMessages()
{
	// check whether 5s have passed or if the number of messages exceeds the limit
	if (_logClock.getElapsedTime().asSeconds() > 5.f || _logMessages.size() > _nMaxEntries)
	{
		// if there is at least one element present, delete the one which is first in the queue
		if (_logMessages.size() > 0)
		{
			_logMessages.pop_front();
			// the log has been modified
			_logChanged = true;
		}
		_logClock.restart();
	}
}


const std::shared_ptr<sf::RenderTexture> GameLog::getLogBuffer()
{
	// delete log messages which are no longer relevant
	updateLogMessages();
	// render the text to the buffer, if anything has changed within the last tick
	if (_logChanged)
	{
		updateBuffer();
	}

	return _logBuffer;
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

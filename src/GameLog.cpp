#include "pch.h"
#include "GameLog.h"


GameLog::GameLog()
	: _logBuffer(std::make_shared<sf::RenderTexture>()),
	_logColor(sf::Color::Black),
	_logSize(15),
	_logStyle(sf::Text::Regular)
{
	// 
	if (!_logBuffer->create(250, 500))
	{
		std::cerr << "Unable to create buffer for texture" << std::endl;
	}

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
	/*sf::Text logText;
	logText.setFont(_logFont);
	logText.setString(text);
	logText.setCharacterSize(size);
	logText.setFillColor(color);
	logText.setStyle(style);
	_logMessages.push_back(logText);*/
	_logMessages.push_back(text);
}


void GameLog::createLogEntry(const char * text, unsigned int size, const sf::Color & color, sf::Uint32 style)
{
	/*sf::Text logText;
	logText.setFont(_logFont);
	logText.setString(text);
	logText.setCharacterSize(size);
	logText.setFillColor(color);
	logText.setStyle(style);
	_logMessages.push_back(logText);*/
	_logMessages.push_back(text);
}


void GameLog::determinePositions()
{
	/*int i = 0;
	for (sf::Text& entry : _logMessages)
	{
		entry.setPosition(50, 50 + i++ * 25);
	}*/
}

void GameLog::updateBuffer()
{
	// clear the buffer
	_logBuffer->clear(sf::Color(255,255,255,100));

	// dummy variable
	sf::Text logText;
	int i = 0;
	for (std::string& entry : _logMessages)
	{
		logText.setFont(_logFont);
		logText.setString(entry);
		logText.setCharacterSize(_logSize);
		logText.setFillColor(_logColor);
		logText.setStyle(_logStyle);
		logText.setPosition(0.0f, i++ * 25.0f);

		// draw text to the buffer
		_logBuffer->draw(logText);
	}

	// We're done drawing to the texture
	_logBuffer->display();
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


const std::shared_ptr<sf::RenderTexture> GameLog::getLogBuffer()
{
	updateLogMessages();
	updateBuffer();
	return _logBuffer;
}

//const std::deque<sf::Text> GameLog::getLogMessages()
const sf::Text GameLog::getLogMessages()
{
	updateLogMessages();
	//determinePositions();
	std::string result;
	int i = 0;
	for (std::string& entry : _logMessages)
	{
		result += entry + std::string("\n");
	}

	sf::Text logText;
	logText.setFont(_logFont);
	logText.setString(result);
	logText.setCharacterSize(_logSize);
	logText.setFillColor(_logColor);
	logText.setStyle(_logStyle);
	logText.setPosition(50.0f, 50.0f);

	return logText;
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

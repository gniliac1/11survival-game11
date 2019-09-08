#include "pch.h"
#include "GameLog.h"


GameLog::GameLog()
{
}


GameLog::~GameLog()
{
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

const std::deque<sf::Text>& GameLog::getLogMessages() const
{
	return _logMessages;
}

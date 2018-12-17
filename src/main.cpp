// Stages.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include "pch.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 540), "SFML works!");
	window.setFramerateLimit(60); // call it once, after creating the window

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	// load a texture
	sf::Texture texture;
	if (!texture.loadFromFile("../graphics/sprites/people/male_walkcycle.png", sf::IntRect(0, 128, 64, 64)))
	{
		std::cerr << "Alles kaputt! :(" << std::endl;
	}

	// create a sprite
	sf::Sprite sprite;
	sprite.setTexture(texture);

	// position
	sprite.setPosition(sf::Vector2f(480.f, 270.f)); // absolute position
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// catch the resize events
			if (event.type == sf::Event::Resized)
			{
				// update the view to the new size of the window
				sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
				window.setView(sf::View(visibleArea));
			}

			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// left key is pressed: move our character
			sprite.move(sf::Vector2f(-2.5, 0.f)); // offset relative to the current position
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// right key is pressed: move our character
			sprite.move(sf::Vector2f(2.5, 0.f)); // offset relative to the current position
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			// up key is pressed: move our character
			sprite.move(sf::Vector2f(0.f, -2.5)); // offset relative to the current position
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			// left key is pressed: move our character
			sprite.move(sf::Vector2f(0.f, 2.5)); // offset relative to the current position
		}

		window.clear();
		window.draw(shape);
		// inside the main loop, between window.clear() and window.display()
		window.draw(sprite);
		window.display();
	}
    std::cout << "Hello World!\n"; 
}

// Programm ausführen: STRG+F5 oder "Debuggen" > Menü "Ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.

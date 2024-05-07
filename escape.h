#pragma once

#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>

class escape
{
public:
	escape();
	void initTexture(std::string escapeTexture);
	void setPos(sf::Vector2f newPos);
	sf::FloatRect getGlobalBounds();
	void DrawTo(sf::RenderWindow& window);
private:
	sf::RectangleShape Escape;
	sf::Texture texture;
};


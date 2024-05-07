#pragma once

#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>

class wall
{
public:
	wall();
	void DrawTo(sf::RenderWindow& window);
	void setPos(sf::Vector2f newPos);
	sf::Vector2f getPos();
	sf::FloatRect getGlobalBounds();
	void initTexture(std::string wallTexture);
private:
	sf::RectangleShape Wall;
	sf::Texture texture;

};


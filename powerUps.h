#pragma once

#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>

class powerUps
{
public:
	powerUps();
	void initTexture(std::string powerUpTexture);
	void setPos(sf::Vector2f newPos);
	sf::FloatRect getGlobalBounds();
	void DrawTo(sf::RenderWindow& window);
	void setId(int Id);
	int getId();
private:
	sf::RectangleShape PowerUp;
	sf::Texture texture;
	int Id;
};


#pragma once

#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>

class key
{
public:
	key();
	void initTexture(std::string keyTexture);
	void setPos(sf::Vector2f newPos);
	sf::FloatRect getGlobalBounds();
	void DrawTo(sf::RenderWindow& window);
	void setId(int Id);
	int getId();
private:
	sf::RectangleShape Key;
	sf::Texture texture;
	int Id;
};


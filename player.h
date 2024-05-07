#pragma once

#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include "animation.h"

class player
{
public:
	~player();
	player();
	void DrawTo(sf::RenderWindow& window);
	void setPos(sf::Vector2f newPos);
	void move(sf::Vector2f newPos);
	sf::Vector2f getPos();
	sf::FloatRect getGlobalBounds();
	void addKey();
	void resetKey();
	int getKey();
	void setLifes(int amount);
	void minusLife();
	int getLifes();
	void initTexture(std::string playerTexture);
	void animationTexture(sf::IntRect texture);
	void addLife();
	sf::Texture texture;
private:
	sf::RectangleShape Player;
	int keys = 0;
	int lifes = 3;

};


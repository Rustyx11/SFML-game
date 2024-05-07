#pragma once

#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include<cmath>
#include "animation.h"

class enemy
{
public:
	enemy(sf::Vector2f size);
	void DrawTo(sf::RenderWindow& window);
	void setPos(sf::Vector2f newPos);
	void move(sf::Vector2f distance);
	void movement();
	sf::Vector2f getPos();
	sf::FloatRect getGlobalBounds();
	void movementInit(sf::Vector2f finish, float speed);
	void initTexture(std::string enemyTexture);
	void animationTexture(sf::IntRect texture);
	sf::Texture* getTexture();
	bool getDirection();
private:
	sf::Texture texture;
	sf::RectangleShape Enemy;
	sf::Vector2f start;
	sf::Vector2f finish;
	sf::Vector2f trajectory;
	bool direction = true;

};


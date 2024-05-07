#pragma once

#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>

class animation
{
public:
	void initAnimation(sf::Texture *texture, int row, int column, float switchTime);
	void update(float dt, int currentRow);
	sf::IntRect textureRect;
private:
	float time = 0;
	int rows;
	int columns;
	float switchTime;
	int currentColumn;
	sf::Texture texture;
};


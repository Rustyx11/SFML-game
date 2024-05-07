#pragma once

#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>

class heart
{
public:
	heart();
	void DrawTo(sf::RenderWindow& window);
	void initTexture(std::string heartTexture);
	void setPos(sf::Vector2f newPos);
private:
	sf::RectangleShape Heart;
	sf::Texture texture;
};


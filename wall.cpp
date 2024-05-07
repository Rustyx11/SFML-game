#include "wall.h"

wall::wall()
{
	Wall.setSize({ 40,40 });
}

void wall::DrawTo(sf::RenderWindow& window)
{
	window.draw(Wall);
}

void wall::setPos(sf::Vector2f newPos)
{
	Wall.setPosition(newPos);
}

sf::Vector2f wall::getPos()
{
	return Wall.getPosition();
}

sf::FloatRect wall::getGlobalBounds()
{
	return Wall.getGlobalBounds();
}

void wall::initTexture(std::string wallTexture)
{
	this->texture.loadFromFile(wallTexture);
	Wall.setTexture(&texture);
}



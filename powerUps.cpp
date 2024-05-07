#include "powerUps.h"

powerUps::powerUps()
{
	PowerUp.setSize({ 40,40 });
}

void powerUps::initTexture(std::string powerUpTexture)
{
	this->texture.loadFromFile(powerUpTexture);
	PowerUp.setTexture(&texture);
}

void powerUps::setPos(sf::Vector2f newPos)
{
	PowerUp.setPosition(newPos);
}

sf::FloatRect powerUps::getGlobalBounds()
{
	return PowerUp.getGlobalBounds();
}

void powerUps::DrawTo(sf::RenderWindow& window)
{
	window.draw(PowerUp);
}

void powerUps::setId(int Id)
{
	this->Id = Id;
}

int powerUps::getId()
{
	return this->Id;
}

#include "animation.h"

/*
void animation::initAnimation(sf::Texture texture, int row, int column, float switchTime, int currentRow)
{
	this->texture = texture;
	this->rows = row;
	this->columns = column;
	this->switchTime = switchTime;
	this->width = texture.getGlobalBounds().width;
	this->height = texture.getGlobalBounds().height;
	this->currentRow = currentRow;
}

sf::Texture animation::update( float dt)
{
	this->time += dt;
	if (this->time > this->switchTime)
	{
		if (this->currentColumn <= this->columns-1)
		{
			this->currentColumn++;
		}
		else
		{
			this->currentColumn = 0;
		}
		texture.set;
		this->time = 0;
		
	}
	return texture;
	
}
*/
/** \brief Inicjacja animacji gracza
* @param texture
* @param row
* @param column
* @param switchTime
* @return Funkcja nie zwraca wartosci
*/
void animation::initAnimation(sf::Texture* texture, int row, int column, float switchTime)
{
	this->rows = row;
	this->columns = column;

	this->switchTime = switchTime;

	textureRect.width = texture->getSize().x / column;
	textureRect.height = texture->getSize().y / row;
	
}
/** \brief Aktualizacja animacji gracza
* @param dt
* @param currentRow
* @return Funkcja nie zwraca wartosci
*/
void animation::update(float dt, int currentRow)
{
	this->time += dt;
	if (this->time > this->switchTime)
	{

		this->currentColumn++;
		
		if (currentColumn > this->columns-1)
		{
			this->currentColumn = 0;
		}
		this->time = 0;
		
	}
	textureRect.left = currentColumn * textureRect.width;
	textureRect.top = currentRow * textureRect.height;
}

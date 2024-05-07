#include "enemy.h"
/** \brief Rozmiar przeciwnika
* @param size
* @return Funkcja nie zwraca wartosci
*/
enemy::enemy(sf::Vector2f size)
{
	Enemy.setSize(size);
}
/** \brief Wyswietlanie przeciwnika
* @param window
* @return Funkcja nie zwraca wartosci
*/
void enemy::DrawTo(sf::RenderWindow& window)
{
	window.draw(Enemy);
}
/** \brief Ustawianie pozycji przeciwnika
* @param newPos
* @return Funkcja nie zwraca wartosci
*/
void enemy::setPos(sf::Vector2f newPos)
{
	Enemy.setPosition(newPos);
}
/** \brief Ruch przeciwnika
* @param distance
* @return Funkcja nie zwraca wartosci
*/
void enemy::move(sf::Vector2f distance)
{
	Enemy.move(distance);
}
/** \brief Szybkosc poruszania sie przeciwnika
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
void enemy::movement()
{

	if (Enemy.getPosition().x > finish.x || Enemy.getPosition().y > finish.y)
	{
		direction = false;
	}
	else if (Enemy.getPosition().x < start.x || Enemy.getPosition().y < start.y)
	{
		direction = true;
	}

	if (direction)
	{
		Enemy.move(-this->trajectory);
	}
	else
	{
		Enemy.move(this->trajectory);
	}
	
	
}
/** \brief Pobiera pozycje przeciwnika
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
sf::Vector2f enemy::getPos()
{
	return Enemy.getPosition();
}
/** \brief Rozmiar siatki przeciwnka
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
sf::FloatRect enemy::getGlobalBounds()
{
	return Enemy.getGlobalBounds();
}
/** \brief Inicjalizacja ruchu przeciwnika
* @param finish
* @param speed
* @return Funkcja nie zwraca wartosci
*/
void enemy::movementInit(sf::Vector2f finish, float speed)
{
	this->start = Enemy.getPosition();
	this->finish = finish;

	float deltaX = start.x - finish.x;
	float deltaY = start.y - finish.y;

	float speedX = deltaX / speed;
	float speedY = deltaY / speed;

	this->trajectory = { speedX,speedY };

}
/** \brief Inicjalizacja tekstury przeciwnika
* @param enemyTexture
* @return Funkcja nie zwraca wartosci
*/
void enemy::initTexture(std::string enemyTexture)
{
	this->texture.loadFromFile(enemyTexture);
	texture.setRepeated(true);
	Enemy.setTexture(&texture);
}
/** \brief Animacja przeciwnka
* @param texture
* @return Funkcja nie zwraca wartosci
*/
void enemy::animationTexture(sf::IntRect texture)
{
	Enemy.setTextureRect(texture);
}
/** \brief Pobiera teksture przeciwnka
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
sf::Texture* enemy::getTexture()
{
	return &texture;
}
/** \brief Pobiera kierunek ruchu przeciwnka
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
bool enemy::getDirection()
{
	return this->direction;
}

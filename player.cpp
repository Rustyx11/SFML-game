#include "player.h"

player::~player()
{
}
/** \brief Rozmiar gracza
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
player::player()
{
	Player.setSize({ 40,40 });
}
/** \brief Rysowanie gracza
* @param window
* @return Funkcja nie zwraca wartosci
*/
void player::DrawTo(sf::RenderWindow& window)
{
	window.draw(Player);
}
/** \brief Ustalenie pozycji gracza
* @param newPos
* @return Funkcja nie zwraca wartosci
*/
void player::setPos(sf::Vector2f newPos)
{
	Player.setPosition(newPos);
}
/** \brief Ruch gracza
* @param distance
* @return Funkcja nie zwraca wartosci
*/
void player::move(sf::Vector2f distance)
{
	Player.move(distance);
}
/** \brief Pobiera pozycje gracza
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
sf::Vector2f player::getPos()
{
	return Player.getPosition();
}
/** \brief Rozmiar siatki gracza
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
sf::FloatRect player::getGlobalBounds()
{
	return Player.getGlobalBounds();
}
/** \brief Dodanie kluczy
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
void player::addKey()
{
	this->keys++;
}
/** \brief Resetowanie kluczy
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
void player::resetKey()
{
	this->keys = 0;
}
/** \brief Pobieranie kluczy przez gracza
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
int player::getKey()
{
	return this->keys;
}
/** \brief Ustawienie ¿ycia gracza
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
void player::setLifes(int amount)
{
	this->lifes = amount;
}

/** \brief Odbieranie ¿ycia gracza
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
void player::minusLife()
{
	this->lifes--;
}
/** \brief Zdobywanie ¿ycia
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
int player::getLifes()
{
	return this->lifes;
}
/** \brief Textura gracza
* @param playerTexture
* @return Funkcja nie zwraca wartosci
*/
void player::initTexture(std::string playerTexture)
{
	this->texture.loadFromFile(playerTexture);
	texture.setRepeated(true);
	Player.setTexture(&texture);
}
/** \brief Animacja gracza
* @param texture
* @return Funkcja nie zwraca wartosci
*/
void player::animationTexture(sf::IntRect texture)
{
	Player.setTextureRect(texture);
}
/** \brief Dodawanie ¿yæ
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
void player::addLife()
{
	this->lifes++;
}






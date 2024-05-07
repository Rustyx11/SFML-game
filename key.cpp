#include "key.h"
/** \brief Rozamir klucza
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
key::key()
{
	Key.setSize({ 40,40 });
}
/** \brief Inicjalizacja tekstury klucza
* @param keyTexture
* @return Funkcja nie zwraca wartosci
*/
void key::initTexture(std::string keyTexture)
{
	this->texture.loadFromFile(keyTexture);
	Key.setTexture(&texture);
}
/** \brief Ustawienie pozycji klucza
* @param newPos
* @return Funkcja nie zwraca wartosci
*/
void key::setPos(sf::Vector2f newPos)
{
	Key.setPosition(newPos);
}
/** \brief Rozmiar siatki klucza
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
sf::FloatRect key::getGlobalBounds()
{
	return Key.getGlobalBounds();
}
/** \brief Rysowanie klucza
* @param window
* @return Funkcja nie zwraca wartosci
*/
void key::DrawTo(sf::RenderWindow& window)
{
	window.draw(Key);
}
/** \brief ID Klucza
* @param Id
* @return Funkcja nie zwraca wartosci
*/
void key::setId(int Id)
{
	this->Id = Id;
}
/** \brief Pobiera ID klucza
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
int key::getId()
{
	return this->Id;
}

#include "escape.h"
/** \brief Rozmiar wyjscia
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
escape::escape()
{
	Escape.setSize({ 40,40 });
}
/** \brief Inicjalizacja tekstury wyjscia
* @param escapeTexture
* @return Funkcja nie zwraca wartosci
*/
void escape::initTexture(std::string escapeTexture)
{
	this->texture.loadFromFile(escapeTexture);
	Escape.setTexture(&texture);
}
/** \brief Ustawienie pozycji wyjscia
* @param newPos
* @return Funkcja nie zwraca wartosci
*/
void escape::setPos(sf::Vector2f newPos)
{
	Escape.setPosition(newPos);
}
/** \brief Rozmiar siatki wyjscia
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
sf::FloatRect escape::getGlobalBounds()
{
	return Escape.getGlobalBounds();
}
/** \brief Wyswietlanie wyjscia
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
void escape::DrawTo(sf::RenderWindow& window)
{
	window.draw(Escape);
}

#include "heart.h"
/** \brief Rozmiar serca gracza
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
heart::heart()
{
	Heart.setSize({ 40,40 });
}
/** \brief Wyswietlanie serca gracza
* @param window
* @return Funkcja nie zwraca wartosci
*/
void heart::DrawTo(sf::RenderWindow& window)
{
	window.draw(Heart);
}
/** \brief Inicjalizacja tekstury serca gracza
* @param heartTexture
* @return Funkcja nie zwraca wartosci
*/
void heart::initTexture(std::string heartTexture)
{
	this->texture.loadFromFile(heartTexture);
	Heart.setTexture(&texture);
}
/** \brief Ustawienie pozycji serca
* @param newPos
* @return Funkcja nie zwraca wartosci
*/
void heart::setPos(sf::Vector2f newPos)
{
	Heart.setPosition(newPos);
}

#include "ladder.h"
/** \brief Rozmiar drabiny
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
ladder::ladder()
{
	Ladder.setSize({ 40,40 });
	
}
/** \brief Wyswietlanie drabiny
* @param window
* @return Funkcja nie zwraca wartosci
*/
void ladder::DrawTo(sf::RenderWindow& window)
{
	window.draw(Ladder);
}
/** \brief Pozycja drabiny
* @param newPos
* @return Funkcja nie zwraca wartosci
*/
void ladder::setPos(sf::Vector2f newPos)
{
	Ladder.setPosition(newPos);
}
/** \brief Pobiera pozycje drabiny
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
sf::Vector2f ladder::getPos()
{
	return Ladder.getPosition();
}
/** \brief Rozmiar siatki drabiny
* @param brak parametru
* @return Funkcja nie zwraca wartosci
*/
sf::FloatRect ladder::getGlobalBounds()
{
	return Ladder.getGlobalBounds();
}
/** \brief Wczytanie tekstury drabiny
* @param ladderTexture
* @return Funkcja nie zwraca wartosci
*/
void ladder::initTexture(std::string ladderTexture)
{
	this->texture.loadFromFile(ladderTexture);
	Ladder.setTexture(&texture);
}

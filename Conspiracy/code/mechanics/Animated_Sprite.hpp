#ifndef ANIMATED_SPRITE_HPP
#define ANIMATED_SPRITE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

class Animated_Sprite : public sf::Sprite
{
public:
	Animated_Sprite();
	void animate(sf::Vector2f frame, int row, int col, int deltaT, bool backward);
	void setFrame(sf::Vector2f frame);	// ustala rozmiar klatki
	void setCol(int col);	// ustawia liczbe kolumn
	

private:

	sf::Vector2f frameSize;
	int colNumber;
	int frameCounter ;	// mierzy aktualna ilosc klatek gry na 1 klatke animacji
	int colCounter ;		// wskazuje na wyswietlana kolumne
};

#endif

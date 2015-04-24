#include "Animated_Sprite.hpp"

void Animated_Sprite::animate(sf::Vector2f frameSize, int row, int col, int deltaFrame, bool backward) // frameSize = rozmiar klatki, row rzad animacji, col ilosc kolumn, deltaFrame ilosc klatek gry na 1 animacji, backward czy wyswietlic obrazek z prawej do lewej
{
	if (!backward)	this->setTextureRect(sf::IntRect(colCounter*frameSize.x, row*frameSize.y, frameSize.x, frameSize.y));	
	else this->setTextureRect(sf::IntRect((colCounter+1)*frameSize.x, row*frameSize.y, frameSize.x*(-1), frameSize.y));
	if (frameCounter >= deltaFrame)	// wiekszy rowny, bo czasem nie zdazy zlapac przy czestym przelaczaniu animacji i sie buguje, a tak jest troche niechlujnie, ale tej niechlujnosci nie widac
	{
		colCounter++;
		frameCounter = 0;
	}
	else frameCounter++;
	if (colCounter == col) colCounter = 0;
}

void Animated_Sprite::setFrame(sf::Vector2f frame)
{
	frameSize = frame;
}

void Animated_Sprite::setCol(int col)
{
	colNumber = col;
}
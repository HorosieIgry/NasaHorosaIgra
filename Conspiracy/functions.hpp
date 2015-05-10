#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <SFML/Graphics.hpp>

#include <iostream>

#include "Screen.hpp"

int load_font(sf::Font *font, const char* filename);
void fadein_message(sf::Text* text);
void brighten_fade(   sf::RectangleShape* cush);
void darken_fade(sf::RectangleShape* cush);
int next_text(sf::Text* text, std::string messages[6], int nr);

#endif
	
	

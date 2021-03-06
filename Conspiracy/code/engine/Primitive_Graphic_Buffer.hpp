#ifndef PRIMITIVE_GRAPHIC_BUFFER_HPP
#define PRIMITIVE_GRAPHIC_BUFFER_HPP

#include <vector>
#include "SFML/Graphics.hpp"
#include "My_View.hpp"

class PrimitiveGraphicBuffer{
	
	private:
	sf::RenderWindow* window;
	int sprite_size;
	int text_size;
	std::vector<sf::Sprite>   sprites;
	std::vector<sf::Text>   texts;
	void clear();
	
	public:
	My_View std_view;
	
	PrimitiveGraphicBuffer();

	
	void addSprite(sf::Sprite);
	void addText(sf::Text);
	
	void push();
	void setRenderWindow(sf::RenderWindow * w);
	
	
	};
	
#endif
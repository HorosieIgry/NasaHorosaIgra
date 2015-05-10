#include "functions.hpp"

int load_font(sf::Font *font, const char* filename){

	if (!(font->loadFromFile(filename))){
		std::cout << "Failed to load font from " << filename << std::endl;
		return 1;
	}
	else return 0;

}


void fadein_message(sf::Text* text){


	sf::FloatRect textRect = text->getLocalBounds();
	text->setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text->setPosition(SCRWIDTH / 2, SCRHEIGHT / 2);
	text->setColor(sf::Color(255.f, 255.f, 255.f));

};


void brighten_fade(sf::RectangleShape* cush){
	if (cush->getFillColor().a>0.f){

		if (cush->getFillColor().a - 7.5f>0.f)cush->setFillColor(sf::Color(0.f, 0.f, 0.f, cush->getFillColor().a - 7.5f));
		else {
			cush->setFillColor(sf::Color(0.f, 0.f, 0.f, 0.f));
		}
		std::cout << float(cush->getFillColor().a) << std::endl;
	}


}


void darken_fade(sf::RectangleShape* cush){
	if (cush->getFillColor().a<255.f){

		if (cush->getFillColor().a + 7.5f<255.f)cush->setFillColor(sf::Color(0.f, 0.f, 0.f, cush->getFillColor().a + 7.5f));
		else
		{
			cush->setFillColor(sf::Color(0.f, 0.f, 0.f, 255.f));
		}
		std::cout << float(cush->getFillColor().a) << std::endl;
	}


}

int next_text(sf::Text* text, std::string messages[6], int nr){
	if (nr>2)return 1;
	else{
		sf::String uploader = messages[nr];
		text->setString(uploader.toWideString());
		return 0;
	}

};

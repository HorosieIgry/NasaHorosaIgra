#ifndef MY_VIEW_HPP
#define MY_VIEW_HPP

#include "SFML/System/Vector2.hpp"
#include "SFML/Graphics.hpp"
#include "../../Screen.hpp"

class My_View : public sf::View{

public:

void center_on(sf::Sprite sprite);

void standard_view(sf::Sprite sprite,int flr_height);

};

#endif
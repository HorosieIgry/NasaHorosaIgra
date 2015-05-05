#include "World_Constants.hpp"

World_Constants::World_Constants(){
	
floor_height = 0.25*SCRHEIGHT;

player_size = sf::Vector2f(93,64);

platform_width = 2*player_size.x;

jmp_velocity = 30;
gravitational_force = 2;

};

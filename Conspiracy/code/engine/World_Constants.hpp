#ifndef WORLD_CONSTANTS_HPP
#define WORLD_CONSTANTS_HPP

#include "SFML/System/Vector2.hpp"
#include "../../Screen.hpp"

class World_Constants{

public:

//platforms
int floor_height;
int platform_width;

//player
sf::Vector2f player_size;


//jumping
int gravitational_force;
int jmp_velocity;

World_Constants();

};

#endif

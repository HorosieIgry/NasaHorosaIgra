#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Animated_Sprite.hpp"
#include "Platforms.hpp"

class Player : public Animated_Sprite{
public:
bool afloat(Platforms f,int floor_w,int plr_x);

};

#endif
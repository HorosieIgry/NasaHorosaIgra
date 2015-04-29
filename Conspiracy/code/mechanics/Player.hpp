#include "Animated_Sprite.hpp"

class Player : public Animated_Sprite{
public:
bool afloat(Platforms f,int floor_w,int plr_x);
sf::Vector2f movement;
bool isCollidingHorizontally(Platforms f);
bool isCollidingTop();
bool isCollidingBot(Platforms f);

private:
	World_Constants world;

};

bool  Player::afloat(Platforms f,int floor_w,int plr_x){

int ex =getPosition().x ;
if(ex>40*floor_w) return true;
int index = ((ex - ex%floor_w)/floor_w);

if (f.floor[index] == 0 && (ex%floor_w<floor_w - plr_x)) return true;
	
return false;
};

bool Player::isCollidingBot(Platforms f)
{
	int playerX = getPosition().x;
	int index = ((playerX - playerX % world.platform_width) / world.platform_width);
	if ( f.floor[index] == 0 && (playerX % world.platform_width < world.platform_width - world.player_size.x) ) return false;

	return true;
}

bool Player::isCollidingHorizontally(Platforms f)
{
	int playerX = getPosition().x;
	float playerY = getPosition().y;
	int index = ((playerX - playerX % world.platform_width) / world.platform_width);

	// lewa strona, nie mam narazie pomyslu na zmniejszenie ilosc warunkow wiec sa 3 (rog gracza do rogu planszy): dolny wiekszy od gornego i dolny mniejszy od dolnego ; gorny mniejszy od gornego, dolny wiekszy od dolnego ; gorny mniejszy od dolnego, gorny wiekszy od gornego
	if (index > 0 && f.floor[index - 1] == 1 && playerY + world.player_size.y > f.platforms[index - 1].getPosition().y  && playerY + world.player_size.y < f.platforms[index - 1].getPosition().y + world.platform_height ||
		index > 0 && f.floor[index - 1] == 1 && playerY < f.platforms[index - 1].getPosition().y  && playerY + world.player_size.y > f.platforms[index - 1].getPosition().y + world.platform_height ||
		index > 0 && f.floor[index - 1] == 1 && playerY < f.platforms[index - 1].getPosition().y + world.platform_height  && playerY > f.platforms[index - 1].getPosition().y
		) return true;

	// prawa strona na tej samej zasadzie
	if (f.floor[index + 1] == 1 && playerY + world.player_size.y > f.platforms[index + 1].getPosition().y  && playerY + world.player_size.y < f.platforms[index + 1].getPosition().y + world.platform_height ||
		index > 0 && f.floor[index + 1] == 1 && playerY < f.platforms[index + 1].getPosition().y  && playerY + world.player_size.y > f.platforms[index + 1].getPosition().y + world.platform_height ||
		index > 0 && f.floor[index + 1] == 1 && playerY < f.platforms[index + 1].getPosition().y + world.platform_height  && playerY > f.platforms[index + 1].getPosition().y
		) return true;
	
	return false;
}

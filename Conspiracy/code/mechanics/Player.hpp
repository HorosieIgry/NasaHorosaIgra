class Player : public sf::Sprite{
public:
bool afloat(Floor_Maker f,int floor_w,int plr_x);

};

bool  Player::afloat(Floor_Maker f,int floor_w,int plr_x){
bool flying = false;
int ex =getPosition().x ;
if(ex>20*floor_w)return true;
int index = ((ex - ex%floor_w)/floor_w);
if (index>=20)return false;
if(f.floor[index]==0&&(ex%floor_w<floor_w-plr_x)){
	flying =true;
	
	
	}


return flying;
};

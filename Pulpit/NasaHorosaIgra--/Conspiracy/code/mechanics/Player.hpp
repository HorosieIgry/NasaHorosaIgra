

class Player : public Animated_Sprite{
public:
bool afloat(Platforms f,int floor_w,int plr_x);

};

bool  Player::afloat(Platforms f,int floor_w,int plr_x){
bool flying = false;
//int insanidade = f.getPointer() -20*floor_w;
int ex =getPosition().x; //- insanidade;


if(ex<-plr_x)return true;
int index = ((ex - ex%floor_w)/floor_w);
//if (index>=20)return false;
if(f.platform_map[index]==0&&(ex%floor_w<floor_w-plr_x)){
	flying =true;
	
	
	}


return flying;
};

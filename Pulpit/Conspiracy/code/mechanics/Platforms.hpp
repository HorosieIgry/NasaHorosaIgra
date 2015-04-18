class Platforms{
	
private:
	sf::Texture good_one(int x,int y);
	sf::Sprite ziutek[20];
	
public:
std::vector<sf::Sprite>platforms;
Platforms(int width,int height);
Platforms();
void make(Floor_Maker f,int width,int height);


};

Platforms::Platforms(){};

sf::Texture Platforms::good_one(int x,int y){
	sf::Texture maciek;
	maciek.create(x,y);
	return maciek;
	};


void Platforms::make(Floor_Maker f,int width,int height){


	
for(int i =0;i<20;i++){
	if(f.floor[i]==1){
			std::cout<<"Start"<<std::endl;
		ziutek[i].setTexture(good_one(width,height));
		ziutek[i].setColor(sf::Color(0,255,255));	
		ziutek[i].setPosition(i*width,SCRHEIGHT-height);
		platforms.push_back(ziutek[i]);
		std::cout<<"End"<<std::endl;
		}
	
	
	}
std::cout<<"End of all"<<std::endl;


};

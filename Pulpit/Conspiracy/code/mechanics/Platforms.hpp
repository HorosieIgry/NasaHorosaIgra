class Platforms{
public:
std::vector<sf::Sprite>platforms;
Platforms(int width,int height);
Platforms();
void make(Floor_Maker f,int width,int height);
private:
	sf::Sprite ziutek[20];
	sf::Texture tex;

};

Platforms::Platforms(){};

Platforms::Platforms(int width,int height){

		tex.create(width,height);

	/*for(int k=0;k<20;k++){
	ziutek[k].setTexture(tex);
	ziutek[k].setColor(sf::Color(0,255,255));	
}*/
	
	
	};

void Platforms::make(Floor_Maker f,int width,int height){


	
for(int i =0;i<20;i++){
	std::cout<<i<<std::endl;
	if(f.floor[i]==1){
			std::cout<<"Start"<<std::endl;
		ziutek[i].setTexture(tex);
		ziutek[i].setColor(sf::Color(0,255,255));	
		ziutek[i].setPosition(i*width,SCRHEIGHT-height);
		platforms.push_back(ziutek[i]);
		std::cout<<"End"<<std::endl;
		}
	
	
	}
std::cout<<"End of all"<<std::endl;


};

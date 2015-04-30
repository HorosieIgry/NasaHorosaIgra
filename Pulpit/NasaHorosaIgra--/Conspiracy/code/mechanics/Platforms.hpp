class Platforms{
// Arek paczaj robie komentarze
//przerabiam klase Platforms tak zeby nie trzeba było
// klasy Floor_Maker	
private:
	sf::Texture good_one(int x,int y);
	// generuje sprita do vectora platforms
	sf::Sprite zulek(int width,int height);
	//pointer - pokazuje gdzie będzie następna platforma
	int pointer;

public:
sf::Texture teksi;
sf::Sprite mati;
std::vector<sf::Sprite>platforms; //przechowuje sprajty platform
std::vector<int>platform_map;   //mapa dziur i platform
// Konstruktor
Platforms(int width,int height);
Platforms();
// void update - updatuje mape i platfromy
void update(int width,int height);
//wyswietlamape
void print();

int getPointer();
};

Platforms::Platforms(){};

Platforms::Platforms(int width,int height){
	// bo pierwsza platforma zaczyna się w 0
	pointer=0;
	
	//generuje pierwsze 20 platform(w mapie)
	for(int i=0;i<5;i++)platform_map.push_back(1);
	
	for(int j=5;j<20;j++){

			if(platform_map[j-1]==0){
			platform_map.push_back(1);
			continue; 
			} 

		platform_map.push_back(rand()%2);
		
			std::cout<<"Map Constructed"<<std::endl;
		}
	

	
	for(unsigned int i =0;i<platform_map.size();i++){
	if(platform_map[i]==1){
			std::cout<<"Start"<<std::endl;
		
		platforms.push_back(zulek(width,height));
		std::cout<<"End"<<std::endl;
		}
		//przesuwam wsk rysowania następnej platformy
	pointer+=width;
	
	}
	std::cout<<"End of all"<<std::endl;
		std::cout<<"Sprites Constructed"<<std::endl;
	};
// generacja tekstur - nie dotykać - duza szansa zjebania gry
sf::Texture Platforms::good_one(int x,int y){
	sf::Texture maciek;
	maciek.create(x,y);
	return maciek;
	};
	
// dane na temat klasy w terminalu
void Platforms::print(){
	std::cout<<"Floor outlay:"<<std::endl;
	for(unsigned int i=0;i<platform_map.size();i++){
		if(platform_map[i])std::cout<<"1";
		else std::cout<<"0";
		}
	std::cout<<std::endl;		
	std::cout<<"X pointer:"<<pointer<<std::endl;
	std::cout<<"Nr of platforms:"<<platforms.size()<<std::endl;
	std::cout<<std::endl;
	
	};
	
// generacja sprajtow - nie dotykać - duza szansa zjebania gry
sf::Sprite Platforms::zulek(int width,int height)
{
	
	sf::Sprite zul;
	zul.setTexture(good_one(width,height));
	zul.setColor(sf::Color(0,255,255));	
	zul.setPosition(pointer,SCRHEIGHT-height);
	return zul;
	};
	
// wstawianie nowych platform
void Platforms::update(int width,int height){
	
	int ayn_rand = rand()%2;
	
	//platform_map.erase(platform_map.begin());
	
	if(platform_map[platform_map.size()-1]==0){
			platform_map.push_back(1);
			ayn_rand=1;
			} 
	else{
		platform_map.push_back(ayn_rand);
		}	
		
			std::cout<<"Map Updated"<<std::endl;
	if(ayn_rand==1){
	//platforms.erase(platforms.begin());
	platforms.push_back(zulek(width,height));
}
	pointer+=width;
	};
	
	int Platforms::getPointer(){return pointer;};
	

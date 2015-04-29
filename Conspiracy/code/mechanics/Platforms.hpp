class Platforms{
	
private:
	sf::Texture good_one(int x,int y);
	sf::Sprite ziutek[40];
	
public:

Platforms(int width,int height);
Platforms();
void makeFloor(int width,int height, int position);	// position ustawia wysokosc na ktorej znajduja sie platformy
int getSize();	// zwraca dlugosc wektora, myslalem nad tym by zrobic wektory prywatne, ale doszedlem do wniosku, ze po co, a jesli kiedys zajdzie taka potrzeba to juz mamy 1 funkcje
std::vector<sf::Sprite>platforms;
std::vector <int> floor;


};

Platforms::Platforms(){};

sf::Texture Platforms::good_one(int x,int y){
	sf::Texture maciek;
	maciek.create(x,y);
	return maciek;
	};


void Platforms::makeFloor(int width,int height, int position){

	for (int i = 0; i < 5; i++)
	{
		floor.push_back(1);

		ziutek[i].setTexture(good_one(width, height));
		ziutek[i].setColor(sf::Color(0, 255, 255));
		ziutek[i].setPosition(i*width, SCRHEIGHT - position);
		platforms.push_back(ziutek[i]);

	}
	for (int j = 5; j<40; j++){
		if (floor[j - 1] == 0 && floor[j - 2] == 0 || rand()%2){

			ziutek[j].setTexture(good_one(width, height));
			ziutek[j].setColor(sf::Color(0, 255, 255));
			ziutek[j].setPosition(j*width, SCRHEIGHT - position);
			platforms.push_back(ziutek[j]);

			floor.push_back(1);
			continue;
		}
		ziutek[j].setTexture(good_one(width, height));
		ziutek[j].setColor(sf::Color(0, 0, 0));
		ziutek[j].setPosition(j*width, SCRHEIGHT - position);
		platforms.push_back(ziutek[j]);
		floor.push_back(0);
	}
};

int Platforms::getSize()
{
	return floor.size()-1;
}

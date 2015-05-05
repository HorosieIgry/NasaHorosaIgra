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



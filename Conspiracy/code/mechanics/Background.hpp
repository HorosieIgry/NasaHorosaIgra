//klasa robiaca tlo z przesuwajacym sie sloncem
class Dynamic_bg {
	
	private:
	//stan przesuniecia slonca
	float x;
	//stwierdza czy noc czy dzien
	bool day ;
	//zegar paczacy czy przesunac ksiezyc/slonce
	sf::Clock frame_clock;
	//rozmiar tla
	sf::Vector2f size;
	sf::Vector2f position(sf::Vector2f pos);
	sf::Texture smunn();
	
	public:
	Dynamic_bg();
	Dynamic_bg(int scr_x,int scr_y);
	//sprawdza zegar i przestawia slonce
	void update(sf::Vector2f pos);
	sf::Sprite smoon;
	//sf::Texture smun;
	
};

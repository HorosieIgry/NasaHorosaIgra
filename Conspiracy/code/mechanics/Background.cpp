#include "Background.hpp"

Dynamic_bg::Dynamic_bg(){};

Dynamic_bg::Dynamic_bg(int scrx,int scry){
	
	size = sf::Vector2f(scrx,scry);
	x = 0;
	day =true;
	smoon = sf::Sprite(smunn());
	smoon.setColor(sf::Color(0, 255, 255));
	
	
	};

sf::Vector2f Dynamic_bg::position(sf::Vector2f pos){
	sf::Vector2f vec(93/2,64/2);
	sf::Vector2f c(/*x+*/vec.x+ pos.x -(size.x * cos(3.14159265*x/20))/2,size.y -4*( -x*x +20*x));
	std::cout<<c.x-pos.x<<std::endl;
	
	return c;
	};
	
	void Dynamic_bg::update(sf::Vector2f pos){
		bool i = false;
		if(frame_clock.getElapsedTime().asMilliseconds()>25){
			x+=0.1;
			i= true;
			}
		//	std::cout<<x<<std::endl;
		if(x>20){
			
			x=0;
			day=!day;
			}
		//smoon = sf::Sprite(smunn());
		if(day)smoon.setColor(sf::Color(255, 255, 0));
		else smoon.setColor(sf::Color(255, 255, 255));
		smoon.setPosition(position(pos));
		if(i)frame_clock.restart();
		};

sf::Texture Dynamic_bg::smunn(){
	sf::Texture mun;
	mun.create(50,50);
	return mun;
	
	};



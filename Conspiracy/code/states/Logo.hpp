#ifndef LOGO_HPP
#define LOHO_HPP

#include <SFML/Graphics.hpp>

#include "../../state_manager.hpp"
#include "../../Screen.hpp"
#include "../../functions.hpp"

class Logo : public Game_state{
	
	
private:	
 bool msg_trigger;
 bool pressed;

 
 
 sf::Time fade_time;
 sf::Clock clock;
	  
 sf::RectangleShape cushion;	  
 sf::Sprite logo;
 sf::Texture texture;

public:
	
	virtual void Init();
	virtual void Input();
	virtual void Update();
	virtual void Draw();
			
};
	
#endif

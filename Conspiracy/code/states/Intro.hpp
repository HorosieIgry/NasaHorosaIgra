#ifndef INTRO_HPP
#define INTRO_HPP

#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

#include "../../state_manager.hpp"
#include "../../functions.hpp"

class Intro : public Game_state {
	
	private:
	

 int nr;
	
	std::string intro_table[5];	
	sf::Text text;
	   
protected:

	bool msg_trigger;
	bool pressed;
	
	sf::Time fade_time;
	sf::Clock clock;
	sf::Font letter_font;
 
	sf::RectangleShape cushion;

public:

	virtual void Init();
	virtual void Clear();
	virtual void Input();
	virtual void Update();	
	virtual void Draw();
	
	
	
	
	
};

#endif

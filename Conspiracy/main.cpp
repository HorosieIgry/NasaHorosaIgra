#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

#include "Screen.hpp"
#include "functions.hpp"
#include "state_manager.hpp" 

#include "code/states/Intro.hpp"
#include "code/states/Logo.hpp"
#include "code/states/Game.hpp"
#include "code/states/Game_Over.hpp"

int game_state = 1;

int main()
{

    sf::RenderWindow window(sf::VideoMode(SCRWIDTH, SCRHEIGHT), "GRA");

//ziarno liczb losowych
srand (time(NULL));

Intro intro;
Logo logo;
Game_screen game;
window.setFramerateLimit(60);
intro.initialize("Intro",&window);
logo.initialize("Logo",&window);
game.initialize("Game Screen",&window);

    while (window.isOpen())
    {
	
        if(game_state==1){
			
		intro.Run();
		
	}
	
	if(game_state==2){
		
			logo.Run();

		}
       
           	if(game_state==3){

			game.Run();
		
		}
		
			if(game_state==4){
			std::cout<<"GAME OVER"<<std::endl;
			return 0;
		
		}
           
    }
    
    return 0;
}

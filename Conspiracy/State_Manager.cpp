#include "state_manager.hpp"

void Game_state::Run(){

		Init();
		Clear();
		Input();
		Update();
		Draw();
};

void Game_state::initialize(std::string nom, sf::RenderWindow* rw){

	name = nom;
	render_window = rw;
	initialized = false;
};

std::string Game_state::getName(){

	return name;
};

void Game_state::rename(std::string new_name){

	name = new_name;
};
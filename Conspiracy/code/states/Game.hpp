#ifndef GAME_HPP
#define GAME_HPP

#include "../mechanics/Background.hpp"
#include "../mechanics/Platforms.hpp"
#include "../mechanics/Player.hpp"

#include "../engine/World_Constants.hpp"
#include "../engine/Primitive_Graphic_Buffer.hpp"
#include "../engine/My_View.hpp"

#include "../../Screen.hpp"
#include "../../state_manager.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

class Game_screen : public Game_state{

private:

	Player player;
	sf::Texture texture;	// o tu wstawi³em teksture, bo po wstawieniu ja w init usuwa sie ja za wczesnie i sprite nie ma jak jej wczytac
	sf::Text debug_text;

	sf::Clock internal_FPS;

	sf::Font font;


	int plat_upd;
	int mov;
	int jmp;
	int jmp_border;

	PrimitiveGraphicBuffer pgb;
	World_Constants world;
	Platforms platformy;
	Dynamic_bg background;

public:

	virtual void Init();
	virtual void Input();
	virtual void Update();
	virtual void Draw();

};

#endif
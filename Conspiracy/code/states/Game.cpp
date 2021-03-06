#include "Game.hpp"

void Game_screen::Init(){
		if (!initialized){

			background = Dynamic_bg(SCRWIDTH, SCRHEIGHT);
			platformy = Platforms(world.platform_width, world.floor_height);
			//	std::cout<<"PLatforms initialized"<<std::endl;
			internal_FPS.restart();
			plat_upd = 0;
			mov = 1;
			jmp = 0;
			jmp_border = SCRHEIGHT - world.floor_height - world.player_size.y;
			pgb.setRenderWindow(render_window);


			//	intrect dziala tak fajnie, ze podajesz x, y pozycje startowe, a pozniej x, y o ile trza wyciac obrazek
			if (!texture.loadFromFile("resources/textures/catspritesx4.gif"))
			{
			}
			player.setTexture(texture);
			player.setTextureRect(sf::IntRect(0, 136, 93, 64));

			player.setPosition(0, SCRHEIGHT - world.floor_height - world.player_size.y);


			pgb.std_view.standard_view(player, world.floor_height);


			if (!font.loadFromFile("resources/fonts/4mini.ttf"))
			{
			}


			debug_text.setPosition(-300, 0);
			debug_text.setCharacterSize(24);
			debug_text.setColor(sf::Color::Red);
			debug_text.setFont(font);

			initialized = true;
		}
	};

void Game_screen::Input(){

		sf::Event event;

		while (render_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				render_window->close();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))mov = 1;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))mov = -1;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){

				if (player.getPosition().y == jmp_border)jmp = world.jmp_velocity;

			}

			if (event.type == sf::Event::KeyReleased){

				//temporarily

				//if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&mov==1)mov=0;

				// if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&mov==-1)mov=0;

			}
		}
	};

void Game_screen::Update(){

		//slonce ksiezyc i background
		background.update(player.getPosition());


		//ogarnia przesuwanie elementow w plaszczyznie x
		sf::Vector2f movement(0, 0);

		switch (mov){
		case 1:

			movement.x = 6;
			player.move(movement);
			pgb.std_view.move(movement);
			debug_text.move(movement);

			if (jmp <= 0 && player.getPosition().y >= jmp_border&&!player.afloat(platformy, world.platform_width, world.player_size.x)){
				player.animate(sf::Vector2f(91.33f, 66.66f), 2, 5, 4, 1);
			}

			break;
		case -1:

			movement.x = -6;
			player.move(movement);
			pgb.std_view.move(movement);
			debug_text.move(movement);

			if (jmp <= 0 && player.getPosition().y >= jmp_border&&!player.afloat(platformy, world.platform_width, world.player_size.x)){
				player.animate(sf::Vector2f(91.33f, 66.66f), 2, 5, 5, 0);
			}

			break;
		default:
			break;

		}
		// updatowanie planszy (endless mode)
		if (player.getPosition().x - plat_upd >= world.platform_width){

			plat_upd = player.getPosition().x;
			platformy.update(world.platform_width, world.floor_height);

		}

		//skakanie

		if (jmp != 0 || player.getPosition().y != jmp_border || player.afloat(platformy, world.platform_width, world.player_size.x)){
			player.move(0.f, -jmp);
			jmp -= world.gravitational_force;

			if (mov == 1) player.setTextureRect(sf::IntRect(182, 136, -91, 64));
			else player.setTextureRect(sf::IntRect(91, 136, 91, 64));

		}
		if (jmp <= 0 && player.getPosition().y >= jmp_border&&!player.afloat(platformy, world.platform_width, world.player_size.x)){
			player.setPosition(player.getPosition().x, jmp_border);
			jmp = 0;
		}
		if (player.afloat(platformy, world.platform_width, world.player_size.x) && player.getPosition().y>SCRHEIGHT - world.floor_height)mov = 0;


		if (player.getPosition().y>SCRHEIGHT)game_state++;

		char buff[100];
		sprintf(buff, "PLAYER_POS_X: %.0f\nPLAYER_POS_Y:%.0f\nFLOOR_BORDER:%d\nAFLOAT%d\nFPS:%.0f", player.getPosition().x, player.getPosition().y, jmp_border, player.afloat(platformy, world.platform_width, world.player_size.x), 1.f / internal_FPS.restart().asSeconds());
		debug_text.setString(buff);

	};

	void Game_screen::Draw(){
		//wrzuca tlo do rysowania
		pgb.addSprite(background.smoon);
		//	std::cout<<"Przed wyswietlaniem"<<std::endl;
		//platformy.print();
		for (unsigned int i = 0; i<platformy.platforms.size(); i++){
			//		std::cout<<"1sze wysw"<<std::endl;
			pgb.addSprite(platformy.platforms[i]);
			//			std::cout<<"Po"<<std::endl;
		}

		pgb.addSprite(player);

		pgb.addText(debug_text);
		//	std::cout<<"Przed pushem"<<std::endl;
		pgb.push();
		//	std::cout<<"Po pushu"<<std::endl;
	};

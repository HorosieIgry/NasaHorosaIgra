class Game_screen : public Game_state{
		private:
		 Player player;
		 sf::Texture texture;	// o tu wstawi³em teksture, bo po wstawieniu ja w init usuwa sie ja za wczesnie i sprite nie ma jak jej wczytac
		 sf::Text debug_text;
		 
		 sf::Clock internal_FPS;
		 
		 sf::Font font;
		 
		 Floor_Maker fmaker;

		 int mov;
		 int jmp;
		 int jmp_border;
		 int x = 0;		// do zmieniania animacji poruszania siê
		 
		 PrimitiveGraphicBuffer pgb;
		 World_Constants world;
		 Platforms platformy;
		  
		public: 
		 void Init(){
			if(!initialized){
				internal_FPS.restart();
				fmaker.print(); 
				platformy.make(fmaker,world.platform_width,world.floor_height);
				mov=1;
				jmp=0;
				jmp_border = SCRHEIGHT - world.floor_height - world.player_size.y;
				pgb.setRenderWindow(render_window);
				

			 //	intrect dziala tak fajnie, ze podajesz x, y pozycje startowe, a pozniej x, y o ile trza wyciac obrazek
			 if (!texture.loadFromFile("resources/textures/catspritesx4.gif"))
			 {
				}
			 player.setTexture(texture);
			 player.setTextureRect(sf::IntRect(0, 136, 93, 64));
			 
			 player.setPosition(0,SCRHEIGHT- world.floor_height-world.player_size.y);
			 

			pgb.std_view.standard_view(player,world.floor_height);
			
			
			if (!font.loadFromFile("resources/fonts/4mini.ttf"))
			{
					}
			

			debug_text.setPosition(-300,0);
			debug_text.setCharacterSize(24);
			debug_text.setColor(sf::Color::Red);
			debug_text.setFont(font);
			
			 initialized=true;
		 }
		 };
		 
		 void Input(){
			 
			  sf::Event event ;
		
		        while (render_window->pollEvent(event))
        {
		 if (event.type == sf::Event::Closed)
                render_window->close();
                
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))mov=1;
			 
			 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))mov=-1;
			 
			 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
				 
				 if(player.getPosition().y ==jmp_border)jmp=world.jmp_velocity;
				 
				 
				 }
			 
         if (event.type== sf::Event::KeyReleased){
			 
			 //temporarily
			 
			//if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&mov==1)mov=0;
			 
			// if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&mov==-1)mov=0;
			  
			 }
			    
		}
			 
			 };
		
		void Update(){
			//ogarnia przesuwanie elementow w plaszczyznie x
			x++;
			switch(mov){
			case 1:

			player.move(6.f,0.f);
			pgb.std_view.move(6.f,0.f);
			debug_text.move(6.f,0.f);

			if (jmp <= 0 && player.getPosition().y >= jmp_border&&!player.afloat(fmaker, world.platform_width, world.player_size.x)){
				/*if (x < 10) player.setTextureRect(sf::IntRect(0, 64, 32, 32));
				else if (x < 20) player.setTextureRect(sf::IntRect(64, 64, 32, 32));
				else x = 0; */
				if (x < 5) player.setTextureRect(sf::IntRect(91, 136, -91, 64));
				else if (x < 10) player.setTextureRect(sf::IntRect(182, 136, -91, 64));
				else if (x < 15) player.setTextureRect(sf::IntRect(273, 136, -91, 64));
				else if (x < 20) player.setTextureRect(sf::IntRect(364, 136, -91, 64));
				else if (x < 25) player.setTextureRect(sf::IntRect(455, 136, -91, 64));
				else if (x < 30) player.setTextureRect(sf::IntRect(543, 136, -91, 64));
				else x = 0;
			}
	
			break;
			case -1:

			player.move(-6.f,0.f);
			pgb.std_view.move(-6.f,0.f);
			debug_text.move(-6.f,0.f);

			if (jmp <= 0 && player.getPosition().y >= jmp_border&&!player.afloat(fmaker, world.platform_width, world.player_size.x)){
				/*if (x < 10) player.setTextureRect(sf::IntRect(0, 32, 32, 32));
				else if (x < 20) player.setTextureRect(sf::IntRect(64, 32, 32, 32));
				else x = 0;*/
				if (x < 5) player.setTextureRect(sf::IntRect(0, 136, 91, 64));
				else if (x < 10) player.setTextureRect(sf::IntRect(91, 136, 91, 64));
				else if (x < 15) player.setTextureRect(sf::IntRect(182, 136, 91, 64));
				else if (x < 20) player.setTextureRect(sf::IntRect(273, 136, 91, 64));
				else if (x < 25) player.setTextureRect(sf::IntRect(364, 136, 91, 64));
				else if (x < 30) player.setTextureRect(sf::IntRect(455, 136, 91, 64));
				else x = 0;
			}

			break;
			default:
			break;
			
			}
			
			//skakanie
			
			if(jmp!=0||player.getPosition().y!=jmp_border||player.afloat(fmaker,world.platform_width,world.player_size.x)){
				player.move(0.f,-jmp);
				jmp-= world.gravitational_force;

				if (mov == 1) player.setTextureRect(sf::IntRect(182, 136, -91, 64));
				else player.setTextureRect(sf::IntRect(91, 136, 91, 64));
				
				}
			if(jmp<=0&&player.getPosition().y>=jmp_border&&!player.afloat(fmaker,world.platform_width,world.player_size.x)){
				player.setPosition(player.getPosition().x,jmp_border);
				jmp=0;
				}
			if(player.afloat(fmaker,world.platform_width,world.player_size.x)&&player.getPosition().y>SCRHEIGHT-world.floor_height)mov=0;
			
			
			if(player.getPosition().y>SCRHEIGHT||player.getPosition().x>3600)game_state++;
			
			char buff[100]; 
			sprintf(buff, "PLAYER_POS_X: %.0f\nPLAYER_POS_Y:%.0f\nFLOOR_BORDER:%d\nAFLOAT%d\nFPS:%.0f", player.getPosition().x,player.getPosition().y,jmp_border,player.afloat(fmaker,world.platform_width,world.player_size.x),1.f/internal_FPS.restart().asSeconds());
			debug_text.setString(buff);
			
			
			};
		
		void Draw(){
		for(unsigned int i=0;i<platformy.platforms.size();i++){
			pgb.addSprite(platformy.platforms[i]);
			}

		pgb.addSprite(player);

		pgb.addText(debug_text);

		pgb.push();
			};
				
		};

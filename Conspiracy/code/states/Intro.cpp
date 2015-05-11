#include "Intro.hpp"

void Intro::Init(){

		if (!initialized){
			msg_trigger = true;
			pressed = false;
			nr = 0;

			intro_table[0] = "Graphics of cat made";
			intro_table[1] = "by Shepardskin";
			intro_table[2] = "8====> - Karol Jankowski :-D";

			load_font(&letter_font, "resources/fonts/4mini.ttf");
			cushion = sf::RectangleShape(sf::Vector2f(SCRWIDTH, SCRHEIGHT));
			text = sf::Text("", letter_font, 40);
			cushion.setFillColor(sf::Color(0.f, 0.f, 0.f, 255.f));
			next_text(&text, intro_table, nr);
			nr++;
			fadein_message(&text);


			initialized = true;
			//std::cout<<"Initialized: "<<initialized<<std::endl;
		}
	};


void Intro::Clear(){
		//if(intro_music.getStatus()!= sf::Music::Playing)intro_music.play();
	};


void Intro::Input(){

		sf::Event event;

		while (render_window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				render_window->close();


			if (event.type == sf::Event::KeyPressed)if (event.key.code == sf::Keyboard::Escape)game_state = 3;


			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (!pressed&&msg_trigger == true){
					//experimental, but seems to work
					if (event.mouseButton.button == sf::Mouse::Left&&cushion.getFillColor().a == 0.f){
						msg_trigger = !msg_trigger;

						pressed = true;

					}
				}
			}

			if (event.type == sf::Event::MouseButtonReleased)
			{
				if (pressed){
					if (event.mouseButton.button == sf::Mouse::Left)pressed = false;
				}
			}
		}
	};


void Intro::Update(){
		fade_time = clock.getElapsedTime();

		if (fade_time.asMicroseconds()>2){
			if (msg_trigger == true)brighten_fade(&cushion);
			else{
				darken_fade(&cushion);
			}
			clock.restart();
		}

		if (cushion.getFillColor().a == 255.f&&!msg_trigger){

			msg_trigger = true;
			if (next_text(&text, intro_table, nr) == 0){
				fadein_message(&text);
				nr++;
			}
			else game_state = 2;
		}
	};


void Intro::Draw(){

		render_window->clear();
		render_window->draw(text);
		render_window->draw(cushion);
		render_window->display();

	};

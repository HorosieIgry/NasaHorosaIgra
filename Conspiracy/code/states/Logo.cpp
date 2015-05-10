#include "Logo.hpp"

void Logo::Init(){
		if (!initialized){

			msg_trigger = true;
			pressed = false;


			cushion = sf::RectangleShape(sf::Vector2f(SCRWIDTH, SCRHEIGHT));
			cushion.setFillColor(sf::Color(0.f, 0.f, 0.f, 255.f));


			if (!texture.loadFromFile("resources/images/logo.png"))
			{
				// error...
			}

			logo.setTexture(texture);
			logo.setScale(sf::Vector2f((2.f*SCRWIDTH) / 640.f, (2.f*SCRHEIGHT) / 480));


			initialized = true;
		}
	};

void Logo::Input(){

		sf::Event event;

		while (render_window->pollEvent(event))
		{

			if (event.type == sf::Event::Closed)render_window->close();

			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (!pressed&&msg_trigger == true){
					if (event.mouseButton.button == sf::Mouse::Left){
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

void Logo::Update(){
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

			game_state = 3;
		}
	};


	void Logo::Draw(){

		render_window->clear();
		render_window->draw(logo);
		render_window->draw(cushion);
		render_window->display();

	};

void Intror(sf::RenderWindow* window){
	
	
		static bool msg_trigger=true;
		static bool pressed = false;
		static int nr=0;
	
	
	
	std::string intro_table[7];

intro_table[0]="Welcome Sir.";
intro_table[1]="I hope that, you are not fatigued\n from your journey.";
intro_table[2]="I would like you to assume\n your office immediatly.";
intro_table[3]="We have reasons to believe\n that some people are plotting a coup.";
intro_table[4]="You will be overseeing the circulation\n of mail among the most\n influential people in the country.";
intro_table[5]="Intercept any letter,\n you find suspicious.\n You have been given authority\n to confiscate up to 400 letters a day.\n We cannot let them succeed.";
intro_table[6]="With regards\n\n\n\n\n Your Humble Supervisor";
	
	
	sf::Time fade_time;
  static sf::Clock clock;
 static sf::Font letter_font;

   

    static  sf::RectangleShape cushion(sf::Vector2f(SCRWIDTH, SCRHEIGHT));
   static sf::Text text("", letter_font, 40);

    if(nr==0){
       load_font(&letter_font,"resources/fonts/Dynalight-Regular.otf");
   cushion.setFillColor(sf::Color(0.f,0.f,0.f,255.f));
	next_text(&text,intro_table,nr);
	nr++;
    fadein_message(&text);
}
	
	
	
			if(intro_music.getStatus()!= sf::Music::Playing)intro_music.play();
		fade_time=clock.getElapsedTime();
		static sf::Event event ;
		
		        while (window->pollEvent(event))
        {
		 if (event.type == sf::Event::Closed)
                window->close();
		
		
		if (event.type == sf::Event::KeyPressed)if(event.key.code == sf::Keyboard::Escape)game_state=3;
		
		
		if (event.type == sf::Event::MouseButtonPressed)
{
	if(!pressed&&msg_trigger == true){
		//experimental, but seems to work
    if (event.mouseButton.button == sf::Mouse::Left&&cushion.getFillColor().a==0.f){
    msg_trigger=!msg_trigger;

pressed = true;

}
}
		}
		
		
		
				if (event.type == sf::Event::MouseButtonReleased)
{
	if(pressed){
    if (event.mouseButton.button == sf::Mouse::Left)pressed = false;
}

		}
		
	}
		
		if(fade_time.asMicroseconds()>2){
			if(msg_trigger==true)brighten_fade(&cushion);
			else{
				darken_fade(&cushion);
				}
			clock.restart();
			}
			
			if(cushion.getFillColor().a==255.f&&!msg_trigger){
				
				msg_trigger=true;
				if(next_text(&text,intro_table,nr)==0){
					fadein_message(&text);
					nr++;
					}
				else game_state=2;
				}

        window->clear();
		window->draw(text);
		window->draw(cushion);
        window->display();
      
        
	
	
	
	
	
	};
	
	
  void	Logor(sf::RenderWindow* window){
	  
	  
	  
		static bool msg_trigger=true;
		static bool pressed = false;
		static bool first_run=true;
	  	sf::Time fade_time;
  static sf::Clock clock;
	  
	      static  sf::RectangleShape cushion(sf::Vector2f(SCRWIDTH, SCRHEIGHT));
	  
	    static sf::Sprite logo;
  static sf::Texture texture;


	  
	  if(first_run){
	
		 cushion.setFillColor(sf::Color(0.f,0.f,0.f,255.f));
	
		  
		  if (!texture.loadFromFile("resources/images/new_logo_big.png"))
{
    // error...
}

logo.setTexture(texture);
logo.setScale(sf::Vector2f((2.f*SCRWIDTH)/640.f, (2.f*SCRHEIGHT)/480));
   
		  first_run=false;
		  
		  
		  }
	  
	  
	  			fade_time=clock.getElapsedTime();
	  			
	  		static sf::Event event ;
		
		        while (window->pollEvent(event))
        {	
	  			
	  			 if (event.type == sf::Event::Closed)window->close();
		
		if (event.type == sf::Event::MouseButtonPressed)
{
	if(!pressed&&msg_trigger == true){
    if (event.mouseButton.button == sf::Mouse::Left){
    msg_trigger=!msg_trigger;

pressed = true;
}
}
		}
		
				if (event.type == sf::Event::MouseButtonReleased)
{
	if(pressed){
    if (event.mouseButton.button == sf::Mouse::Left)pressed = false;
}

		}
		
	}
		
				if(fade_time.asMicroseconds()>2){
			if(msg_trigger==true)brighten_fade(&cushion);
			else{
				darken_fade(&cushion);
				}
			clock.restart();
			}
		
		if(cushion.getFillColor().a==255.f&&!msg_trigger){
				
				msg_trigger=true;

				game_state=3;
				}
				
				
			
        window->clear();
		window->draw(logo);
		window->draw(cushion);
        window->display();
	  
	  
	  
  
	  
	  };
	
	
	
	
	void Game(sf::RenderWindow* window)
	
	{
		static bool first=true;
		
		static sf::Sprite player;
		static int mov=0;
		
		
		
		if(first){
			sf::Texture texture;
			texture.create(50,50);
			player.setTexture(texture);
			player.setColor(sf::Color(255.f,0.f,0.f));
			
			first = false;
			
			
			}
			
			
			
		static sf::Event event ;
		
		        while (window->pollEvent(event))
        {
		 if (event.type == sf::Event::Closed)
                window->close();
                

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&mov==0)mov=1;
			 
			 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&mov==0)mov=-1;
			 
			 
			 
			 

         if (event.type== sf::Event::KeyReleased){
			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&mov==1)mov=0;
			 
			 if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&mov==-1)mov=0;
			 
			 
			 }
			 
			 
			 
                
		}
		switch(mov){
			case 1:
			player.move(0.f,-1.f);
			break;
			case -1:
			player.move(0.f,1.f);
			break;
			default:
			break;
			
			}
		
		
		 window->clear();
		window->draw(player);
        window->display();
		
		
		
		};
	
	
	
	
	

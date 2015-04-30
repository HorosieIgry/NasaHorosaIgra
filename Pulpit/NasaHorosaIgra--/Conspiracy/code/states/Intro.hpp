
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
 virtual void Init(){
	 
	 if(!initialized){
  msg_trigger=true;
  pressed = false;
  nr=0;
  
intro_table[0]="Graphics of cat made";
intro_table[1]="by Shepardskin";
intro_table[2]="8====> - Karol Jankowski :-D";

   load_font(&letter_font,"resources/fonts/4mini.ttf");
   cushion =  sf::RectangleShape(sf::Vector2f(SCRWIDTH, SCRHEIGHT));
   text =  sf::Text("", letter_font, 40);
   cushion.setFillColor(sf::Color(0.f,0.f,0.f,255.f));
	next_text(&text,intro_table,nr);
	nr++;
    fadein_message(&text);


initialized=true;
//std::cout<<"Initialized: "<<initialized<<std::endl;
}
};

 virtual void Clear(){
		//if(intro_music.getStatus()!= sf::Music::Playing)intro_music.play();
	
	
	};

 virtual void Input(){
	
			sf::Event event ;
		
		        while (render_window->pollEvent(event))
        {
		 if (event.type == sf::Event::Closed)
                render_window->close();
		
		
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
	
	
	
	};
	
 virtual void Update(){
		fade_time=clock.getElapsedTime();
		
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
		
		
		
		};
		
		
 virtual void Draw(){
			
        render_window->clear();
		render_window->draw(text);
		render_window->draw(cushion);
        render_window->display();		
			
			};
	
	
	
	

	
	
};

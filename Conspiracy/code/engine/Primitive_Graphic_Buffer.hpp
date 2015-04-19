class PrimitiveGraphicBuffer{
	
	private:
	sf::RenderWindow* window;
	int sprite_size;
	int text_size;
	std::vector<sf::Sprite>   sprites;
	std::vector<sf::Text>   texts;
	void clear();
	
	public:
	My_View std_view;
	
	PrimitiveGraphicBuffer();

	
	void addSprite(sf::Sprite);
	void addText(sf::Text);
	
	void push();
	void setRenderWindow(sf::RenderWindow * w);
	
	
	};
	
	PrimitiveGraphicBuffer::PrimitiveGraphicBuffer(){
		sprite_size=0;
		text_size=0;

		
		};
		
		void PrimitiveGraphicBuffer::setRenderWindow(sf::RenderWindow * w){
			window=w;
			
			};
		
		
		void PrimitiveGraphicBuffer::clear(){
		sprite_size=0;
		text_size=0;

		 sprites.clear();
		 texts.clear();
		
		
		};
		
		void PrimitiveGraphicBuffer::addSprite(sf::Sprite sprite){
			sprites.push_back(sprite);
			sprite_size++;
			
			};
			
		void PrimitiveGraphicBuffer::addText(sf::Text text){
			texts.push_back(text);
			text_size++;
			
			};
			
			void PrimitiveGraphicBuffer::push(){
				
				window->clear();
				window->setView(std_view);
				for(int i=0;i<sprite_size;i++){
					window->draw(sprites[i]);
					
					}
					
				for(int i=0;i<text_size;i++){

					window->draw(texts[i]);

					}
				
				window->display();
				
				clear();
				
				};
			
		

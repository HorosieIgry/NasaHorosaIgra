#include "Primitive_Graphic_Buffer.hpp"

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
			
		

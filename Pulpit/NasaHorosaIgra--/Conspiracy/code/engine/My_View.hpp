

class My_View : public sf::View{

public:

void center_on(sf::Sprite sprite){


//chwilowo zakomentarzowane żeby błędu nie było
/*sf::Vector2u size = sprite.getTexture()->getSize();

float x = size.x/2;
float y = size.y/2;
*/
sf::Vector2f vec(93/2,64/2);

	setCenter(sprite.getPosition() + vec);
	setSize(sf::Vector2f(SCRWIDTH, SCRHEIGHT));

};

void standard_view(sf::Sprite sprite,int flr_height){

center_on(sprite);
setCenter(getCenter().x,SCRHEIGHT/2);

};



};

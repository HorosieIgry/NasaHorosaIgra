class World_Constants{

public:

//platforms
int floor_height;
int platform_width;
int platform_height; 

//player
sf::Vector2f player_size;


//jumping
int gravitational_force;
int jmp_velocity;

World_Constants();



};

World_Constants::World_Constants(){
	
floor_height = 0.25*SCRHEIGHT;

player_size = sf::Vector2f(93,64);

platform_width = 120;
platform_height = 30;

jmp_velocity = 30;
gravitational_force = 2;

};

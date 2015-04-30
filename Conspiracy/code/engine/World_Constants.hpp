class World_Constants{

public:

//platforms
int floor_height;
int platform_width;

//player
sf::Vector2f player_size;


//jumping
int gravitational_force;
int jmp_velocity;

World_Constants();



};

World_Constants::World_Constants(){
	
floor_height = 0.25*SCRHEIGHT;

player_size = sf::Vector2f(50,50);

platform_width = 3*player_size.x;

jmp_velocity = 30;
gravitational_force = 2;

};

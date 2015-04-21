class Game_state{
	
	protected:
	
	sf::RenderWindow * render_window;
	std::string name;
	bool initialized;
	
	public:
	
	void initialize(std::string nom,sf::RenderWindow* rw);
		
	virtual void Init(){};
	virtual void Clear(){};
	virtual void Input(){};
	virtual void Update(){};
	virtual void Draw(){};
	
	virtual void Run(){
		
		Init();
		Clear();
		Input();
		Update();
		Draw();
		};
	
	
	//class name handlers
	std::string getName();
	void rename(std::string new_name);
	
	
	};
	
	void Game_state::initialize(std::string nom,sf::RenderWindow* rw){
		
		name =nom;
		render_window = rw;
		initialized=false;
		
		
		};

std::string Game_state::getName(){
	
	return name;
		
		
		};

void Game_state::rename(std::string new_name){
		
		name=new_name;
		
		};	

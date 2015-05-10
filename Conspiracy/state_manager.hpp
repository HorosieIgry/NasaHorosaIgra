#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

#include <string>
#include <SFML/Graphics/RenderWindow.hpp>

class Game_state{

protected:

	sf::RenderWindow * render_window;
	std::string name;
	bool initialized;

public:

	void initialize(std::string nom, sf::RenderWindow* rw);

	virtual void Init(){};
	virtual void Clear(){};
	virtual void Input(){};
	virtual void Update(){};
	virtual void Draw(){};

	virtual void Run();

	std::string getName();
	void	rename(std::string new_name);

};

#endif
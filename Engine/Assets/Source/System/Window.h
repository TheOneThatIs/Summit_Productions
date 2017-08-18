#pragma once

#include<string>
#include<SFML\Graphics.hpp>


namespace summit{

class Window {
	sf::RenderWindow renderWindow;
	bool isFullscreen;

public:
	Window();
	Window(std::string name, int width, int height);


	void create(std::string name, int width, int height);

	bool pollEvents(sf::Event *event);

	void clear(sf::Color clearColor);
	void display();

	void draw(const sf::Drawable &drawable);

	
	void setKeyRepeatEnabled(bool enabled);

	void setDimensions(int width, int height);
	
	/*
	***BUG***
	Game lags terribly in fullscreen mode.
	*/
	void toggleFullscreen();

	bool isOpen();
	int getWidth();
	int getHeight();

	void close();
};

}
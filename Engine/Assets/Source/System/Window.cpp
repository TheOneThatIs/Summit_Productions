#include "Window.h"


namespace sp {
	Window::Window(): isFullscreen(false) {}

	Window::Window(std::string name, int width, int height) {
		renderWindow.create(sf::VideoMode(width, height), name);
	}

	void Window::create(std::string name, int width, int height) {
		renderWindow.create(sf::VideoMode(width, height), name);
	}

	bool Window::pollEvents(sf::Event *event){
		return renderWindow.pollEvent(*event);
	}

	void Window::clear(sf::Color clearColor){
		renderWindow.clear(clearColor);
	}

	void Window::display(){
		renderWindow.display();
	}


	void Window::draw(const sf::Drawable &drawable) {
		renderWindow.draw(drawable);
	}


	void Window::setKeyRepeatEnabled(bool enabled) {
		renderWindow.setKeyRepeatEnabled(enabled);
	}

	void Window::setCam(Camera cam) {
		renderWindow.setView(cam.view);
	}

	void Window::setDimensions(int width, int height) {
		renderWindow.setSize(sf::Vector2u(width, height));
	}

	void Window::toggleFullscreen() {
		std::vector<sf::VideoMode> videoModes =  sf::VideoMode::getFullscreenModes();
		if (!isFullscreen) {
			renderWindow.create(videoModes[0], "Kaplooey!", sf::Style::Fullscreen);
			isFullscreen = true;
		}
		else {
			renderWindow.create(videoModes[0], "Kaplooey!", sf::Style::Default);
			isFullscreen = false;
		}
	}

	bool Window::isOpen(){
		return renderWindow.isOpen();
	}

	int Window::getWidth() {
		return renderWindow.getSize().x;
	}
	int Window::getHeight() {
		return renderWindow.getSize().y;
	}

	sf::View Window::getDefaultView() {
		return renderWindow.getDefaultView();
	}
	
	void Window::close() {
		renderWindow.close();
	}
}
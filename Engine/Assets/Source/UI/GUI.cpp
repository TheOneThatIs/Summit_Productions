#include"GUI.h"
#include"..\Graphics\Camera.h"


namespace sp {
	GUI::GUI() {}
	GUI::GUI(sp::Window *window){}

	void GUI::init(std::string filePath, sf::IntRect hitBox, sp::Point pos, sp::Window *window) {
		std::cout << pos.x << std::endl;
		setTexture(filePath);
		setHitBox(hitBox);
		setPosition(pos);
		windowPtr = window;
	}

	void GUI::draw() {
		image.draw(windowPtr);
	}


	void GUI::setTexture(Image image) {}
	void GUI::setTexture(std::string filePath) {
		image.init(filePath, sp::Point(0, 0));
	}

	void GUI::setPosition(sp::Point pos) { // Sets exact position
		this->pos = pos;
		image.setPosition(pos);
		hitBox.left = pos.x;
		hitBox.top = pos.y;
	}

	void GUI::setHitBox(sf::IntRect hitBox) { this->hitBox = hitBox; }

	bool GUI::update(sp::Point mousePos) {
		if (mousePos.x >= hitBox.left && mousePos.x <= (hitBox.left + hitBox.width) && mousePos.y >= hitBox.top && mousePos.y <= (hitBox.top + hitBox.height))
			return true;
		return false;
	}

	void GUI::move(float x, float y) { // Adds param xy into GUIs xy
		this->pos.x += x;
		this->pos.y += y;
	} 


	sp::Point GUI::getPosition() { return pos; }
}
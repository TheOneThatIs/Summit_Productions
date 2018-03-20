#include "RenderLayer.h"
#include<iostream>

namespace sp {
	RenderLayer::RenderLayer(sp::Window* window) {
		this->window = window;
	}

	void RenderLayer::addImage(sp::Image* image) {
		imagePtrs.push_back(image);
		std::cout << "Image added to render layer." << std::endl;
	}

	void RenderLayer::render() {
		for (int i = 0; i < imagePtrs.size(); i++) {
			window->draw(*imagePtrs[i]->getSprite()); // I think the dereference of imagePtrs is what causes the sprites to not draw, but SFML forced me to do it
		}
	}
}
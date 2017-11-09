#include "TileFern.h"



TileFern::TileFern() :
	ITile(4, 25), image("Resources/Textures/Terrain/Plants.png", {25, 0, 25, 25 }){
}
TileFern::~TileFern(){}


void TileFern::update() {

}

void TileFern::draw(sp::Window *window) {
	image.draw(window);
}

void TileFern::setPosition(float x, float y) {
	image.setPosition({ x, y });
}
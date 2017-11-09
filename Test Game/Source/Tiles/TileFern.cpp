#include "TileFern.h"



TileFern::TileFern() :
	ITile(4, 25, sp::Image("Resources/Textures/Terrain/Plants.png", {25, 0, 25, 25 })){
}
TileFern::~TileFern(){}


void TileFern::update() {

}

void TileFern::draw(sp::Window *window) {
	i_image.draw(window);
}
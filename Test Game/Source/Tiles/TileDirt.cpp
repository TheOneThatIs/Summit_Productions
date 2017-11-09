#include "TileDirt.h"



TileDirt::TileDirt() :
	ITile(0, 25, sp::Image("Resources/Textures/Terrain/Dirt.png", { 0, 0, 25, 25 })){
}
TileDirt::~TileDirt(){}


void TileDirt::update() {

}

void TileDirt::draw(sp::Window *window) {
	i_image.draw(window);
}
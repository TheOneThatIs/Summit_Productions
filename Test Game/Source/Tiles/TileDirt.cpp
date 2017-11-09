#include "TileDirt.h"



TileDirt::TileDirt() :
	ITile(0, 25), image("Resources/Textures/Terrain/Other.png", { 0, 0, 25, 25 }){
}
TileDirt::~TileDirt(){}


void TileDirt::update() {

}

void TileDirt::draw(sp::Window *window) {
	image.draw(window);
}

void TileDirt::setPosition(float x, float y) {
	image.setPosition({ x, y });
}
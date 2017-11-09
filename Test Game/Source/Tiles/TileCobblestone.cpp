#include "TileCobblestone.h"



TileCobblestone::TileCobblestone() :
	ITile(3, 25), image("Resources/Textures/Terrain/Stone.png", { 0, 25, 25, 25 })
{
}
TileCobblestone::~TileCobblestone(){}


void TileCobblestone::update() {

}

void TileCobblestone::draw(sp::Window *window) {
	image.draw(window);
}

void TileCobblestone::setPosition(float x, float y) {
	image.setPosition({ x, y });
}
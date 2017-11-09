#include "TileFlower.h"
#include<Engine\Assets\Source\Graphics\Image.h>


TileFlower::TileFlower() :
	ITile(5, 200), image("Resources/Textures/Terrain/Plants.png", {25, 0, 25, 25})
{}
TileFlower::~TileFlower(){}


void TileFlower::update() {

}

void TileFlower::draw(sp::Window *window) {
	image.draw(window);
}

void TileFlower::setPosition(float x, float y) {
	image.setPosition({ x, y });
}
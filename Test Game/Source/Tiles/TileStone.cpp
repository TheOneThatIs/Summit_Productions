#include "TileStone.h"
#include<Engine\Assets\Source\Graphics\Image.h>


TileStone::TileStone() :
	ITile(2, 200), image("Resources/Textures/Terrain/Stone.png", {0, 0, 25, 25})
{}
TileStone::~TileStone(){}


void TileStone::update() {

}

void TileStone::draw(sp::Window *window) {
	image.draw(window);
}

void TileStone::setPosition(float x, float y) {
	image.setPosition({ x, y });
}
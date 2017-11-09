#include "TileShist.h"
#include<Engine\Assets\Source\Graphics\Image.h>


TileShist::TileShist() :
	ITile(9, 200), image("Resources/Textures/Terrain/Stone.png", {0, 0, 25, 25})
{}
TileShist::~TileShist(){}


void TileShist::update() {

}

void TileShist::draw(sp::Window *window) {
	image.draw(window);
}

void TileShist::setPosition(float x, float y) {
	image.setPosition({ x, y });
}
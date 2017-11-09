#include "TileGrass.h"
#include<Engine\Assets\Source\Graphics\Image.h>


TileGrass::TileGrass() :
	ITile(1, 200), image("Resources/Textures/Terrain/Other.png", {25, 0, 25, 25})
{}
TileGrass::~TileGrass(){}


void TileGrass::update() {

}

void TileGrass::draw(sp::Window *window) {
	image.draw(window);
}

void TileGrass::setPosition(float x, float y) {
	image.setPosition({ x, y });
}
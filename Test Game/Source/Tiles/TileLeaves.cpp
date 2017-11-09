#include "TileLeaves.h"
#include<Engine\Assets\Source\Graphics\Image.h>


TileLeaves::TileLeaves() :
	ITile(8, 200), image("Resources/Textures/Terrain/Stone.png", {0, 25, 25, 25})
{}
TileLeaves::~TileLeaves(){}


void TileLeaves::update() {

}

void TileLeaves::draw(sp::Window *window) {
	image.draw(window);
}

void TileLeaves::setPosition(float x, float y) {
	image.setPosition({ x, y });
}
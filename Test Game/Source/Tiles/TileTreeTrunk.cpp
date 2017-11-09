#include "TileTreeTrunk.h"
#include<Engine\Assets\Source\Graphics\Image.h>


TileTreeTrunk::TileTreeTrunk() :
	ITile(7, 200), image("Resources/Textures/Terrain/Trees.png", {25, 0, 25, 25})
{}
TileTreeTrunk::~TileTreeTrunk(){}


void TileTreeTrunk::update() {

}

void TileTreeTrunk::draw(sp::Window *window) {
	image.draw(window);
}

void TileTreeTrunk::setPosition(float x, float y) {
	image.setPosition({ x, y });
}
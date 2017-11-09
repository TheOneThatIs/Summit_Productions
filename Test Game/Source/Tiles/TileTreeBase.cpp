#include "TileTreeBase.h"
#include<Engine\Assets\Source\Graphics\Image.h>


TileTreeBase::TileTreeBase() :
	ITile(6, 200), image("Resources/Textures/Terrain/Trees.png", {0, 0, 25, 25})
{}
TileTreeBase::~TileTreeBase(){}


void TileTreeBase::update() {

}

void TileTreeBase::draw(sp::Window *window) {
	image.draw(window);
}

void TileTreeBase::setPosition(float x, float y) {
	image.setPosition({ x, y });
}
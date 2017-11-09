#include "TileStone.h"
#include<Engine\Assets\Source\Graphics\Image.h>


TileStone::TileStone() :
	ITile(2, 200, sp::Image("Resources/Textures/Terrain/Stone.png", {0, 0, 25, 25}))
{}
TileStone::~TileStone(){}


void TileStone::update() {

}

void TileStone::draw(sp::Window *window) {
	i_image.draw(window);
}
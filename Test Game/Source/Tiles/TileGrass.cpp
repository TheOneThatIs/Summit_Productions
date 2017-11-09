#include "TileGrass.h"
#include<Engine\Assets\Source\Graphics\Image.h>


TileGrass::TileGrass() :
	ITile(1, 200, sp::Image("Resources/Textures/Terrain/Grass.png", {0, 0, 25, 25}))
{}
TileGrass::~TileGrass(){}


void TileGrass::update() {

}

void TileGrass::draw(sp::Window *window) {
	i_image.draw(window);
}
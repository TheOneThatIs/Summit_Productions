#include "TileCobblestone.h"



TileCobblestone::TileCobblestone() :
	ITile(3, 25, sp::Image("Resources/Textures/Terrain/Stone.png", {0, 25, 25, 25} )){
}
TileCobblestone::~TileCobblestone(){}


void TileCobblestone::update() {

}

void TileCobblestone::draw(sp::Window *window) {

}
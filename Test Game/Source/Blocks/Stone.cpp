#include "Stone.h"



Stone::Stone(int id) : Tile(id){
	setDimensions(25, 25);
	setTexture("Resources/Textures/Blocks/Stone.png");
}
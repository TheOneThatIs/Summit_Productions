#include "TileBatch.h"

#include"TileDirt.h"
#include"TileGrass.h"
#include"TileStone.h"
#include"TileCobblestone.h"
#include"TileFern.h"


TileBatch::TileBatch(){}
TileBatch::~TileBatch(){}


sp::ITile* TileBatch::createTile(int id) {
	switch (id) {
		case 0:
			return new TileDirt();
		case 1:
			return new TileGrass();
		case 2:
			return new TileStone();
		case 3:
			return new TileCobblestone();
		case 4:
			return new TileFern();
		default:
			std::cout << "[***ERROR***] A tile with ID " << id << " does not exist!" << std::endl;
			//return nullptr;
	}
}
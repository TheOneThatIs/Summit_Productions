#pragma once
#include<Engine\Assets\Source\World\ITile.h>
#include<Engine\Assets\Source\World\ITileBatch.h>


class TileBatch : public sp::ITileBatch{
public:
	TileBatch();
	~TileBatch();

	sp::ITile* createTile(int id);
};
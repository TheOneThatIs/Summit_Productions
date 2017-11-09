#pragma once
#include<Engine\Assets\Source\World\ITile.h>

class TileGrass : public sp::ITile{
public:
	TileGrass();
	~TileGrass();

	void update() override;
	void draw(sp::Window *window) override;
};
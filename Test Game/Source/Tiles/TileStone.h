#pragma once
#include<Engine\Assets\Source\World\ITile.h>

class TileStone : public sp::ITile{
public:
	TileStone();
	~TileStone();

	void update() override;
	void draw(sp::Window *window) override;
};
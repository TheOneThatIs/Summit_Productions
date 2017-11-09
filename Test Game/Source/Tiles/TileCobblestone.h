#pragma once
#include<Engine\Assets\Source\World\ITile.h>

class TileCobblestone : public sp::ITile {
public:
	TileCobblestone();
	~TileCobblestone();

	void update() override;
	void draw(sp::Window *window) override;
};
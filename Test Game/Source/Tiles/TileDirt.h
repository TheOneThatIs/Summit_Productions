#pragma once
#include<Engine\Assets\Source\World\ITile.h>

class TileDirt : public sp::ITile {
public:
	TileDirt();
	~TileDirt();

	void update() override;
	void draw(sp::Window *window) override;
};
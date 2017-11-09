#pragma once
#include<Engine\Assets\Source\World\ITile.h>

class TileFern : public sp::ITile {
public:
	TileFern();
	~TileFern();

	void update() override;
	void draw(sp::Window *window) override;
};
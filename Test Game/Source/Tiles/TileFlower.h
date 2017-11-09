#pragma once
#include<Engine\Assets\Source\World\ITile.h>
#include<Engine\Assets\Source\Graphics\Image.h>


class TileFlower : public sp::ITile{
	sp::Image image;
public:
	TileFlower();
	~TileFlower();

	void update() override;
	void draw(sp::Window *window) override;

	void setPosition(float x, float y);
};
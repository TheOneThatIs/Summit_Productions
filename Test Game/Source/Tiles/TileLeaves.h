#pragma once
#include<Engine\Assets\Source\World\ITile.h>
#include<Engine\Assets\Source\Graphics\Image.h>


class TileLeaves : public sp::ITile{
	sp::Image image;
public:
	TileLeaves();
	~TileLeaves();

	void update() override;
	void draw(sp::Window *window) override;

	void setPosition(float x, float y);
};
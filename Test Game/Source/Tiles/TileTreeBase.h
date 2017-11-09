#pragma once
#include<Engine\Assets\Source\World\ITile.h>
#include<Engine\Assets\Source\Graphics\Image.h>


class TileTreeBase : public sp::ITile{
	sp::Image image;
public:
	TileTreeBase();
	~TileTreeBase();

	void update() override;
	void draw(sp::Window *window) override;

	void setPosition(float x, float y);
};
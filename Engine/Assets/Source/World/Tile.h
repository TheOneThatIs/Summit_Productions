#pragma once
#include<vector>
#include"..\Graphics\Image.h"
#include"..\Math\Point.h"


namespace sp{
	class Tile {
	protected:
		int id;
		Image texture;
		Point pos;
		float width, height;

	public:
		Tile(int id);

		void setTexture(std::string filePath);

		int getID();

		void draw(Window *window);

		void setPosition(float x, float y);
		
		float getWidth();
		float getHeight();

	private:
		void setID(int id);

	protected:
		void setDimensions(float width, float height);
	};
}
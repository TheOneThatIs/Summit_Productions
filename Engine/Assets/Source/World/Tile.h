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

	public:
		Tile(int id);

		void setTexture(std::string filePath);

		int getID();

		void draw(Window *window);

	private:
		void setID(int id);
	};
}
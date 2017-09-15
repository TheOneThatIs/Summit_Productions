#pragma once
#include"..\..\Graphics\Image.h"
#include"..\..\Math\Point.h"
#include"..\..\Math\Vector.h"


namespace sp {
	class Entity {
	protected:
		sp::Image img_spriteSheet;
		Point pos;
		int id;
		
	public:
		Entity(int id);

		virtual void uponCreation() = 0;
		virtual void update() = 0;
		virtual void draw(sp::Window *window) = 0;
		virtual void uponDestruction() = 0;

		void setPos(float x, float y);
		Point getPos();

	private:
		void setID(int id);
	};
}
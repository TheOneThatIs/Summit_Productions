#pragma once
#include"..\Graphics\Image.h"


namespace sp {
	class Entity {
	protected:
		sp::Image img_spriteSheet;
		Point pos;
		int id;
		
	public:
		Entity(int id);
		~Entity();


		virtual void uponCreation();
		virtual void update(sf::Event &event);
		virtual void draw(sp::Window *window);
		virtual void uponDestruction();

		void setPos(float x, float y);
		Point getPos();

		int getID();

	private:
		void setID(int id);
	};
}
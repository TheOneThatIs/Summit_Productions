#pragma once
#include"..\Graphics\Image.h"


namespace sp {

	enum BlockState{
		NORMAL, BREAKING, BROKEN
	};

	class ITile {
	protected:
		const int i_ID;
		const int i_durability;
		int i_damage;
		sp::Image i_image;

	public:
		ITile(int id, int durability, sp::Image image);
		~ITile();

		virtual BlockState damage(float damage);
		virtual void onDestroy();
		virtual void update();
		virtual void draw(sp::Window *window) = 0;


		void setPosition(float x, float y);

		int getID();
		int getDurability();
		int getDamage();
		sp::Image getImage();
	};
}
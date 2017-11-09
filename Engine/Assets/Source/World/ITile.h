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

	public:
		ITile(int id, int durability);
		~ITile();

		virtual BlockState damage(float damage);
		virtual void onDestroy();
		virtual void update();
		virtual void draw(sp::Window *window) = 0;
		virtual void setPosition(float x, float y) = 0;

		int getID();
		int getDurability();
		int getDamage();
	};
}
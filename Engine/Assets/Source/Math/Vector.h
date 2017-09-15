#pragma once
#include"Point.h"



namespace sp {
	class Vector {
		Point origin;
		float magnitude;

	public:
		Vector();
		Vector(Point origin);
		Vector(float x, float y);

		void setOrigin(float x, float y);
		Point getOrigin();

		float getMagnitude();

		void normalize();




		Vector operator +(Vector vec);
		Vector operator +(float factor);

		Vector operator -(Vector vec);
		Vector operator -(float factor);

		Vector operator *(Vector factor);
		Vector operator *(float factor);
	};
}
#pragma once
#include"Point.h"
#include<iostream>


namespace sp {
	class Vector {
		Point origin;
		float magnitude;

	public:
		Vector();
		Vector(Point origin);
		Vector(float x, float y);

		void setOrigin(float x, float y);
		Point getOrigin() const;

		float getMagnitude() const;

		void normalize();




		Vector operator +(Vector vec) const;
		Vector operator +(float factor) const;

		Vector operator -(Vector vec) const;
		Vector operator -(float factor) const;

		Vector operator *(Vector factor) const;
		Vector operator *(float factor) const;
		//std::ostream& operator<<(std::ostream& stream, const Vector& vec) const;
	};
}
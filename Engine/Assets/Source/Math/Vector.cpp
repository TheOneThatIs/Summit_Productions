#include"Vector.h"
#include<math.h>
#include<iostream>

namespace sp{

	Vector::Vector() {
		setOrigin(0, 0);
	}
	Vector::Vector(Point origin) {
		setOrigin(origin.x, origin.y);
	}
	Vector::Vector(float x, float y) {
		setOrigin(x, y);
	}


	void Vector::setOrigin(float x, float y) {
		origin.x = x;
		origin.y = y;

		magnitude = sqrt(x*x + y*y);
	}

	Point Vector::getOrigin() {
		return origin;
	}

	float Vector::getMagnitude() {
		return magnitude;
	}

	void Vector::normalize() {
		origin.x = origin.x / magnitude;
		origin.y = origin.y / magnitude;
	}





	Vector Vector::operator + (Vector vec) {
		Vector temp;
		temp.setOrigin(origin.x + vec.getOrigin().x, origin.y + vec.getOrigin().y);

		return temp;
	}

	Vector Vector::operator + (float factor) {
		Vector temp;
		temp.setOrigin(origin.x + factor, origin.y + factor);

		return temp;
	}

	Vector Vector::operator - (Vector vec) {
		Vector temp;
		temp.setOrigin(origin.x - vec.getOrigin().x, origin.y - vec.getOrigin().y);

		return temp;
	}

	Vector Vector::operator - (float factor) {
		Vector temp;
		temp.setOrigin(origin.x - factor, origin.y - factor);

		return temp;
	}

	Vector Vector::operator * (float factor) {
		Vector temp;
		temp.setOrigin(origin.x * factor, origin.y * factor);

		return temp;
	}
	Vector Vector::operator * (Vector vec) {
		Vector temp;
		temp.setOrigin(origin.x * vec.getOrigin().x, origin.y * vec.getOrigin().y);

		return temp;
	}
}
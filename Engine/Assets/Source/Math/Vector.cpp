#include"Vector.h"
#include<math.h>


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

	Point Vector::getOrigin() const {
		return origin;
	}

	float Vector::getMagnitude() const {
		return magnitude;
	}

	void Vector::normalize() {
		origin.x = origin.x / magnitude;
		origin.y = origin.y / magnitude;
	}





	Vector Vector::operator + (Vector vec) const {
		return Vector(origin.x + vec.getOrigin().x, origin.y + vec.getOrigin().y);
	}

	Vector Vector::operator + (float factor) const {
		return Vector(origin.x + factor, origin.y + factor);
	}

	Vector Vector::operator - (Vector vec) const {
		return Vector(origin.x - vec.getOrigin().x, origin.y - vec.getOrigin().y);
	}

	Vector Vector::operator - (float factor) const {
		return Vector(origin.x - factor, origin.y - factor);
	}

	Vector Vector::operator * (float factor) const {
		return Vector(origin.x * factor, origin.y * factor);
	}
	Vector Vector::operator * (Vector vec) const {
		return Vector(origin.x * vec.getOrigin().x, origin.y * vec.getOrigin().y);
	}
	//std::ostream& Vector::operator<<(std::ostream& stream, const Vector& vec) const {
	//	// TO-DO
	//	stream << "(" << vec.getOrigin().x << ", " << vec.getOrigin().y << ")";
	//	return stream;
	//}
}
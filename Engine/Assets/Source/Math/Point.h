#pragma once

namespace sp {
	struct Point {
		float x, y;

		Point() { x = 0; y = 0; }
		Point(float x, float y) { this->x = x; this->y = y; }
	};
	struct Point3D : Point {
		float z;
	};
}
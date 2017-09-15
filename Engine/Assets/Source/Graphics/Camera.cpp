#include "Camera.h"


namespace sp {
	Camera::Camera(sf::FloatRect viewRect) : view(viewRect) {

	}

	void Camera::move(sp::Point point) {
		view.setCenter(sf::Vector2f(point.x, point.y));
	}

	void Camera::reset(sf::FloatRect rect) {
		view.reset(rect);
	}
}
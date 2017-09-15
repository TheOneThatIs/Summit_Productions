#pragma once
#include<SFML\Graphics.hpp>
#include"..\Math\Point.h"


namespace sp {
	class Camera {
	public:
		sf::View view;
		
		Camera(sf::FloatRect viewRect);

		void move(sp::Point);

		void reset(sf::FloatRect rect);
	};
}
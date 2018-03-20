#pragma once
#include<string>
#include"..\Math\Point.h"
#include<SFML\Graphics.hpp>
#include<vector>
#include<memory>
#include"Image.h"
#include"..\System\Window.h"


namespace sp {
	class RenderLayer {
		std::vector<sp::Image*> imagePtrs;
		sp::Window* window;

	public:
		RenderLayer(sp::Window* window);
		void addImage(sp::Image* image);
		void render();
	};
}
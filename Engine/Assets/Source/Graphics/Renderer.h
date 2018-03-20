#pragma once

#include"RenderLayer.h"
#include"RenderLayer.h"
#include<vector>

namespace sp {
	class Renderer {
		static std::vector<RenderLayer*> renderLayers;
	public:
		Renderer();
		static void addLayer(sp::RenderLayer* renderLayer);
		void removeLayer();
		static void render();
	};
}
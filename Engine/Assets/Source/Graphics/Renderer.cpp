#include "Renderer.h"

std::vector<sp::RenderLayer*> sp::Renderer::renderLayers;

namespace sp {

	Renderer::Renderer() {}
	

	void Renderer::addLayer(sp::RenderLayer* renderLayer) {
		renderLayers.push_back(renderLayer);
	}
	void Renderer::removeLayer() {
		renderLayers.pop_back();
	}
	void Renderer::render() {
		for (int i = 0; i < renderLayers.size(); i++) {
			renderLayers[i]->render();
		}
	}

}
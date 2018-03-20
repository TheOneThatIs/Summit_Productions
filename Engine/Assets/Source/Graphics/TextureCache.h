#pragma once
#include<map>
#include<memory>
#include<vector>
#include"RenderLayer.h"
#include"..\Util\Vec.h"
#include<SFML\Graphics.hpp>

namespace sp {

class TextureCache {
protected:
	static std::map <std::string, std::shared_ptr<sf::Texture>> textures;

public:
	static std::shared_ptr<sf::Texture> getTexture(const std::string& filePath);
	static void freeOrphans();

private:

	TextureCache();
};

}
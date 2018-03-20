#include "TextureCache.h"
#include<iostream>

std::map <std::string, std::shared_ptr<sf::Texture>> sp::TextureCache::textures;

namespace sp{


	TextureCache::TextureCache(){}

	std::shared_ptr<sf::Texture> TextureCache::getTexture(const std::string& filePath) { // *** TODO ***: Add error checking
		const auto it = textures.find(filePath);
		if (it != textures.end()) { // If texture is found in cache
			std::cout << "Loading cached Image!" << std::endl;
			return it->second; // Return cached texture
		}
			else { // Texture not found in cache, create one
				std::shared_ptr<sf::Texture> pTexture = std::make_shared<sf::Texture>(); // Create a shared pointer for our texture
				if (pTexture->loadFromFile(filePath)) { // Do not insert texture into the cache if it fails to load
					textures.insert({ filePath, pTexture }); // Insert it into the map
					std::cout << "Created new Image!" << std::endl;
					return pTexture;
				}
				return nullptr; // File failed to load
			}
	}
	void TextureCache::freeOrphans() {
		for(auto it = textures.begin(); it != textures.end(); ) {
			if (it->second.unique()) // If nothing's using the resource
				it = textures.erase(it); // Free the memory and set the iterator to the next element in the map
				else
					it++; // Something is using that resource, keep it in memory and check next element in the map
		}
		std::cout << "Number of cached textures: " << textures.size() << std::endl;
	}

}
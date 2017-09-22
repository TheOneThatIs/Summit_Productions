#include"TestGame.h"


int main(int argc, char** argv) {
	TestGame game;
	sf::Event event;

	game.gameLoop(event, 60);

	return 0;
}
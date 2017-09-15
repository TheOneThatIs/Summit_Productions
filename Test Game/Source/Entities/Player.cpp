#include "Player.h"



Player::Player(int id) : Entity(id) {
	uponCreation();
}
Player::~Player(){
	uponDestruction();
}


void Player::uponCreation() {
	std::cout << "Player created!" << std::endl;
	img_spriteSheet.init("Resources/Textures/Player.png", sp::Point(100, 100));
}

void Player::update() {
	//std::cout << "Updating the player with ID: " << id << std::endl;
	img_spriteSheet.setPosition(getPos());
}

void Player::draw(sp::Window *window) {
	//std::cout << "Drawing the player with ID: " << id << std::endl;
	img_spriteSheet.draw(window);
}

void Player::uponDestruction() {
	std::cout << "Player destroyed!" << std::endl;
}
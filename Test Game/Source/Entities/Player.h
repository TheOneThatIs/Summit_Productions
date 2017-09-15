#pragma once
#include<Engine\Assets\Source\World\Entities\Entity.h>
#include<Engine\Assets\Source\System\Window.h>


class Player : public sp::Entity{
public:
	Player(int id);
	~Player();

	void uponCreation() override;

	void update() override;
	void draw(sp::Window *window) override;

	void uponDestruction() override;
};
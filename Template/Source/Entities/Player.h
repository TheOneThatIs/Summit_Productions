#pragma once
#include<Engine\Assets\Source\World\Entities\Entity.h>


class Player : public sp::Entity{
public:
	Player(int id);

	void uponCreation() override;
	void update() override;
	void uponDestruction() override;
};
#pragma once
#include "entity.h"
#include "random.h"

class enemy : public entity
{
public:
	float playermovespeed = 1;
	int movementlength = 100;
	int attackdmg = 1;
	int counterwalking = 0;
	int direction = 0; // i messed up directions but ok
	int counter1 = 0;
	int hp = 3;
	bool alive = true;

	enemy();
	void update();
	void updateMovement();
};
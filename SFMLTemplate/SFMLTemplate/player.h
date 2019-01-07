#pragma once

#include "entity.h"

class player : public entity 
{
public:
	float playermovespeed = 0.5;
	int attackdmg = 5;
	int counterwalking = 0;
	int direction = 0; // 1 up 2 down 3 left 4 right
	int health = 10;
	int coins = 0;
	bool moveup = true;
	bool movedown = true;
	bool moveleft = true;
	bool moveright = true;
	player();
	void update();
	void updateMovement();
};
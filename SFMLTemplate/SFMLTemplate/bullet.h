#pragma once
#include "entity.h"

class bullet : public entity
{
public:
	float bulletspeed = 20;
	int attackdmg = 1;
	int direction = 0; 
	bool destroy = false;
	int counterlife = 0;
	int lifetime = 20;
	bullet();
	void update();

};
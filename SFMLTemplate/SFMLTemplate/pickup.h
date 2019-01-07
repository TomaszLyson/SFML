#pragma once
#include "entity.h"

class pickup : public entity
{
public:
	
	bool isCoin = true;
	bool destroy = false;
	int coinvalue = 5;

	pickup();
	void update();

};


#pragma once
#include "entity.h"
#include <string>

class textDisplay: public entity
{
public:
	float movementspeedtext = 2;
	string myString = "sample";
	int counter = 0;
	bool destroy = false;
	int lifetimecounter = 50;

	textDisplay();
	void update();
};


#include "random.h"

int generateRandom(int max) {
	int randomNumber = rand();
	float random = (randomNumber % max) + 1;
	int truerandom = random;
	return truerandom;
}

int generateRandom1(int max) {
	int randomNumber = rand();
	float random = (randomNumber % max);
	int truerandom = random;
	return truerandom;
}

int generateRandomBoolean()
{
	int randomNumber = rand();
	float random = (randomNumber % 2) + 1;
	int truerandom = random;
	if (truerandom == 1) {
		return true;
	}
	else {
		return false;
	}
}


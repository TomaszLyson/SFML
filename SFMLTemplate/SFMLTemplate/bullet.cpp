#include "bullet.h"

bullet::bullet()
{
		rect.setSize(sf::Vector2f(25, 25));
		rect.setPosition(0, 0);
		rect.setFillColor(sf::Color::Yellow);
		//sprite.setTextureRect(sf::IntRect(0, 0, 24, 32));
}

void bullet::update() {
	if (direction == 1) {
		rect.move(0, -bulletspeed);
	}
	if (direction == 2) {
		rect.move(0, bulletspeed);
	}
	if (direction == 3) {
		rect.move(-bulletspeed, 0);
	}
	if (direction == 4) {
		rect.move(bulletspeed, 0);
	}

	counterlife++;
	if (counterlife >= lifetime) {
		destroy = true;
	}
}
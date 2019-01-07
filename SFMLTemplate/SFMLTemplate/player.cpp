#include "player.h"

player::player()
{
	rect.setSize(sf::Vector2f(24, 32));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect(0, 0, 24, 32));
	playermovespeed = 6;
}

void player::update() {
	sprite.setPosition(rect.getPosition());
}

void player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (moveright == true) {
			rect.move(playermovespeed, 0);
			sprite.setTextureRect(sf::IntRect(counterwalking * 24, 32 * 3, 24, 32));
			direction = 4;
			moveright = true;
			moveleft = true;
			moveup = true;
			movedown = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{ 
		if (moveleft == true) {
			rect.move(-playermovespeed, 0);
			sprite.setTextureRect(sf::IntRect(counterwalking * 24, 32 * 2, 24, 32));
			direction = 3;
			moveright = true;
			moveleft = true;
			moveup = true;
			movedown = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (moveup == true) {
			rect.move(0, -playermovespeed);
			sprite.setTextureRect(sf::IntRect(counterwalking * 24, 32, 24, 32));
			direction = 1;
			moveright = true;
			moveleft = true;
			moveup = true;
			movedown = true;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (movedown == true) {
			rect.move(0, playermovespeed);
			sprite.setTextureRect(sf::IntRect(counterwalking * 24, 0, 24, 32));
			direction = 2;
			moveright = true;
			moveleft = true;
			moveup = true;
			movedown = true;
		}
	}
	else {

	}
	counterwalking++;

	if (counterwalking == 8) {
		counterwalking = 0;
	}
}

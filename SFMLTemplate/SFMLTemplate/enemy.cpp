#include "enemy.h"



enemy::enemy()
{
	rect.setSize(sf::Vector2f(32, 32));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect(49 * 5, 0, 49, 49));
	//playermovespeed = 0.05;
}


void enemy::update() {
	sprite.setPosition(rect.getPosition());
}

void enemy::updateMovement()
{



	if (direction ==3)
	{
		rect.move(playermovespeed, 0);
		sprite.setTextureRect(sf::IntRect((49 * 6) + 49 * counterwalking, 0, 49, 49));
	
	}
	else if (direction ==4)
	{
		rect.move(-playermovespeed, 0);
		sprite.setTextureRect(sf::IntRect((49 * 4) + 49 * counterwalking,0, 49, 49));
	
	}
	else if (direction == 1)
	{
		rect.move(0, -playermovespeed);


	}
	else if (direction == 2)
	{
		rect.move(0, playermovespeed);


	} // no animations for up and down :(
	else {

	}
		
	
	counterwalking++;

	if (counterwalking == 1) {
		counterwalking = 0;
	}

	counter1++;
	if (counter1 >= movementlength)
	{
		direction = generateRandom(5);
		counter1 = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		//playermovespeed += 0.002f;
		movementlength -= 0.000000000000001;//idk why but it stops enemy from twitching in place
		counter1++;
	}
}
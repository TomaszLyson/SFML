#include "textDisplay.h"
#include "entity.h"


textDisplay::textDisplay()
{
	text.setFillColor(sf::Color::Green);
	text.setCharacterSize(25);
	text.setString(myString);
}

void textDisplay::update()
{
	text.move(0, -movementspeedtext);

	counter++;

	if (counter >= lifetimecounter) {

		destroy = true;
	}
}


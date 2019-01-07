#pragma once
#ifndef __SFMLTemplate__entity__
#define __SFMLTemplate__entity__

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <xtgmath.h>
#include <deque>
#include <list>
#include <vector> 

using namespace std;

class entity {
public:
	sf::RectangleShape rect;
	sf::Sprite sprite;
	sf::Text text;


private:
protected:
};


#endif /*defined(__SFMLTemplate__entity__)*/
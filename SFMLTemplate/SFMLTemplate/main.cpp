#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
#include "player.h"
#include "entity.h"
#include "bullet.h"
#include "enemy.h"
#include "random.h"
#include "textDisplay.h"
#include <vector>
#include "wall.h"
#include "pickup.h"
#include <luaconf.h>

extern "C" {
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
}

#include <LuaBridge/LuaBridge.h>

std::vector<std::string> getElements(const std::string& table, lua_State* L);









//previous submissions also had problems with older OS.
//everything is done on windows7, as far as Im aware, my projects differ on different OS. I have no clue how to fix. Win32 x86/ sdk 8.1 issues, compiler issues, symbol loading issues.








int main(int, char const**)
{
	//lua_State* F = luaL_newstate();
	//luaL_dofile(F, "level.lua");
	//luaL_openlibs(F);
	//lua_pcall(F, 0, 0, 0);

	//LuaRef t = getGlobal(F, "window");
	//LuaRef title = t["title"];
	//LuaRef w = t["width"];
	//LuaRef h = t["height"];

	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock clock3;
	int counter = 0;
	int counter2 = 0;
	int counter3 = 0;
	int counter4 = 0;
	sf::RenderWindow window(sf::VideoMode(1000,800), "SomeGameTing");
	window.setFramerateLimit(60);

	sf::Font font;
	if (!font.loadFromFile("arial.ttf")) {
	return EXIT_FAILURE;
	}

	sf::Texture texturePlayer;
	if (!texturePlayer.loadFromFile("spriteWalk.png")) {
		return EXIT_FAILURE;
	}

	sf::Texture textureCoin;
	if (!textureCoin.loadFromFile("FFV_Zeninage_Sprite_iOS.png")) {
		return EXIT_FAILURE;
	}

	sf::Texture textureEnemy;
	if (!textureEnemy.loadFromFile("enemySprite.png")) {
		return EXIT_FAILURE;
	}

	sf::Text text("coins", font, 25);
	text.setFillColor(sf::Color::Cyan);
	text.setCharacterSize(25);
	text.setPosition(22, 20);
	
	sf::Sprite spritePlayer(texturePlayer);
	//spritePlayer.setPosition(window.getSize().x / 2, window.getSize().y / 2);
	//spritePlayer.setTextureRect(sf::IntRect(0, 0, 26, 32));

	// text vector array
	vector<textDisplay>::const_iterator iter8;
	vector<textDisplay> textDisplayArray;
	//text display object
	class textDisplay textDisplay1;
	textDisplay1.text.setFont(font);

	//main player
	class player Player1;
	Player1.sprite.setTexture(texturePlayer);

	vector<bullet>::const_iterator iter;
	vector<bullet> bulletArray;

	//bullet projectile object
	class bullet bullet1;

	vector<enemy>::const_iterator iter4;
	vector<enemy> enemyArray;

	//enemy object
	class enemy enemy1;
	enemy1.sprite.setTexture(textureEnemy);
	//enemy1.sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));

	enemy1.rect.setPosition(600, 200);
	enemyArray.push_back(enemy1);

	vector<pickup>::const_iterator iter6;
	vector<pickup> pickupArray;

	class pickup pickup1;
	pickup1.sprite.setTexture(textureCoin);
	pickup1.rect.setPosition(500, 500);
	pickup1.rect.setSize(sf::Vector2f(16, 32)); // no difference
	pickupArray.push_back(pickup1);

	pickup1.rect.setPosition(650, 500);
	pickupArray.push_back(pickup1);

	//wall
	vector<wall>::const_iterator iter5;
	vector<wall> wallArray;
	class wall wall1;
	wall1.rect.setSize(sf::Vector2f(20, 700));
	wall1.rect.setPosition(550, 20);
	wallArray.push_back(wall1);

	wall1.rect.setSize(sf::Vector2f(1000, 20));
	wall1.rect.setPosition(0, 780);
	wallArray.push_back(wall1);

	wall1.rect.setSize(sf::Vector2f(20, 800));
	wall1.rect.setPosition(0, 0);
	wallArray.push_back(wall1);

	wall1.rect.setSize(sf::Vector2f(1000, 20));
	wall1.rect.setPosition(0, 0);
	wallArray.push_back(wall1);

	wall1.rect.setSize(sf::Vector2f(20, 800));
	wall1.rect.setPosition(980, 0);
	wallArray.push_back(wall1);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
		}
		//start of clear window on screen
		window.clear();


		sf::Time elapsed1 = clock.getElapsedTime();
		sf::Time elapsed2 = clock2.getElapsedTime();
		sf::Time elapsed3 = clock3.getElapsedTime();

		text.setString("Coins: " + to_string(Player1.coins));
		window.draw(text);

		counter = 0;
		for (iter5 = wallArray.begin(); iter5 != wallArray.end(); iter5++) {
			window.draw(wallArray[counter].rect);

			counter++;
		}


		counter = 0;
		for (iter5 = wallArray.begin(); iter5 != wallArray.end(); iter5++) {
			if (Player1.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds())) {
				if (Player1.direction == 1) {
					Player1.moveup = false;
					Player1.rect.move(0, 1);
				}
				else if (Player1.direction == 2) {
					Player1.movedown = false;
					Player1.rect.move(0, -1);
				}
				else if (Player1.direction == 3) {
					Player1.moveleft = false;
					Player1.rect.move(1, 0);
				}
				else if (Player1.direction == 4) {
					Player1.moveright = false;
					Player1.rect.move(-1, 0);
				}
				else {

				}

			}

			counter++;
		}






		counter = 0;
		for (iter6 = pickupArray.begin(); iter6 != pickupArray.end(); iter6++) {

			if (Player1.rect.getGlobalBounds().intersects(pickupArray[counter].rect.getGlobalBounds()))
			{
				if (pickupArray[counter].isCoin == true) 
				{
					Player1.coins += pickupArray[counter].coinvalue;
				}
				pickupArray[counter].destroy = true;
			}
			counter++;
		}





		if (elapsed2.asSeconds() >= 0.5)
		{
			clock2.restart();
			counter = 0;
			
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {

				if (Player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds())) {
					//text
					textDisplay1.text.setString(to_string(enemyArray[counter2].attackdmg));
					textDisplay1.text.setPosition(Player1.rect.getPosition().x, Player1.rect.getPosition().y);
					textDisplayArray.push_back(textDisplay1);

					Player1.health -= enemyArray[counter2].attackdmg;
				}

				counter++;
				
			}
		}
		if (Player1.health <= 0) {
			Player1.playermovespeed = 0;
		}
		cout << Player1.health << endl;


		counter = 0;
		for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++)
		{

			counter = 0;
			for (iter5 = wallArray.begin(); iter5 != wallArray.end(); iter5++) {

				if (bulletArray[counter].rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds())) 
				{
					bulletArray[counter].destroy = true;

					
				}
				
			}
			counter++;
		}
		//projectile and enemy collision
		counter = 0;
		for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++)
		{

			counter2 = 0;
			for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {

				if (bulletArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds())) 
				{
					//cout << "lmao" << endl; - testing
					bulletArray[counter].destroy = true;

					//text
					textDisplay1.text.setString(to_string(bulletArray[counter].attackdmg));
					textDisplay1.text.setPosition(enemyArray[counter2].rect.getPosition().x, enemyArray[counter2].rect.getPosition().y);
					textDisplayArray.push_back(textDisplay1);

					enemyArray[counter2].hp -= bulletArray[counter].attackdmg;
					if (enemyArray[counter2].hp <= 0) {
						enemyArray[counter2].alive = false;
					}
				}

				counter2++;
			}

			counter++;
		}

		counter = 0;
		for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++) {
			if (textDisplayArray[counter].destroy == true) {
				textDisplayArray.erase(iter8);
				break;
			}
			counter++;
		}


		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {

			if (enemyArray[counter].alive == false) {
				cout << "enemy dead" << endl;
				enemyArray.erase(iter4);
				break;
			}

			counter++;
		}

		counter = 0;
		for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++) {

			if (bulletArray[counter].destroy == true) {
				bulletArray.erase(iter);
				break;

			}

			counter++;
		}

		cout << int(bulletArray.size()) << endl;
		if (elapsed1.asSeconds()>= 0.15)
		{
			clock.restart();
			//shooting
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				bullet1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2 - bullet1.rect.getSize().x / 2, Player1.rect.getPosition().y + Player1.rect.getSize().y / 2 - bullet1.rect.getSize().y / 2);
				bullet1.direction = Player1.direction;
				bulletArray.push_back(bullet1);
				Player1.playermovespeed += 0.003;
				bullet1.bulletspeed += 0.006;
				
			}
			
		}
		//drawing coin
		counter = 0;
		for (iter6 = pickupArray.begin(); iter6 != pickupArray.end(); iter6++) {

			pickupArray[counter].update();

			window.draw(pickupArray[counter].sprite);
			counter++;
		}

		counter = 0;
		for (iter6 = pickupArray.begin(); iter6 != pickupArray.end(); iter6++) {

			if (pickupArray[counter].destroy == true)
			{
				pickupArray.erase(iter6);
				break;
			}
			counter++;
		}


		//drawing bullets
		counter = 0;
		for (iter = bulletArray.begin(); iter != bulletArray.end(); iter++) {

			bulletArray[counter].update();

			window.draw(bulletArray[counter].rect);
			
			counter++;
		}

		//drawing enemy
		counter = 0;
		for (iter4 = enemyArray.begin(); iter4 != enemyArray.end(); iter4++) {

			enemyArray[counter].update();
			enemyArray[counter].updateMovement();
			
			//window.draw(enemyArray[counter].rect);
			window.draw(enemyArray[counter].sprite);
			counter++;
		}

		//drawing text
		counter = 0;
		for (iter8 = textDisplayArray.begin(); iter8 != textDisplayArray.end(); iter8++) {
			window.draw(textDisplayArray[counter].text);
			textDisplayArray[counter].update();
			counter++;
		}
		
		//cout << Player1.playermovespeed << endl;

		//drawing a player
		window.draw(Player1.sprite);

		// update player
		Player1.update();
		Player1.updateMovement();

		window.display();
	}

	return 0;
}
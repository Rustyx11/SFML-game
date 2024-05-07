#include<iostream>
#include<cmath>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>

#include"enemy.h"
#include"player.h"
#include"wall.h"
#include"ladder.h"
#include"level.h"
#include"key.h"
#include"escape.h"
#include"animation.h"
#include"heart.h"

using namespace sf;
using namespace std;

int main()
{
	//consts
	const int WINDOW_WIDTH = 1920;
	const int WINDOW_HEIGHT = 1080;
	const int gridSize = 40;
	const float moveSpeed = 300.f;

	//background
	Sprite background;
	Texture backgroundTexture;

	backgroundTexture.setSmooth(true);
	backgroundTexture.setRepeated(true);


	//buttons textures
	Texture buttonsTexture;
	buttonsTexture.loadFromFile("textures/buttons.png");

	Texture buttonsDifficultyTexture;
	buttonsDifficultyTexture.loadFromFile("textures/buttons_difficulty.png");

	//player movement variables
	bool onLadder = false;
	float dt = 0.f;
	Vector2f velocity;
	int way = 0;

	//player jump variables
	bool onGround = true;
	bool isFalling = false;
	bool jump = true;

	//player powers variables
	int currentPower = 0;
	float boost = 1;

	//player text variables
	bool canPlayerMove = true;

	//Collision variables
	FloatRect nextPos;

	//level selector variables
	int select = 0;
	bool next = true;
	escape escape;


	//screen creator
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML works!", Style::Fullscreen);
	window.setFramerateLimit(120);

	//clocks variables
	Clock dt_clock;
	Clock isPlayerJumping;
	Clock powerUpClock;

	//enemy animation
	animation enemyAnimation;

	//vectors
	vector<wall> walls;
	vector<ladder> ladders;
	vector<enemy> enemys;
	vector<key> keys;
	vector<heart> hearts;
	vector<animation> enemyAnimations;
	vector<powerUps> powers;

	//player object
	player player;

	//player texture and animation
	player.initTexture("textures/player.png");
	animation animation;
	animation.initAnimation(&player.texture, 2, 4, 0.200);

	//Level object
	level level;


	// mouse variables
	FloatRect mouse;
	Vector2i mousePos;


	//menu variables
	RectangleShape start;
	RectangleShape difficulty;
	RectangleShape exit;
	float menuHeight = 105;
	float menuWidth = 410;
	int menuSelect = 1;

	//difficulty menu variables
	RectangleShape easy;
	RectangleShape normal;
	RectangleShape hardcore;
	RectangleShape back;

	/*
	// fonts
	Font font;
	font.loadFromFile("SF Atarian System.ttf");

	// text
	Text text;
	text.setPosition({gridSize*20,gridSize*15});
	text.setFont(font);
	text.setString("Hello world");
	text.setCharacterSize(24); 
	text.setFillColor(Color::Green);
	*/

	
	



	//hearts object
	heart heart;

	
	


	
	//game loop
	while (window.isOpen())
	{
		dt = dt_clock.restart().asSeconds();

		

		//close window
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();
		}


		//player deaths
		if (player.getLifes() == 0)
		{
			window.close();
		}

		if (next)
		{

			
			switch (select)
			{

				//case menu
			case 0:

				backgroundTexture.loadFromFile("textures/menu.png");
				background.setTexture(backgroundTexture);
				background.setTextureRect({ 0,0,WINDOW_WIDTH,WINDOW_HEIGHT});


				

				switch (menuSelect)
				{
					//case main menu
				case 1:

					start.setSize({ 200,60 });
					start.setPosition({ menuWidth * 2,menuHeight * 4 });

					difficulty.setSize({ 200,60 });
					difficulty.setPosition({ menuWidth * 2,menuHeight * 5 });

					exit.setSize({ 200,60 });
					exit.setPosition({ menuWidth * 2,menuHeight * 6 });
					break;
					//case choose difficulty
				case 2:

					easy.setSize({ 200,60 });
					easy.setPosition({ menuWidth * 2,menuHeight * 4 });

					normal.setSize({ 200,60 });
					normal.setPosition({ menuWidth * 2,menuHeight * 5 });

					hardcore.setSize({ 200,60 });
					hardcore.setPosition({ menuWidth * 2,menuHeight * 6 });

					back.setSize({ 200,60 });
					back.setPosition({ menuWidth * 2,menuHeight * 7 });
				
					break;
				}

				next = false;
				break;
				//case level 1
			case 1:

				walls.clear();
				ladders.clear();
				enemys.clear();
				keys.clear();

				for (float i = 0; i < player.getLifes(); i++)
				{
					heart.setPos({ i * gridSize, 0 });
					heart.initTexture("textures/heart.png");
					hearts.push_back(heart);
					cout << i << endl;
				}


				walls = level.level1Wall("textures/wall.png");
				ladders = level.level1Ladder("textures/ladder.png");
				enemys = level.level1Enemy("textures/enemy.png");
				keys = level.level1Key("textures/key.png");
				powers = level.level1PowerUps("textures/powerUp.png");

				player.resetKey();
				player.setPos({ 2 * gridSize,23 * gridSize });

				for (auto& enemy : enemys)
				{
					enemyAnimation.initAnimation(enemy.getTexture(), 2, 4, 0.200);
				}

				backgroundTexture.loadFromFile("textures/background.png");
				background.setTexture(backgroundTexture);
				background.setTextureRect({ 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT});

				escape.setPos({ gridSize * 46,gridSize * 5 });
				escape.initTexture("textures/door.png");

				next = false;

				break;


				//case level2
			case 2:

				walls.clear();
				ladders.clear();
				enemys.clear();
				keys.clear();

				player.resetKey();
				player.setPos({ 1 * gridSize,22 * gridSize });


				walls = level.level2Wall("textures/wall_lv2.png");
				ladders = level.level2Ladder("textures/ladder.png");
				enemys = level.level2Enemy("textures/enemy.png");
				keys = level.level2Key("textures/key.png");

				backgroundTexture.loadFromFile("textures/background_lv2.png");
				background.setTexture(backgroundTexture);
				background.setTextureRect({ 0, 0, WINDOW_WIDTH * 10, WINDOW_HEIGHT * 10 });

				escape.setPos({ gridSize * 25,gridSize * 25 });
				escape.initTexture("textures/door.png");


				next = false;

				break;

				//case level3
			case 3:

				walls.clear();
				ladders.clear();
				enemys.clear();
				keys.clear();

				walls = level.level1Wall("textures/wall.png");
				ladders = level.level1Ladder("textures/ladder.png");
				enemys = level.level1Enemy("textures/enemy.png");
				keys = level.level1Key("textures/key.png");
				powers = level.level1PowerUps("textures/powerUp.png");

				player.resetKey();
				player.setPos({ 2 * gridSize,23 * gridSize });

				for (auto& enemy : enemys)
				{
					enemyAnimation.initAnimation(enemy.getTexture(), 2, 4, 0.200);
				}

				backgroundTexture.loadFromFile("textures/background.png");
				background.setTexture(backgroundTexture);
				background.setTextureRect({ 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT });

				escape.setPos({ gridSize * 46,gridSize * 5 });
				escape.initTexture("textures/door.png");

				next = false;

				break;
			}
		}
		//menu
		if (select == 0)
		{
			//mouse posision

			mousePos = Mouse::getPosition();

			mouse.left = mousePos.x;
			mouse.top = mousePos.y;
			mouse.width = 1;
			mouse.height = 1;


			switch (menuSelect)
			{
				//case main menu
			case 1:
				start.setTexture(&buttonsTexture);
				start.setTextureRect({ 975,0,488,152 });
				difficulty.setTexture(&buttonsTexture);
				difficulty.setTextureRect({ 1954,0,488,152 });
				exit.setTexture(&buttonsTexture);
				exit.setTextureRect({ 0,0,488,152 });

				if (mouse.intersects(start.getGlobalBounds()))
				{
					start.setTextureRect({ 1463,0,488,152 });
				}
				
				if (mouse.intersects(difficulty.getGlobalBounds()))
				{
					difficulty.setTextureRect({ 2440,0,488,152 });
				}
					
				if (mouse.intersects(exit.getGlobalBounds()))
				{
					exit.setTextureRect({ 487,0,488,152 });
				}
					

				if (Mouse::isButtonPressed(Mouse::Left) && mouse.intersects(start.getGlobalBounds()))
				{
					select++;
					next = true;
				}

				if (Mouse::isButtonPressed(Mouse::Left) && mouse.intersects(difficulty.getGlobalBounds()))
				{
					menuSelect = 2;
					next = true;
				}

				if (Mouse::isButtonPressed(Mouse::Left) && mouse.intersects(exit.getGlobalBounds()))
				{
					window.close();
				}


				break;

				//menu difficulty
			case 2:
				easy.setTexture(&buttonsDifficultyTexture);
				easy.setTextureRect({ 0,0,488,152 });
				normal.setTexture(&buttonsDifficultyTexture);
				normal.setTextureRect({ 975,0,488,152 });
				hardcore.setTexture(&buttonsDifficultyTexture);
				hardcore.setTextureRect({ 1952,0,488,152 });
				back.setTexture(&buttonsDifficultyTexture);
				back.setTextureRect({ 2929,0,488,152 });
				if (player.getLifes() == 10)
				{
					easy.setTextureRect({ 488,0,488,152 });
				}

				if (player.getLifes() == 3)
				{
					normal.setTextureRect({ 975,0,488,152 });
				}

				if (player.getLifes() == 1)
				{
					hardcore.setTextureRect({ 2440,0,488,152 });
				}

				if (mouse.intersects(easy.getGlobalBounds()))
				{
					easy.setTextureRect({ 488,0,488,152 });
				}

				if (mouse.intersects(normal.getGlobalBounds()))
				{
					normal.setTextureRect({ 1463,0,488,152 });
				}

				if (mouse.intersects(hardcore.getGlobalBounds()))
				{
					hardcore.setTextureRect({ 2440,0,488,152 });
				}

				if (mouse.intersects(back.getGlobalBounds()))
				{
					back.setTextureRect({ 3417,0,488,152 });
				}
			


				if (Mouse::isButtonPressed(Mouse::Left) && mouse.intersects(easy.getGlobalBounds()))
				{
					player.setLifes(10);
				}

				if (Mouse::isButtonPressed(Mouse::Left) && mouse.intersects(normal.getGlobalBounds()))
				{
					player.setLifes(3);
				}

				if (Mouse::isButtonPressed(Mouse::Left) && mouse.intersects(hardcore.getGlobalBounds()))
				{
					player.setLifes(1);
				}

				if (Mouse::isButtonPressed(Mouse::Left) && mouse.intersects(back.getGlobalBounds()))
				{
					menuSelect = 1;
					next = true;
				}


				break;



			}
		}

		//movement
		velocity.x = 0.f;
		velocity.y = 0.f;

		//if player is on the ladder and pessing "w" he climb ladder
		if (Keyboard::isKeyPressed(Keyboard::W) && onLadder && canPlayerMove)
		{
			onGround = true;
			velocity.y += -moveSpeed * dt;
		}

		//if player is not on the ladder and pessing "w" he start jumping
		if (Keyboard::isKeyPressed(Keyboard::W) && !onLadder && canPlayerMove)
		{

			//jump

			//if player is on the ground he can jump
			if (onGround)
			{
				isPlayerJumping.restart();
				jump = true;
			}

			//if player can jump and is not falling we add velocity to player
			if (jump && !isFalling)
			{
				velocity.y += -moveSpeed * dt;
			}

			//if player is in the air longer than 500ms he cant jump and is falling
			if (isPlayerJumping.getElapsedTime().asMilliseconds() >= 500)
			{
				jump = false;
				isFalling = true;
			}

			//if player is in air less than 20ms he can jump
			if (isPlayerJumping.getElapsedTime().asMilliseconds() < 20)
			{
				jump = true;
			}

			//if player is falling he is falling
			if (isFalling)
			{
				velocity.y += moveSpeed * dt;
			}
			onGround = false;
		}

		//if player no longer pessing "w" key player start to falling
		else
		{
			isFalling = true;
			jump = true;

			//if player is not on the ladder player is falling
			if (!onLadder)
			{
				velocity.y += moveSpeed * dt;
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::A) && canPlayerMove)
		{
			velocity.x += -moveSpeed * dt;
			way = 1;
			animation.update(dt, way);
			player.animationTexture(animation.textureRect);
			
		}
		if (Keyboard::isKeyPressed(Keyboard::D) && canPlayerMove)
		{
			velocity.x += moveSpeed * dt;
			way = 0;
			animation.update(dt, way);
			player.animationTexture(animation.textureRect);
		}
		if (Keyboard::isKeyPressed(Keyboard::S) && canPlayerMove)
		{
			velocity.y += moveSpeed * dt;
		}

		animation.update(dt, way);
		player.animationTexture(animation.textureRect);

		//Collision
		for (auto& wall : walls)
		{
			FloatRect playerBounds = player.getGlobalBounds();
			FloatRect wallBounds = wall.getGlobalBounds();

			nextPos = playerBounds;
			nextPos.left += velocity.x;
			nextPos.top += velocity.y;



			//Collison with map
			if (wallBounds.intersects(nextPos))
			{
				//Bottom collision
				if (playerBounds.top < wallBounds.top
					&& playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
					&& playerBounds.left < wallBounds.left + wallBounds.width
					&& playerBounds.left + playerBounds.width > wallBounds.left
					)
				{
					//jump variables
					isFalling = false;
					onGround = true;

					//stop moving
					velocity.y = 0.f;
					player.setPos({ playerBounds.left, wallBounds.top - playerBounds.height });
				}

				//Top collision
				else if (playerBounds.top > wallBounds.top
					&& playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
					&& playerBounds.left < wallBounds.left + wallBounds.width
					&& playerBounds.left + playerBounds.width > wallBounds.left
					)
				{
					velocity.y = 0.f;
					player.setPos({ playerBounds.left, wallBounds.top + wallBounds.height });
				}

				//Right collision
				if (playerBounds.left < wallBounds.left
					&& playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
					&& playerBounds.top < wallBounds.top + wallBounds.height
					&& playerBounds.top + playerBounds.height > wallBounds.top
					)
				{
					velocity.x = 0.f;
					player.setPos({ wallBounds.left - playerBounds.width, playerBounds.top });
				}

				//Left collision
				else if (playerBounds.left > wallBounds.left
					&& playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
					&& playerBounds.top < wallBounds.top + wallBounds.height
					&& playerBounds.top + playerBounds.height > wallBounds.top
					)
				{
					velocity.x = 0.f;
					player.setPos({ wallBounds.left + wallBounds.width, playerBounds.top });
				}
			}
		}

		//Collison with enemy 
		for (auto& enemy : enemys)
		{
			//enemy movement
			enemy.movement();

			//enemy animation
			if (enemy.getDirection())
			{
				enemyAnimation.update(dt, 0);
				enemy.animationTexture(enemyAnimation.textureRect);
			}
			else
			{
				enemyAnimation.update(dt, 1);
				enemy.animationTexture(enemyAnimation.textureRect);
				
			}
			

			//Collison with enemy 
			if (enemy.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				player.setPos({ gridSize, 25 * gridSize });
				player.minusLife();
				hearts.pop_back();
			}
		}


		//Collison with ladder
		for (auto& ladder : ladders)
		{
			if (ladder.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				onLadder = true;
				break;
			}
			else
			{
				onLadder = false;
			}
		}

		//Collison with key
		for (auto& key : keys)
		{
			if (key.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				player.addKey();
				keys.erase(keys.begin() + key.getId());
			}
		}


		//Collision with escape
		if (escape.getGlobalBounds().intersects(player.getGlobalBounds()) && keys.size() == 0 && select != 0)
		{
			player.setPos({ gridSize, 25 * gridSize });
			select++;
			next = true;
		}

		//power ups logic
		for (auto& power : powers)
		{
			if (power.getGlobalBounds().intersects(player.getGlobalBounds()))
			{
				currentPower = (powerUpClock.getElapsedTime().asMilliseconds() % 2) + 1;
				powers.erase(powers.begin() + power.getId());
				powerUpClock.restart();
			}
		}

		if (currentPower == 1)
		{
			heart.setPos({ (player.getLifes()*1.f) * gridSize, 0 });
			heart.initTexture("textures/heart.png");
			hearts.push_back(heart);
			player.addLife();
			currentPower = 0;
		}

		if (currentPower == 2 && powerUpClock.getElapsedTime().asMilliseconds() < 5000)
		{
			boost = 1.5;
		}
		else
		{
			currentPower = 0;
			boost = 1;
		}


		//player move

		velocity.x = velocity.x * boost;
		velocity.y = velocity.y * boost;

		player.move(velocity);

		//Collision with screen
		//Left collision
		if (player.getPos().x < 0.f)
		{
			player.setPos({ 0.f, player.getPos().y });
		}
		//Top collision
		if (player.getPos().y < 0.f)
		{
			player.setPos({ player.getPos().x, 0.f });
		}
		//Right collision
		if (player.getPos().x + player.getGlobalBounds().width > WINDOW_WIDTH)
		{
			player.setPos({ WINDOW_WIDTH - player.getGlobalBounds().width, player.getPos().y });
		}
		//Bottom collision
		if (player.getPos().y + player.getGlobalBounds().height > WINDOW_HEIGHT)
		{
			player.setPos({ player.getPos().x, WINDOW_HEIGHT - player.getGlobalBounds().height });
		}

	
		

		//Render
		window.clear();

		window.draw(background);

		if (select != 0)
		{
			for (auto& power : powers)
			{
				power.DrawTo(window);
			}

			for (auto& wall : walls)
			{
				wall.DrawTo(window);
			}

			for (auto& ladder : ladders)
			{
				ladder.DrawTo(window);
			}

			for (auto& enemy : enemys)
			{
				enemy.DrawTo(window);
			}

			for (auto& key : keys)
			{
				key.DrawTo(window);
			}

			for (auto& heart : hearts)
			{
				heart.DrawTo(window);
			}

			escape.DrawTo(window);

			player.DrawTo(window);
		}
		else
		{
			switch (menuSelect)
			{
			case 1:
				window.draw(start);
				window.draw(difficulty);
				window.draw(exit);
				break;
			
			case 2:
				window.draw(easy);
				window.draw(normal);
				window.draw(hardcore);
				window.draw(back);
				break;
			}

		}

		//window.draw(text);

		window.display();
	}
	return 0;
}
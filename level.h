#pragma once

#include<iostream>
#include<cmath>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<SFML\System.hpp>
#include"enemy.h"
#include"player.h"
#include"wall.h"
#include"ladder.h"
#include"key.h"
#include"powerUps.h"

class level
{
public:
	level();
	std::vector<wall> level1Wall(std::string wallTexture);
	std::vector<ladder> level1Ladder(std::string ladderTexture);
	std::vector<enemy> level1Enemy(std::string enemyTexture);
	std::vector<key> level1Key(std::string keyTexture);
	std::vector<powerUps> level1PowerUps(std::string powerUpTexture);
	std::vector<wall> level2Wall(std::string wallTexture);
	std::vector<ladder> level2Ladder(std::string ladderTexture);
	std::vector<enemy> level2Enemy(std::string enemyTexture);
	std::vector<key> level2Key(std::string keyTexture);
	std::vector<wall> level3Wall(std::string wallTexture);
	std::vector<ladder> level3Ladder(std::string ladderTexture);
	std::vector<enemy> level3Enemy(std::string enemyTexture);
	std::vector<key> level3Key(std::string keyTexture);
};


#include "enemy.h"

Enemy::Enemy(std::string image_filepath) : Agent(100.0f)
{
	this->addSprite(image_filepath);
	this->sprite()->filter(0);
}

Enemy::~Enemy()
{

}

void Enemy::update(float deltaTime)
{
	Agent::update(deltaTime);
}

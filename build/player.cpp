/**
 * This class describes Player behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "player.h"

Player::Player() : Agent(100.0f)
{
	this->addSprite("assets/player-plane-64x32.tga");
	this->sprite()->filter(0);
}

Player::~Player()
{

}

void Player::update(float deltaTime)
{
	Agent::update(deltaTime);
	timer += deltaTime;
	if (timer >= 1.0f) {
		//std::cout << "Player health: " << getHealth() << std::endl;
		timer = 0.0f;
	}

	// ###############################################################
	// Movement with WASD
	// ###############################################################

	Vector2f velocity;

	if (input()->getKey(KeyCode::W) || input()->getKey(KeyCode::Up)) {
		velocity.y = -3.0f;
	}
	else if (input()->getKey(KeyCode::S) || input()->getKey(KeyCode::Down)) {
		velocity.y = 3.0f;
	}

	if (input()->getKey(KeyCode::A) || input()->getKey(KeyCode::Left)) {
		velocity.x = -3.0f;
	}
	else if (input()->getKey(KeyCode::D) || input()->getKey(KeyCode::Right)) {
		velocity.x = 3.0f;
	}

	if (input()->getKeyDown(KeyCode::R)) {
		rotation.z += PI / 4;
	}

	velocity.normalize();
	position += velocity * 600.0f * deltaTime;

	// ###############################################################
	// Keep player from leaving the screen
	// ###############################################################

	// Keep player from leaving screen (Right side)
	if (position.x >= SWIDTH * 0.7 - sprite()->width() / 2) {
		position.x = SWIDTH * 0.7 - sprite()->width() / 2;
	}
	// Keep player from leaving screen (Left side)
	else if (position.x <= SWIDTH * 0.3 + sprite()->width() / 2) {
		position.x = SWIDTH * 0.3 + sprite()->width() / 2;
	}

	// Keep player from leaving screen (Top side) WORKS
	if (position.y <= SHEIGHT * 1 / 7 + sprite()->height() / 2) {
		position.y = SHEIGHT * 1 / 7 + sprite()->height() / 2;
	}
	// Keep player from leaving screen (Bottom side) WORKS
	else if (position.y >= SHEIGHT * 6 / 7 - sprite()->height() / 2) {
		position.y = SHEIGHT * 6 / 7 - sprite()->height() / 2;
	}



	// ###############################################################
	// Shooting
	// ###############################################################

	shootingTimer += deltaTime;
	if (shootingTimer >= 0.1f) {
		canShoot = true;
	}

	if (input()->getKeyDown(KeyCode::Space)) {
		if (canShoot) {
			// reset cooldown variables.
			shootingTimer = 0.0f;
			canShoot = false;
			// Create bullet and spawn it on the player.
			Bullet* bullet = new Bullet(this);
			bullet->position = this->position - Point2(0, 35);
			bullet->rotation.z = this->rotation.z;

			// Add as child for rendering.
			this->parent()->addChild(bullet);
		}
	}
}

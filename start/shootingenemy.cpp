#include "shootingenemy.h"

ShootingEnemy::ShootingEnemy(Entity* target) : Enemy("assets/enemy_plane.tga")
{
	this->target_ = target;
	this->scale = Point2(2.0f, 2.0f);
	updateTargetPosition();
	updateTargetAngle();
	this->rotation.z = targetAngle + PI / 2;
	chargeDelay = (rand() % 100 + 70) / 100;
}



void ShootingEnemy::update(float deltaTime) {
	Enemy::update(deltaTime);

	// TODO Implement enemy that dives diagonally to the player, shoots once and leaves.

	if (isCharging) {
		updateTargetPosition();
		chargingTimer += deltaTime;
	}

	if (chargingTimer >= chargeDelay)
	{
		isCharging = false;
	}

	if (!isCharging && !isAtDestination)
	{
		MoveTowards(deltaTime, this);
	}

	if (roundf(this->position.x) == roundf(targetPosition.x) && roundf(this->position.y) == roundf(targetPosition.y)) {
		isCharging = false;
		isAtDestination = true;
		updateTargetPosition();
		updateTargetAngle();
		this->rotation.z = targetAngle + PI / 2;
		std::cout << "Target Angle to player from enemy: " << targetAngle << std::endl;
		Bullet* bullet = new Bullet(this);
		bullet->position = this->position;
		bullet->rotation.z = this->rotation.z;

		// Add as child for rendering.
		this->parent()->parent()->addChild(bullet);

	}

	timer += deltaTime;
	if (timer >= 1.0f)
	{
		timer = 0.0f;
	}

}

void ShootingEnemy::MoveTowards(float deltaTime, Entity* whatToMove) {
	// Calculate difference between player and enemy position.
	Vector2f delta = targetPosition - whatToMove->position;
	// Normalize vector
	delta.normalize();

	// Update position
	whatToMove->position += delta * movementSpeed * deltaTime;
}

void ShootingEnemy::updateTargetPosition()
{
	targetPosition = target_->position;
}

void ShootingEnemy::updateTargetAngle()
{
	float deltaX = targetPosition.x - this->position.x;
	float deltaY = targetPosition.y - this->position.y;

	targetAngle = atan2(deltaY, deltaX);
}


void ShootingEnemy::ReturnOffscreen() 
{

}

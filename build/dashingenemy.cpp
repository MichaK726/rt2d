#include "dashingenemy.h"

DashingEnemy::DashingEnemy(Entity* target) : Enemy("assets/enemy_plane.tga")
{
	this->target_ = target;
	this->scale = Point2(2.0f, 2.0f);
	updateTargetPosition();
	updateTargetAngle();
	this->rotation.z = targetAngle + PI / 2;
}



void DashingEnemy::update(float deltaTime) {
	Enemy::update(deltaTime);

	if (target_ != nullptr) {

		// TODO Implement enemy that dives diagonally to the player, shoots once and leaves.
		if (isCharging)
		{
			chargingTimer += deltaTime;
			this->rotation.z = targetAngle + PI / 2;
		}

		if (chargingTimer >= chargeDelay)
		{
			isCharging = false;
			chargingTimer = 0.0f;
		}

		if (!isCharging)
		{
			MoveTowards(deltaTime);
		}

		if (roundf(this->position.x) == roundf(targetPosition.x) && roundf(this->position.y) == roundf(targetPosition.y)) {
			updateTargetPosition();
			updateTargetAngle();
			isCharging = true;
		}

		timer += deltaTime;
		if (timer >= 1.0f)
		{
			timer = 0.0f;
		}
	}

}

void DashingEnemy::MoveTowards(float deltaTime) {
	// Calculate difference between player and enemy position.
	Vector2f delta = targetPosition - this->position;
	// Normalize vector
	delta.normalize();

	// Update position
	this->position += delta * movementSpeed * deltaTime;
}

void DashingEnemy::updateTargetPosition()
{
	targetPosition = target_->position;
}

void DashingEnemy::updateTargetAngle()
{
	float deltaX = targetPosition.x - this->position.x;
	float deltaY = targetPosition.y - this->position.y;

	targetAngle = atan2(deltaY, deltaX);
}


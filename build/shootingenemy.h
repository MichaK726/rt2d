#pragma once
#include "enemy.h"
#include "bullet.h"
#include "gamescene.h"

class ShootingEnemy : public Enemy
{
public:
	ShootingEnemy(Entity* target);

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	void update(float deltaTime);

	void updateTargetPosition();

	void updateTargetAngle();

	void MoveTowards(float deltaTime, Entity* whatToMove);

	void ReturnOffscreen();
private:
	/// @brief Movement speed of the enemy.
	float movementSpeed = 300.0f;
	/// @brief The target that the enemy is following.
	Entity* target_;
	/// @brief The last known position for the enemy of the target.
	Point3 targetPosition;
	/// @brief The last known angle for the enemy of the target.
	float targetAngle;

	Point3 ReturnPosition;

	float timer = 0.0f;

	float chargingTimer = 0.0f;
	bool isCharging = true;
	float chargeDelay = 0.8f;

	bool isAtDestination = false;


};


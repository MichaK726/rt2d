/**
 * Copyright 2024 Micha Koster <mm.koster@student.alfa-college.nl>
 *
 * @file bullet.h
 *
 * @brief The Bullet class is the class for all bullet-type projectiles in the game. The Bullet class extends from Entity.
 */

#ifndef BULLET_H
#define BULLET_H

#include <rt2d/entity.h>

 /// @brief The Bullet class is the class for all bullet-type projectiles in the game. The Bullet class extends from Entity.
class Bullet : public Entity
{
public:
	/// @brief Constructor
	Bullet(Entity* owner, float damage = 100.0f, std::string image_filepath = "assets/player_bullet.tga");

	/// @brief Destructor
	virtual ~Bullet();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);


	/// @brief This method gets the movementSpeed of the bullet.
	/// @return float
	float getMovementSpeed() { return movementSpeed; };

	/// @brief This method sets the movementSpeed of the bullet.
	/// @param This is the value to set movementSpeed to.
	/// @return void
	void setMovementSpeed(float movementSpeed) { this->movementSpeed = movementSpeed; };


	// TODO Rename to hasCollided
	void setIsDead(bool isDead) { this->isDead = isDead; };
	bool getIsDead() { return isDead; };

	bool isOffscreen();

	/// @brief This method returns the damage of a bullet.
	/// @return float : damage
	float getDamage() { return damage; };

	Entity* getOwner() { return owner; };
private:
	/// @brief This is the movement speed of the plane.
	float movementSpeed = 500.0f;
	bool isDead = false;
	float damage;
	Entity* owner;

};

#endif /* BULLET_H */


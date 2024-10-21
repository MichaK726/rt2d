/**
 * Copyright 2024 Micha Koster <mm.koster@student.alfa-college.nl>
 *
 * @file agent.h
 *
 * @brief This class functions as an in-between class between the entities and players/enemies. This class is just a entity class with added template functions for health-management.
 */

#ifndef AGENT_H
#define AGENT_H

#include <rt2d/entity.h>

 /// @brief This class functions as an in-between class between the entities and players/enemies. This class is just a entity class with added template functions for health-management. This class inherits from Entity.
class Agent : public Entity
{
public:
	/// @brief Constructor
	/// @param health sets the health_ float.
	Agent(float health);

	/// @brief TakeDamage subtracts float damage from float health_
	/// @param damage is the amount of damage to subtract from health
	/// @return void
	void takeDamage(float damage);

	/// @brief getHealth returns the private float health_
	/// @return float
	float getHealth() { return health_; };

	// @brief This functions returns if an agent is dead.
	// @return Bool : isDead
	bool getIsDead() { return isDead; };

	// @brief
	void setIsDead(bool isDead) { this->isDead = isDead; };

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	void update(float deltaTime);

private:
	/// The health of the Agent object.
	float health_;
	bool isDead = false;
};


#endif /* AGENT_H */

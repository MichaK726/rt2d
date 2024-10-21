/**
 * Copyright 2024 Micha Koster <mm.koster@student.alfa-college.nl>
 *
 * @file player.h
 *
 * @brief The Player class is het class used for the player in the game. The Player class inherits from Agent (so the health etc. is already implemented.)
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "agent.h"
#include "bullet.h"

 /// @brief The Player class is het class used for the player in the game. The Player class inherits from Agent (so the health etc. is already implemented.)
class Player : public Agent
{
public:
	/// @brief Constructor
	Player();

	/// @brief Destructor
	virtual ~Player();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief This is a timer variable for a one second timer, used for printing debug statements.
	float timer = 0.0f;

	/// @brief This is the timer for when the player is allowed to shoot again.
	float shootingTimer = 0.0f;

	bool canShoot = true;
};

#endif /* PLAYER_H */

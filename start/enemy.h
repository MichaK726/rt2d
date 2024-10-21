/**
 * Copyright 2024 Micha Koster <mm.koster@student.alfa-college.nl>
 *
 * @file enemy.h
 *
 * @brief The Enemy class is het class used for the enemies in the game. The Enemy class inherits from Agent (so the health etc. is already implemented.)
 */

#ifndef ENEMY_H
#define ENEMY_H

#include "agent.h"

 /// @brief The Enemy class is het class used for the enemies in the game. The Enemy class inherits from Agent (so the health etc. is already implemented.)
class Enemy : public Agent
{
public:
	/// @brief Constructor
	Enemy(std::string image_filepath);

	/// @brief Destructor
	virtual ~Enemy();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
private:

};

#endif /* ENEMY_H */

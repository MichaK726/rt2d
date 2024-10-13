/**
 * Copyright 2024 Micha Koster <mm.koster@student.alfa-college.nl>
 *
 * @file gamescene.h
 *
 * @brief This class is the main game.
 */

#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <rt2d/scene.h>

#include "background.h"
#include "image.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "dashingenemy.h"
#include "shootingenemy.h"

 /// @brief The GameScene class is the Scene implementation.
class GameScene : public Scene
{
public:
	/// @brief Constructor
	GameScene();

	/// @brief Destructor
	virtual ~GameScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	/// @brief setDifficultyIndex updates the difficulty of the game.
	/// @param difficulty_to_set: This is the value to set difficulty_index to.
	void setDifficultyIndex(int difficulty_to_set) { this->difficulty_index = difficulty_to_set; };

	void calculateCollisions();

private:
	// @brief player character
	Player* player;
	// @brief The background
	Background* background;

	/// @brief This determines the difficulty of the game that the user has selected.
	int difficulty_index;

	/// @brief This is a timer variable for a one second timer, used for printing debug statements.
	float debugTimer = 0.0f;


};

#endif /* GAMESCENE_H */

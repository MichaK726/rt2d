#pragma once

#include "entity.h"
#include "enemy.h"
#include "dashingenemy.h"
#include "shootingenemy.h"

class WaveSpawner : Entity
{
public:
	/// @brief Constructor
	WaveSpawner();

	/// @brief Destructor
	~WaveSpawner();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	void update(float deltaTime);
private:
	std::vector<std::vector<Enemy*>> waves;
	bool isSpawning;

	float spawnTimer = 0.0f;
};


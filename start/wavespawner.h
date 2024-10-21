#pragma once

#include "entity.h"
#include "enemy.h"
#include "dashingenemy.h"
#include "shootingenemy.h"
#include <chrono>
#include <thread>

class WaveSpawner : public Entity
{
public:
	/// @brief Constructor
	WaveSpawner(Entity* target);

	/// @brief Destructor
	~WaveSpawner();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	void update(float deltaTime);

	void SpawnEnemy();
private:
	std::vector<std::vector<Enemy*>> waves;

	float spawnTimer = 0.0f;

	Entity* target_;

	int currentWaveIndex = 0;
	int currentEnemyIndex = 0;

	float spawnDelay = 2.0f;
	std::chrono::steady_clock::time_point lastSpawnTime;

};


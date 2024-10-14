#include "wavespawner.h"

WaveSpawner::WaveSpawner() {

	// Initialize Waves

	std::vector<Enemy*> wave1;
	for (int i = 0; i < 10; i++) {
		DashingEnemy* enemy = new DashingEnemy();
		enemy->position.x = 25 * i;
		wave1.push_back(enemy);
	}
}

WaveSpawner::~WaveSpawner() {

}

void WaveSpawner::update(float deltaTime) 
{
	spawnTimer += deltaTime;
	if (spawnTimer <= 2.5f) {
		
	}

}
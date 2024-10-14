#include "wavespawner.h"
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds


WaveSpawner::WaveSpawner(Entity* target) {

	this->target_ = target;

	// Initialize Waves

    std::vector<Enemy*> wave1;
    std::vector<Enemy*> wave2;

	for (int i = 0; i < 10; i++) {
		ShootingEnemy* enemy = new ShootingEnemy(target_);
		enemy->position.x = 25 * i;
		wave1.push_back(enemy);
	}

    for (int i = 0; i < 10; i++) {
        ShootingEnemy* enemy = new ShootingEnemy(target_);
        enemy->position.x = 25 * i;
        wave2.push_back(enemy);
    }
	waves.push_back(wave1);
    waves.push_back(wave2);
}

WaveSpawner::~WaveSpawner() {

}

void WaveSpawner::update(float deltaTime) 
{
    // Check if all waves are complete
    if (currentWaveIndex >= waves.size()) {
        std::cout << "All waves complete!" << std::endl;
        return;
    }

    // Check if enough time has passed since the last spawn
    auto currentTime = std::chrono::steady_clock::now();
    std::chrono::duration<float> elapsed = currentTime - lastSpawnTime;

    if (elapsed.count() >= spawnDelay) {
        SpawnEnemy();
        lastSpawnTime = currentTime;  // Reset the timer
    }
}

void WaveSpawner::SpawnEnemy() {
    // Check if we've spawned all enemies in the current wave
    if (currentEnemyIndex >= waves[currentWaveIndex].size()) {
        // Move to the next wave
        currentWaveIndex++;
        // Reset Enemy Index
        currentEnemyIndex = 0;
        // Print New Wave
        std::cout << "Moving to wave " << currentWaveIndex + 1 << std::endl;
    }

    // Check if there are more waves to process
    if (currentWaveIndex < waves.size()) {
        // Add Current Enemy to scene
        this->parent()->addChild(waves[currentWaveIndex][currentEnemyIndex]);
        // Move to the next enemy
        currentEnemyIndex++;
    }

    std::cout << "Current Enemy Index: " << currentEnemyIndex << std::endl;
    std::cout << "Current Wave Index: " << currentWaveIndex << std::endl;
    std::cout << "Current Wave Size: " << waves[currentWaveIndex].size() << std::endl;
    std::cout << "Total amount of waves: " << waves.size() << std::endl;
}
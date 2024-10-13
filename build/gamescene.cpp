#include <fstream>
#include <sstream>

#include "gamescene.h"
using namespace std;

GameScene::GameScene() : Scene()
{
	player = new Player();

	background = new Background();

	// create the scene 'tree'
	// add player to this Scene as a child.
	this->addChild(background);
	this->addChild(player);
}


GameScene::~GameScene()
{
	// deconstruct and delete the Tree
	this->removeChild(player);
	this->removeChild(background);

	// delete player from the heap (there was a 'new' in the constructor)
	delete player;
	delete background;
}

void GameScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################

	if (input()->getKeyUp(KeyCode::Escape))
	{
		this->stop();
	}

	if (player != nullptr) {
		// ###############################################################
		// Timers
		// ###############################################################

		debugTimer += deltaTime;
		if (debugTimer >= 1.0f) {
			debugTimer = 0.0f;
		}

		// This code spawns an enemy at the position of the player. DEBUG ONLY
		if (input()->getKeyDown(KeyCode::P)) {
			// Create enemy and spawn it on the player
			DashingEnemy* enemy = new DashingEnemy(player);
			enemy->position = player->position + Vector2f(100, 100);

			// Add as child for rendering.
			this->addChild(enemy);
		}

		// This code spawns an enemy at the position of the player. DEBUG ONLY
		if (input()->getKeyDown(KeyCode::O)) {
			// Create enemy and spawn it on the player
			ShootingEnemy* enemy = new ShootingEnemy(player);
			enemy->position = player->position + Vector2f(100, 100);

			// Add as child for rendering.
			this->addChild(enemy);
		}

		// ###############################################################
		// Collision
		// ###############################################################

		calculateCollisions();

		// ###############################################################
		// Deleting "Dead" objects
		// ###############################################################

		if (player->getIsDead() == true)
		{
			player = nullptr;
		}
	}

}

/// Loop through all enemies and all bullets to see if are colliding.
// TODO Also check for collision between player and enemy and player and bullets
void GameScene::calculateCollisions() {
	for (int i = 0; i < children().size(); i++)
	{
		for (int j = 0; j < children().size(); j++)
		{
			Bullet* currentBullet = dynamic_cast<Bullet*>(children()[i]);
			Enemy* currentEnemy = dynamic_cast<Enemy*>(children()[j]);
			if (currentBullet && currentEnemy) {
				if (currentBullet->getOwner() == currentEnemy)
				{
					continue;
				}
				Sprite* currentBulletSprite = currentBullet->sprite();
				Sprite* currentEnemySprite = currentEnemy->sprite();
				if (
					/// Collision on the left
					currentBullet->position.x + currentBullet->sprite()->width() / 2 * currentBullet->scale.x > currentEnemy->position.x - currentEnemy->sprite()->width() / 2 * currentEnemy->scale.x
					/// Collision on the right
					&& currentBullet->position.x - currentBullet->sprite()->width() / 2 * currentBullet->scale.x < currentEnemy->position.x + currentEnemy->sprite()->width() / 2 * currentEnemy->scale.x
					/// Collision on the bottom
					&& currentBullet->position.y + currentBullet->sprite()->height() / 2 * currentBullet->scale.y > currentEnemy->position.y - currentEnemy->sprite()->height() / 2 * currentEnemy->scale.y
					/// Collision on the top
					&& currentBullet->position.y - currentBullet->sprite()->height() / 2 * currentBullet->scale.y < currentEnemy->position.y + currentEnemy->sprite()->height() / 2 * currentEnemy->scale.y
					)
				{
					std::cout << "Enemy colliding with bullet" << std::endl;
					currentEnemy->takeDamage(currentBullet->getDamage());
					currentBullet->setIsDead(true);
				}
			}
		}
	}

	for (int i = 0; i < children().size(); i++)
	{
		Enemy* currentEnemy = dynamic_cast<Enemy*>(children()[i]);

		if (player && currentEnemy) {
			Sprite* currentEnemySprite = currentEnemy->sprite();
			if (
				/// Collision on the left
				player->position.x + player->sprite()->width() / 2 * player->scale.x > currentEnemy->position.x - currentEnemy->sprite()->width() / 2 * currentEnemy->scale.x
				/// Collision on the right
				&& player->position.x - player->sprite()->width() / 2 * player->scale.x < currentEnemy->position.x + currentEnemy->sprite()->width() / 2 * currentEnemy->scale.x
				/// Collision on the bottom
				&& player->position.y + player->sprite()->height() / 2 * player->scale.y > currentEnemy->position.y - currentEnemy->sprite()->height() / 2 * currentEnemy->scale.y
				/// Collision on the top
				&& player->position.y - player->sprite()->height() / 2 * player->scale.y < currentEnemy->position.y + currentEnemy->sprite()->height() / 2 * currentEnemy->scale.y
				)
			{
				player->takeDamage(100.0f);
				currentEnemy->takeDamage(100.0f);
			}
		}
	}

	for (int i = 0; i < children().size(); i++)
	{
		Bullet* currentBullet = dynamic_cast<Bullet*>(children()[i]);

		if (player && currentBullet) {
			if (currentBullet->getOwner() == player)
			{
				continue;
			}
			Sprite* currentEnemySprite = currentBullet->sprite();
			if (
				/// Collision on the left
				player->position.x + player->sprite()->width() / 2 * player->scale.x > currentBullet->position.x - currentBullet->sprite()->width() / 2 * currentBullet->scale.x
				/// Collision on the right
				&& player->position.x - player->sprite()->width() / 2 * player->scale.x < currentBullet->position.x + currentBullet->sprite()->width() / 2 * currentBullet->scale.x
				/// Collision on the bottom
				&& player->position.y + player->sprite()->height() / 2 * player->scale.y > currentBullet->position.y - currentBullet->sprite()->height() / 2 * currentBullet->scale.y
				/// Collision on the top
				&& player->position.y - player->sprite()->height() / 2 * player->scale.y < currentBullet->position.y + currentBullet->sprite()->height() / 2 * currentBullet->scale.y
				)
			{
				player->takeDamage(100.0f);
				currentBullet->setIsDead(true);
			}
		}
	}
}
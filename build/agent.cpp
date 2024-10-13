#include "Agent.h"

Agent::Agent(float health) : Entity() {
	health_ = health;
}

void Agent::takeDamage(float damage)
{
	health_ -= damage;

	if (health_ < 0) health_ = 0;
}

void Agent::update(float deltaTime) {
	if (health_ <= 0.0f) {
		isDead = true;
	}

	if (isDead) {
		this->parent()->removeChild(this);
	}
}



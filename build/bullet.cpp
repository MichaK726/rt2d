#include "bullet.h"

Bullet::Bullet(Entity* owner, float damage, std::string image_filepath)
{
	this->damage = damage;
	addSprite(image_filepath);
	this->sprite()->filter(0);
	this->scale = Point2(2.0f, 2.0f);
	this->owner = owner;
}

Bullet::~Bullet()
{

}

void Bullet::update(float deltaTime)
{
	if (isOffscreen() == true || getIsDead() == true) {
		this->parent()->removeChild(this);
	}
	position += Vector2(cos(rotation.z - PI / 2.0f), (sin(rotation.z - PI / 2.0f))) * deltaTime * movementSpeed;
}

bool Bullet::isOffscreen() {
	/// Check if moving up or down

	// Moving Down
	if ((sin(rotation.z - PI / 2.0f)) > 0.0f) {
		if (position.y > SHEIGHT) {
			return true;
		}
	}

	// Moving Up
	else if (sin(rotation.z - PI / 2.0f) < 0.0f) {
		if (position.y < 0.0f) {
			return true;
		}
	}

	/// Check if moving left or right

	// Moving Right
	if ((cos(rotation.z - PI / 2.0f)) > 0.0f) {
		if (position.x > SWIDTH / 2.0f + 256.0f) {
			return true;
		}
	}

	// Moving Left
	else if (cos(rotation.z - PI / 2.0f) < 0.0f) {
		if (position.x < SWIDTH / 2.0f - 256.0f) {
			return true;
		}
	}

	return false;
}
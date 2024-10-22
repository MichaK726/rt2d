/**
 * This class describes Background behavior.
 *
 * Copyright 2024 Micha Koster <mm.koster@student.alfa-college.nl>
 */

#include "background.h"

Background::Background() : Entity()
{
	this->addSprite("assets/background-stage-1.tga");
	this->sprite()->color = WHITE;
	this->position = Point2(SWIDTH / 2, -2160.0f + 720.0f);
	this->sprite()->filter(0);
	this->scale = Point2(2.0f, 2.0f);
}

Background::~Background()
{

}

void Background::update(float deltaTime)
{
	if (scrolling_)
	{
		this->position.y += 40.0f * deltaTime;
		if (position.y >= 2160.0f) {
			scrolling_ = false;
			position.y = 2160.0f;
		}
	}
}
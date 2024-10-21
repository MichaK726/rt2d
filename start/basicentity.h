/**
 * Copyright 2024 Micha Koster <mm.koster@student.alfa-college.nl>
 *
 * @file basicentity.h
 *
 * @brief This class is just an empty entity, just so you can instance empty entity (You can't directly instance Entity, because it is an abstract class). The BasicEntity class inherits from Entity.
 */

#ifndef BASICENTITY_H
#define BASICENTITY_H

#include <rt2d/entity.h>
 /// @brief This class is just an empty entity, just so you can instance an empty entity (You can't directly instance Entity, because it is an abstract class). The BasicEntity class inherits from Entity.
class BasicEntity : public Entity
{
public:
	/// @brief Constructor
	BasicEntity();

	/// @brief Destructor
	virtual ~BasicEntity();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:

};

#endif /* BASICENTITY_H */


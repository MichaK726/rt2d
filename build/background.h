/**
 * Copyright 2024 Micha Koster <mm.koster@student.alfa-college.nl>
 *
 * @file background.h
 *
 * @brief The Background class controls the scrolling and sprite of the background. The Background class inherits from Entity.
 */

#ifndef Background_H
#define Background_H

#include <rt2d/entity.h>

 /// @brief The Background class controls the scrolling and sprite of the background. The Background class inherits from Entity.
class Background : public Entity
{
public:
	/// @brief Constructor
	Background();

	/// @brief Destructor
	virtual ~Background();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	/// @brief setScrolling set the value of scrolling_ (private) to scrolling. This controls scrolling of the background.
	/// @param scrolling: This is the value to set scrolling_ to.
	void setScrolling(bool scrolling) { this->scrolling_ = scrolling; };

	/// @brief getScrolling returns whether the background is scrolling or not.
	/// @return bool
	bool getScrolling() { return scrolling_; };

private:
	/// @brief This boolean value controls if the background is scrolling.
	bool scrolling_ = true;
};

#endif /* Background_H */
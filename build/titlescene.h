/**
 * Copyright 2024 Micha Koster <mm.koster@student.alfa-college.nl>
 *
 * @file titlescene.h
 *
 * @brief This class is the class for the title screen of the project.
 */

#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "image.h"
#include <rt2d/scene.h>
#include <rt2d/text.h>
#include "basicentity.h"

 /// @brief This class is the class for the title screen of the project.
class TitleScene : public Scene
{
public:
	/// @brief Constructor
	TitleScene();

	/// @brief Destructor
	virtual ~TitleScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	/// @brief isDifficultySelected returns if the difficulty is selected.
	/// @return bool
	bool isDifficultySelected() { return difficulty_selected; };

	/// @brief getDifficultyIndex returns the difficulty.
	/// @return int
	int getDifficultyIndex() { return index; };
private:
	/* Images */

	/// @brief Logo image
	Image* logo;
	/// @brief The image for the difficulty selector.
	Image* difficulty_selector;

	/* Text related stuff */

	/// @brief The parent of all the text elements.
	BasicEntity* textParent;
	/// @brief The vector that stores all the individual text strings.
	std::vector<std::string> text_characters;
	/// @brief The vector that stores all the individual text positions.
	std::vector<Point2> text_positions;
	/// @brief The vector that stores all the individual text colors.
	std::vector<RGBAColor> text_colors;

	/* Difficulty related stuff */

	/// @brief The index that the player is currently selecting as their difficulty.
	int index = 0;
	/// @brief This variable stores if the player has selected a difficulty.
	bool difficulty_selected = false;
};

#endif /* TITLESCENE_H */
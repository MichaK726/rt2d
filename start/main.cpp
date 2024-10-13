/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @brief Description of My Awesome Game.
 *
 * @file main.cpp
 *
 * @mainpage My Awesome Game
 *
 * @section intro Introduction
 *
 * Detailed description of My Awesome Game.
 *
 * There's even a second paragraph.
 */
#include <rt2d/core.h>

#include "titlescene.h"
#include "gamescene.h"

 /// @brief main entry point
int main(void)
{
	// Core instance
	Core core;

	// Scene01
	TitleScene* title_scene = new TitleScene(); // create Scene on the heap
	GameScene* game_scene = new GameScene();

	Scene* current_scene = title_scene;
	while (current_scene->isRunning()) { // check status of Scene every frame
		if (current_scene == title_scene) {
			if (title_scene->isDifficultySelected() == true) {
				int difficulty_index = title_scene->getDifficultyIndex();
				game_scene->setDifficultyIndex(difficulty_index);
				current_scene = game_scene;
			}
		}
		core.run(current_scene); // update and render the current scene
		core.showFrameRate(1); // show framerate in output every n seconds
	}
	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete title_scene; // delete Scene and everything in it from the heap to make space for next Scene

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}
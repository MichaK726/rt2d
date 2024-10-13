#include "titlescene.h"
#include <vector>
using namespace std;

TitleScene::TitleScene() : Scene()
{
	logo = new Image("assets/logo.tga", WHITE, Point2(SWIDTH / 2, SHEIGHT / 4));
	difficulty_selector = new Image("assets/player-plane.tga", WHITE, Point2(SWIDTH / 2 + 125, SHEIGHT / 2));
	difficulty_selector->scale = Point2(2.0f, 2.0f);
	difficulty_selector->sprite()->filter(0);
	textParent = new BasicEntity();

	// push text to array
	text_characters.push_back("Easy");
	text_characters.push_back("Medium");
	text_characters.push_back("Hard");
	text_characters.push_back("Made by Micha Koster");

	// push text_position to array
	for (int i = 0; i < 3; i++) {
		text_positions.push_back(Point2(SWIDTH / 2 - 50, SHEIGHT / 2 + i * 75));
	}
	text_positions.push_back(Point2(SWIDTH / 2 - 225, SHEIGHT - 75));

	// push text_colors to array
	text_colors.push_back(GREEN);
	text_colors.push_back(YELLOW);
	text_colors.push_back(RED);
	text_colors.push_back(WHITE);

	for (int i = 0; i < text_characters.size(); i++) {
		Text* text = new Text();
		text->message(text_characters[i], text_colors[i]);
		text->position = text_positions[i];
		text->scale = Point2(0.75f, 0.75f);
		textParent->addChild(text);
	}

	/// Add objects as child of the scene.
	this->addChild(logo);
	this->addChild(difficulty_selector);
	this->addChild(textParent);
}

TitleScene::~TitleScene()
{

}

void TitleScene::update(float deltaTime)
{
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################

	if (input()->getKeyUp(KeyCode::Escape))
	{
		this->stop();
	}

	// ###############################################################
	// Difficulty Selection
	// ###############################################################

	if (input()->getKeyUp(KeyCode::W) || input()->getKeyUp(KeyCode::Up) && index > 0) {
		difficulty_selector->position.y -= 75;
		index--;
	}
	else if (input()->getKeyUp(KeyCode::S) || input()->getKeyUp(KeyCode::Down) && index < 2) {
		difficulty_selector->position.y += 75;
		index++;
	}

	if (input()->getKeyUp(KeyCode::Enter)) {
		difficulty_selected = true;
	}
}
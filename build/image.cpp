#include "image.h"

Image::Image(std::string image_filepath, RGBAColor color, Point2 image_position, int filter) : Entity()
{
	addSprite(image_filepath);
	sprite()->color = color;
	position = image_position;
	sprite()->filter(filter);
}

void Image::update(float deltaTime)
{

}


/**
 * Copyright 2024 Micha Koster <mm.koster@student.alfa-college.nl>
 *
 * @file image.h
 *
 * @brief This class functions as an in-between class for "Entities" that only have their sprite set and do nothing else (think logo's etc)
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <rt2d/entity.h>

 /// @brief This class functions as an in-between class for "Entities" that only have their sprite set and do nothing else. This class inherits from Entity.
class Image : public Entity
{
public:
	/// @brief This is the constructor for the Image class.
	/// @param image_filepath: This takes the filepath to an image, this must be a .tga file.
	/// @param color: This takes a color. You can choose a predefined color like BLUE or WHITE, or give up your own RGBAColor values.
	/// @param image_position: This is the position where the image should be rendered, by default this is the middle of the screen.
	/// @param filter: This is the type of filter that should be applied. 0 = no filter; 1 = linear; 2 = bilinear; 3 = trilinear;
	/// @return N/A
	Image(std::string image_filepath, RGBAColor color, Point2 image_position = Point2(SWIDTH / 2, SHEIGHT / 2), int filter = 0);

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:

};

#endif /* IMAGE_H */


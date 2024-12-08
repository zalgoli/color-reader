#pragma once
#ifndef IMAGE_H
#define IMAGE_H

#define MAX_WIDTH 30
#define MAX_HEIGHT 30

#include "color.h"

typedef struct
{
	int w; // width
	int h; // height
	color** matrix;
} image;

color** create_matrix(int height, int width);
image create_image(color** mtx, int width, int height);
image read_image_from_file(const char* filename);

void image_print(image input_image);
void free_matrix(color** matrix, int height);


#endif
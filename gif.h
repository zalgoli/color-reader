#pragma once
#ifndef GIF_H
#define GIF_H

#include "image.h"

#define GIF_LENGTH 10

// It's pronounced 'gif' and not 'gif' :)
typedef struct
{
    image images[GIF_LENGTH];
} gif;

void print_gif(gif* input, int rep);
gif read_gif_from_files(char* file_prefix);

#endif

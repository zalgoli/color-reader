// Self-include
#include "gif.h"

// Standard library headers
#include <stdio.h>

// Project-specific headers
#include "image.h"

// System-specific headers
#include <windows.h>


// rep determines how many times the gif plays
void print_gif(gif* input, int rep)
{
    for (int j = 0; j < rep; j++)
    {
        for (int i = 0; i < GIF_LENGTH; i++)
        {
            system("cls");
            image_print(input->images[i]);
            Sleep(300);
        }
    }
}


gif read_gif_from_files(char* file_prefix)
{
    gif result = { 0 }; 

    for (int i = 0; i < GIF_LENGTH; i++)
    {
        char curr_file[50];
        // Building the name of the files, based on the file prefix, the count
        // and the ".bg" string in the middle
        sprintf_s(curr_file, sizeof(curr_file), "%s.bg%d", file_prefix, i);

        result.images[i] = read_image_from_file(curr_file);
    }

    return result;
}

// Standard includes
#include <stdlib.h>
#include <stdio.h>

// Project specific includes
#include "color.h"
#include "image.h"
#include "gif.h"

int main()
{
	int input;

	while (1)
	{
		printf("Input the number corresponding to your desired functionality\n");	
		printf("1: Printing all possible colors on the console\n");
		printf("2: Displaying 'input.txt' file's contents as an image\n");
		printf("3: Displaying an array of files' contents as a gif\n");
		printf("4: Exit the program\n");
		scanf_s("%d", &input);
		

		// 1. Gif fájlból
		if (input == 1)
		{
			for (int i = 0; i < 9; i++)
			{
				color_print(i);
			}
			printf("\n\n");
		}
		else if (input == 2)
		{
			image myImage = read_image_from_file("input.txt");
			image_print(myImage);
			printf("\n\n");
		}
		else if (input == 3)
		{
			gif myGif = read_gif_from_files("elteik"); // Change 'input' to 'elteik' for a surprise
			print_gif(&myGif, 2);
			printf("\n\n");
		}
		else if (input == 4)
		{
			break;
		}

	}

	return 0;
}
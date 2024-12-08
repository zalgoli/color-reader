// Self-include
#include "image.h"

// Standard library headers
#include <stdio.h>
#include <stdlib.h>

color** create_matrix(int width, int height)
{
    // Avoiding invalid matrix dimensions
    if (width > MAX_WIDTH || width < 1 || height > MAX_HEIGHT || height < 1)
    {
        fprintf(stderr, "Invalid matrix dimensions provided.\n");
        return NULL;
    }

    // Allocating memory
    color** matrix = malloc(height * sizeof(color*));
    if (!matrix)
    {
        fprintf(stderr, "Failed to allocate memory for matrix.\n");
    }
    for (int i = 0; i < height; i++)
    {   
        matrix[i] = malloc(width * sizeof(color));
        
        if (!matrix[i])
        {
            fprintf(stderr, "Failed to allocate memory for matrix rows.\n");
            while (--i >= 0) free(matrix[i]);
            free(matrix);
            return NULL;
        }
    }

    return matrix;
}

image create_image(color** mtx, int width, int height)
{
    image res;
    res.matrix = mtx;
    res.h = height;
    res.w = width;

    return res;
}

image read_image_from_file(const char* filename)
{

    // Empty image in case of early return
    image empty = (image){ .matrix = NULL, .w = 0, .h = 0 };

    FILE* file = fopen(filename, "r");
    if (!file)
    {
        fprintf(stderr, "Failed to open file.\n");
        return empty;
    }

    int width, height;
    fscanf_s(file, "%d", &width);
    fscanf_s(file, "%d", &height);

    if (width > MAX_WIDTH || width < 1 || height > MAX_HEIGHT || height < 1)
    {
        fprintf(stderr, "Invalid matrix dimensions provided.\n");
        return empty;
    }

    color** matrix = create_matrix(width, height);
    if (!matrix)
    {
        fclose(file);
        fprintf(stderr, "Failed to allocate memory for matrix.\n");
        return empty;
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fscanf_s(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);

    return create_image(matrix, width, height);
}

void free_matrix(color** matrix, int height)
{
    if (!matrix) return; // do nothing if matrix is NULL

    for (int i = 0; i < height; i++) {
        free(matrix[i]);
    }

    free(matrix); 
}


void image_print(image input_image) 
{
    for (int i = 0; i < input_image.h; i++)
    {
        for (int j = 0; j < input_image.w; j++)
        {
            color_print(input_image.matrix[i][j]);
        }
        printf("\n");
    }
}




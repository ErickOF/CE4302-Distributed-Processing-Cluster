#include "filter/image_processing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void slice_str(const char* str, char* buffer, size_t start, size_t end)
{
    size_t j = 0;

    for (size_t i = start; i <= end; i++)
    {
        buffer[j++] = str[i];
    }

    buffer[j] = 0;
}

int main(int argc, char **argv)
{
    // Images paths
    char* img_path = calloc(100, sizeof(char));
    char* img_output = (char*) calloc(14, sizeof(char));
    // Valid args
    int args = 0;

    for (int i = 1; i < argc; i += 2)
    {
        // Get image path
        if (strcmp(*(argv + i), "-in") == 0)
        {
            strcpy(img_path, *(argv + i + 1));
            args = 1;
        }
    }

    // Check args
    if (args == 0)
    {
        printf("La ruta de la imagen no fue ingresada\n");
        perror(0);
    }

    // Get output
    strcpy(img_output, "./output.\0");

    // Get extension
    char ext[4] = "\0\0\0\0";
    int len = strlen(img_path);
    slice_str(img_path, ext, len - 3, len - 1);

    // Set extension
    img_output = strcat(img_output, ext);

    // Processing image
    processImage(img_path, img_output);

    free(img_output);

    return 0;
}
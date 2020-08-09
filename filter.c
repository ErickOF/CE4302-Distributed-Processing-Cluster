//#include "filter/image_processing.h"
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

int main(int argc, char *argv[])
{
    // Get path
    char* img_path = "lena.png\0";
    printf("%s\n", img_path);
    // Get output
    char* img_output = (char*) calloc(14, sizeof(char));
    strcpy(img_output, "./output.\0");
    // Get extension
    char ext[4] = "\0\0\0\0";
    int len = strlen(img_path);
    printf("%i\n", len);
    slice_str(img_path, ext, len - 3, len - 1);
    printf("%s\n", ext);
    printf("Sliced\n");

    // Set extension
    img_output = strcat(img_output, ext);
    printf("%s\n", img_output);

    // Processing image
    //processImage(img_path, img_output);

    free(img_output);

    return 0;
}
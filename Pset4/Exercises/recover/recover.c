#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover [nameOfTheFile]\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Couldn't open the file\n");
        return 1;
    }

    BYTE *buffer = malloc(BLOCK_SIZE);
    if (buffer == NULL)
    {
        printf("Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    int imageCount = 1;
    FILE *img = NULL;

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, file))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If we already have an image file open, close it before creating a new one.
            if (img != NULL)
            {
                fclose(img);
            }

            char filename[8];
            sprintf(filename, "%03i.jpg", imageCount++);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Error opening the file\n");
                free(buffer);
                fclose(file);
                return 1;
            }
        }

        // If we have an open image file, write the buffer to it.
        if (img != NULL)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }

    // Close the last image file.
    if (img != NULL)
    {
        fclose(img);
    }

    free(buffer);
    fclose(file);

    return 0;
}
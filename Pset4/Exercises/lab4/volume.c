// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

//defining a variable type size of byte
typedef uint8_t BYTE;
typedef int16_t twoBYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);


    BYTE *buffer_header = malloc(sizeof(BYTE) * HEADER_SIZE);

    fread(buffer_header, sizeof(BYTE), HEADER_SIZE, input);
    fwrite(buffer_header, sizeof(BYTE), HEADER_SIZE, output);

    free(buffer_header);


    twoBYTE sample;

    while(fread(&sample, sizeof(twoBYTE), 1, input) == 1)
    {
        // Aplicando o fator de volume e limitando o valor entre -32768 e 32767
        int new_sample = (int)((float)sample * factor);
        if (new_sample > 32767)
            new_sample = 32767;
        else if (new_sample < -32768)
            new_sample = -32768;

        sample = (twoBYTE)new_sample;
        fwrite(&sample, sizeof(twoBYTE), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}

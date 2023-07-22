#include "helpers.h"
#include <stdio.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for(int i = 0; i < height; i++)
    {

        for(int j = 0; j < width; j++)
        {

            int media = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;

            image[i][j].rgbtRed = media;
            image[i][j].rgbtGreen = media;
            image[i][j].rgbtBlue = media;

        }

    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    BYTE red, green, blue;

    for(int i = 0; i < height; i++)
    {

        for(int j = 0; j < width / 2; j++)
        {

            //Get the current index values
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;


            //swap between elements horizontally
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][(width - 1) - j].rgbtRed = red;

            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][(width - 1) - j].rgbtGreen = green;

            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][(width - 1) - j].rgbtBlue = blue;

        }

    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    int pixelCount = 0;
    int red = 0, green = 0, blue = 0;

    for(int i = 0; i < height; i++)
    {

        for(int j = 0; j < width; j++)
        {

            //edge top case
            if(!(i - 1 < 0))
            {

                //edge top-left case
                if(!(j -1 < 0))
                {
                    red += image[i - 1][j - 1].rgbtRed;
                    green += image[i - 1][j - 1].rgbtGreen;
                    blue += image[i - 1][j - 1].rgbtBlue;

                    pixelCount++;
                }

                //edge top-middle case
                red += image[i - 1][j].rgbtRed;
                green += image[i - 1][j].rgbtGreen;
                blue += image[i - 1][j].rgbtBlue;
                pixelCount++;

                //edge top-right case
                if(!(j + 1 >= width))
                {

                    red += image[i - 1][j + 1].rgbtRed;
                    green += image[i - 1][j + 1].rgbtGreen;
                    blue += image[i - 1][j + 1].rgbtBlue;
                    pixelCount++;

                }

            }

            //edge middle-left case
            if(!(j - 1 < 0))
            {

                red += image[i][j - 1].rgbtRed;
                green += image[i][j - 1].rgbtGreen;
                blue += image[i][j - 1].rgbtBlue;
                pixelCount++;

            }

            //default middle-middle case
            red += image[i][j].rgbtRed;
            green += image[i][j].rgbtGreen;
            blue += image[i][j].rgbtBlue;
            pixelCount++;

            //edge middle-right case
            if(!(j + 1 >= width))
            {

                red += image[i][j + 1].rgbtRed;
                green += image[i][j + 1].rgbtGreen;
                blue += image[i][j + 1].rgbtBlue;
                pixelCount++;

            }

            //edge bottom case
            if(!(i + 1 > height))
            {

                //edge bottom-left case
                if(!(j - 1 < 0))
                {
                    red += image[i + 1][j - 1].rgbtRed;
                    green += image[i + 1][j - 1].rgbtGreen;
                    blue += image[i + 1][j - 1].rgbtBlue;
                    pixelCount++;
                }

                //edge bottom-middle case
                red += image[i + 1][j].rgbtRed;
                green += image[i + 1][j].rgbtGreen;
                blue += image[i + 1][j].rgbtBlue;
                pixelCount++;

                //edge bottom-right case
                if(!(j + 1 >= width))
                {

                    red += image[i + 1][j + 1].rgbtRed;
                    green += image[i + 1][j + 1].rgbtGreen;
                    blue += image[i + 1][j + 1].rgbtBlue;
                    pixelCount++;

                }

            }

            red = red / pixelCount;
            green = green / pixelCount;
            blue = blue / pixelCount;

            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;

            red = 0;
            green = 0;
            blue = 0;
            pixelCount = 0;

        }

    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

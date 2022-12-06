#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0;
    int j = 0;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            int grayscale_value = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = grayscale_value;
            image[i][j].rgbtGreen = grayscale_value;
            image[i][j].rgbtBlue = grayscale_value;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0;
    int j = 0;
    int16_t red_buffer;
    int16_t green_buffer;
    int16_t blue_buffer;

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            red_buffer = round((image[i][j].rgbtRed * .393) + (image[i][j].rgbtGreen *.769) + (image[i][j].rgbtBlue * .189));
            green_buffer = round((image[i][j].rgbtRed * .349) + (image[i][j].rgbtGreen *.686) + (image[i][j].rgbtBlue * .168));
            blue_buffer = round((image[i][j].rgbtRed * .272) + (image[i][j].rgbtGreen *.534) + (image[i][j].rgbtBlue * .131));
            if (red_buffer > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = red_buffer;
            }
            if (green_buffer > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = green_buffer;
            }
            if (blue_buffer > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = blue_buffer;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0;
    int j = 0;
    int k = 0;
    RGBTRIPLE reflection_array[width];

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            reflection_array[j] = image[i][width - 1 - j];
        }
        j = 0;
        for (k = 0; k < width; k++)
        {
            image[i][j] = reflection_array[k];
            j++;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    RGBTRIPLE copy[height][width];

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            // Not an edge or corner
            if (i > 0 && j > 0 && i < height - 1 && j < width - 1)
            {
                int red_average = round((image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 9.0);
                int green_average = round((image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 9.0);
                int blue_average = round((image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 9.0);
                copy[i][j].rgbtRed = red_average;
                copy[i][j].rgbtGreen = green_average;
                copy[i][j].rgbtBlue = blue_average;
            }
            // Top left corner
            if (i == 0 && j == 0)
            {
                int red_average = round((image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 4.0);
                int green_average = round((image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 4.0);
                int blue_average = round((image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 4.0);
                copy[i][j].rgbtRed = red_average;
                copy[i][j].rgbtGreen = green_average;
                copy[i][j].rgbtBlue = blue_average;
            }
            // Top row (excluding left & right corner)
            if (i == 0 && j > 0 && j < width - 1)
            {
                int red_average = round((image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 6.0);
                int green_average = round((image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 6.0);
                int blue_average = round((image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 6.0);
                copy[i][j].rgbtRed = red_average;
                copy[i][j].rgbtGreen = green_average;
                copy[i][j].rgbtBlue = blue_average;
            }
            // Top right corner
            if (i == 0 && j == width - 1)
            {
                int red_average = round((image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed) / 4.0);
                int green_average = round((image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen) / 4.0);
                int blue_average = round((image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue) / 4.0);
                copy[i][j].rgbtRed = red_average;
                copy[i][j].rgbtGreen = green_average;
                copy[i][j].rgbtBlue = blue_average;
            }
            // Left edge (excluding top and bottom corner)
            if (i > 0 && i < height - 1 && j == 0)
            {
                int red_average = round((image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i+1][j].rgbtRed + image[i+1][j+1].rgbtRed) / 6.0);
                int green_average = round((image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i+1][j].rgbtGreen + image[i+1][j+1].rgbtGreen) / 6.0);
                int blue_average = round((image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / 6.0);
                copy[i][j].rgbtRed = red_average;
                copy[i][j].rgbtGreen = green_average;
                copy[i][j].rgbtBlue = blue_average;
            }
            // Right edge (excluding top and bottom corner)
            if (i > 0 && i < height - 1 && j == width - 1)
            {
                int red_average = round((image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i+1][j-1].rgbtRed + image[i+1][j].rgbtRed) / 6.0);
                int green_average = round((image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i+1][j-1].rgbtGreen + image[i+1][j].rgbtGreen) / 6.0);
                int blue_average = round((image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue) / 6.0);
                copy[i][j].rgbtRed = red_average;
                copy[i][j].rgbtGreen = green_average;
                copy[i][j].rgbtBlue = blue_average;
            }
            //Bottom left corner
            if (i == height - 1 && j == 0)
            {
                int red_average = round((image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed) / 4.0);
                int green_average = round((image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen) / 4.0);
                int blue_average = round((image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue) / 4.0);
                copy[i][j].rgbtRed = red_average;
                copy[i][j].rgbtGreen = green_average;
                copy[i][j].rgbtBlue = blue_average;
            }
            // Bottom row (excluding left & right corner)
            if (i == height - 1 && j > 0 && j < width - 1)
            {
                int red_average = round((image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed + image[i][j+1].rgbtRed) / 6.0);
                int green_average = round((image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen + image[i][j+1].rgbtGreen) / 6.0);
                int blue_average = round((image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue) / 6.0);
                copy[i][j].rgbtRed = red_average;
                copy[i][j].rgbtGreen = green_average;
                copy[i][j].rgbtBlue = blue_average;
            }
            // Bottom right corner
            if (i == height - 1 && j == width - 1)
            {
                int red_average = round((image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed) / 4.0);
                int green_average = round((image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen) / 4.0);
                int blue_average = round((image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue) / 4.0);
                copy[i][j].rgbtRed = red_average;
                copy[i][j].rgbtGreen = green_average;
                copy[i][j].rgbtBlue = blue_average;
            }

        }
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            image[i][j] = copy[i][j];
        }
    }

    return;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
     // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[BLOCK_SIZE];
    int i = 0;
    int j = 0;
    char name_buffer[8];
    FILE *image_file = NULL;
    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff)
        {
            //  Name first 10 files with 2 leading zeroes)
            if (i < 10)
            {
                // First jpg only (doesn't need to close previous jpg file)
                if (j == 0)
                {
                    sprintf(name_buffer, "00%i.jpg", i);
                    printf("%s\n", name_buffer);
                    image_file = fopen(name_buffer, "w");
                    i++;
                    j++;
                }
                // All other jpgs - close previous jpg file first
                else
                {
                    fclose(image_file);
                    sprintf(name_buffer, "00%i.jpg", i);
                    printf("%s\n", name_buffer);
                    image_file = fopen(name_buffer, "w");
                    i++;
                    j++;
                }

            }
            // Files after first 10 - name with 1 leading zero
            else
            {
            fclose(image_file);
            sprintf(name_buffer, "0%i.jpg", i);
            printf("%s\n", name_buffer);
            image_file = fopen(name_buffer, "w");
            i++;
            j++;
            }
        }

        if (image_file != NULL)
        {
            fwrite(buffer, 1, BLOCK_SIZE, image_file);
        }
    }
    fclose(image_file);
    fclose(file);
}
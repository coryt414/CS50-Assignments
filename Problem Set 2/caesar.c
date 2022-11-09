#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Handle error for more or less than 1 command line argument
    if (argv[1] == NULL || argv[2] != NULL)
    {
        printf("Error, wrong number of command line arguments presented");
        return 1;
    }
    // Error handling for command line arguments that are not numeric
    int i = 0;
    for (i = 0; argv[1][i]; i++)
    {
        if (isdigit(argv[1][i]))
        {
        }
        else
        {
            printf("Usage: ./caesar key");
            return 1;
        }
    }

    // Define the command line input as the cipher key (k)
    string k = argv[1];

    // Prompt user for a string to be converted to a cipher using key (k)
    string user_input = get_string("plaintext:  ");

    printf("ciphertext: ");
    i = 0;
    for (i = 0; user_input[i]; i++)
    {
        char c = user_input[i];
        // Take modulus of key (k) % 26 to account for entries over 26
        // This allows program to utilize keys over 26 i.e. 27 shifts letters up 1
        int k_mod = atoi(k) % 26;

        // Evaluate & preserve lowercase letters
        if (islower(c))
        {
            int eval = k_mod + user_input[i];
            // If letter is out of ascii range, subtract 26 to "rotate" through beginning of alphabet
            if (eval > 122)
            {
                eval = eval - 26;
            }
            printf("%c", (char)eval);
        }
        // Evaluate & preserve uppercase letters
        else if (isupper(c))
        {
            int eval = k_mod + user_input[i];
            // If letter is out of ascii range, subtract 26 to "rotate" through beginning of alphabet

            if (eval > 90)
            {
                eval = eval - 26;
            }
            printf("%c", (char)eval);
        }
        // Preserve any input that is not a letter i.e. punctuation & numbers
        else
        {
            printf("%c", (char)user_input[i]);
        }
    }

    printf("\n");
    return 0;
}

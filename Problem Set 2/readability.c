#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string userEntry = get_string("Text: ");

    float letters = count_letters(userEntry);
    float words = count_words(userEntry);
    float sentences = count_sentences(userEntry);

    float L = ((letters / words) * 100);
    float S = ((sentences / words) * 100);
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    if (index > 15)
    {
    printf("Grade 16+\n");
    }
    else if (index < 1)
    {
    printf("Before Grade 1\n");
    }
    else
    {
    printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    // Count letters in user input
    int i = 0;
    int letter_count = 0;
    for (i=0; text[i]; i++)
    {
    if (isupper(text[i]) || islower(text[i]))
    {
    letter_count = letter_count + 1;
    }
    }
    return letter_count;
}

int count_words(string text)
{
    int i = 0;
    int word_count = 1;
    for (i=0; text[i]; i++)
    {
        if (text[i] == 32)
        {
            word_count = word_count + 1;
        }
    }
    return word_count;
}

int count_sentences(string text)
{
    int i = 0;
    int sentence_count = 0;
    for (i=0; text[i]; i++)
    {
        if (text[i] == 33 || text[i] == 46 ||text[i] == 63)
        {
            sentence_count = sentence_count + 1;
        }
    }
    return sentence_count;
}
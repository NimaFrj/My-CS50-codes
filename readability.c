#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int num_letters = count_letters(text);
    int num_words = count_words(text);
    int num_sentences = count_sentences(text);
    float L = ((float)num_letters / (float)num_words) * 100;
    float S = ((float)num_sentences / (float)num_words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int sum_letter = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if isalpha (text[i])
        {
            sum_letter += 1;
        }
    }
    return sum_letter;
}

int count_words(string text)
{
    int sum_words = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            sum_words += 1;
        }
    }
    return sum_words;
}

int count_sentences(string text)
{
    int sum_sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sum_sentences += 1;
        }
    }
    return sum_sentences;
}

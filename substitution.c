#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int numinp, string key[])
{
    string enc = key[1];
    if (strlen(key[1]) != 26 || numinp == 1)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(enc[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    for (int j = 0; j < 26; j++)
    {
        for (int k = j + 1; k < 26; k++)
        {
            if (enc[j] == enc[k])
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    string input = get_string("plaintext: ");
    string enc_new = key[1];
    int length = strlen(input);
    char output[length];
    int alphabetupper[26];
    int alphabetlower[26];

    for (int j = 65, k = 0; j < 91; j++)
    {
        alphabetupper[k] = j;
        k += 1;
    }

    for (int j = 97, k = 0; j < 123; j++)
    {
        alphabetlower[k] = j;
        k += 1;
    }

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(input[i]))
        {
            output[i] = input[i];
            continue;
        }
        if (isupper(input[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (input[i] == alphabetupper[j])
                {

                    output[i] = toupper(enc_new[j]);
                }
            }
        }
        if (islower(input[i]))
        {
            for (int j = 0; j < 26; j++)
            {
                if (input[i] == alphabetlower[j])
                {
                    output[i] = tolower(enc_new[j]);
                }
            }
        }
    }
    printf("ciphertext: %s\n", output);
}

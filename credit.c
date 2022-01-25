#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long number = get_long("Enter the credit card number: ");
    long n = number;
    long m = number;
    int jam;
    long p = number;
    int x;
    int sum = 0;
    int digits = 0;
    do
    {
        n = n / 10;
        digits = digits + 1;
    } while (n != 0);

    for (int i = 2; i < digits + 1; i += 2)
    {
        if (i == 2)
        {
            m = m / 10;
        }
        x = m % 10;
        if (x > 4)
        {
            x = 1 + 2 * x % 10;
            sum += x;
        }
        else
        {
            sum += x * 2;
        }
        if (m > 0)
        {
            m = m / 100;
        }
    }

    for (int j = 1; j < digits + 1; j += 2)
    {
        x = p % 10;
        if (p > 0)
        {
            p = p / 100;
        }
        sum += x;
    }

    //Find total number of digit - 1
    int digit = (int)log10(number);
    //Find first digit
    int firstDigit = (int)(number / pow(10, digit));
    int seconddigits = (int)(number / pow(10, digit - 1));

    bool amex_start = seconddigits == 34 || seconddigits == 37;
    bool master_start = seconddigits == 51 || seconddigits == 52 || seconddigits == 53 || seconddigits == 54 || seconddigits == 55;

    if (sum % 10 == 0)
    {
        if (digits == 15 && amex_start)
        {
            printf("AMEX\n");
        }
        else if (digits == 16 && master_start)
        {
            printf("MASTERCARD\n");
        }
        else if (digits == 13 && firstDigit == 4)
        {
            printf("VISA\n");
        }
        else if (digits == 16 && firstDigit == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

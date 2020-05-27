#include <cs50.h>
#include <stdio.h>
#include <string.h>

long countDigits (long num, int num1, int num2);
int main(void)
{
    long ld = 0; //2 last digits of the string
    long p = 0; // products' digits
    long fsold; // 1st digit of 2 last digit
    long checksum; //checksum
    long store = 0; //store results of last checksum
    long cnum = get_long("Input a credit card number: ");
    long storeCnum1, storeCnum2;
    int couDig = 0;

    // Count the credit card's digit number

    storeCnum1 = cnum;

    // Check starting number of credit card

    storeCnum2 = cnum;

    // Calculate checksum

    for (int x = 100; cnum > 0; x = 100)
    {
        ld = cnum % x; // 2 last digits is modulo ccnum by 100
        fsold = (ld - ld % 10) / 10; // first of 2 last digits
        cnum = (cnum - ld) / x; // number of digits left after take out 2 last digits
        p = 2 * fsold;
        if (p >= 10)
        {
            checksum = p % 10 + (p - p % 10) / 10 + ld % 10 + store;
        }
        else
        {
            checksum = p + ld % 10 + store;
        }
        store = checksum;
    }

    // Verify checksum

    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        while (storeCnum1 > 0)
        {
            storeCnum1 = storeCnum1 / 10;
            couDig++;
        }

        if (couDig == 15)
        {
            storeCnum2 = countDigits (storeCnum2,couDig,2); // reference storeCnum2 = result of the function bc it C won't return result outside function.
            while (couDig > 2);
            if (storeCnum2 == 34 || storeCnum2 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (couDig == 13)
        {
            storeCnum2 = countDigits (storeCnum2,couDig,1);
            if (storeCnum2 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (couDig == 16)
        {
            storeCnum2 = countDigits (storeCnum2,couDig,2);
            if (storeCnum2 == 51 || storeCnum2 == 52 || storeCnum2 == 53 || storeCnum2 == 54 || storeCnum2 == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                storeCnum2 = (storeCnum2 - storeCnum2 % 10) / 10;
                if (storeCnum2 == 4)
                {
                    printf("VISA\n");
                }
                else
                {
                    printf("INVALID\n");
                }
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
}





long countDigits (long num, int num1, int num2)
{
    do
    {
        num = (num - num % 10) / 10;
        num1--;
    }
    while (num1 > num2);
    return  num;
}

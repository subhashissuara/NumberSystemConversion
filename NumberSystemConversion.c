/*
    Subhashis Suara
    UCSE19012
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

int DecimalToBinary(unsigned long long input)
{
    int cnt = 0, output[32];
    while (input > 0)
    {
        output[cnt] = input % 2;
        input = input / 2;
        cnt++;
    }

    printf("Binary number of given Decimal number: ");
    for (int i = (cnt - 1); i >= 0; i--)
        printf("%d", output[i]);
}

int DecimalToOctal(unsigned long long input)
{
    int cnt = 0, output[32];
    while (input > 0)
    {
        output[cnt] = input % 8;
        input = input / 8;
        cnt++;
    }

    printf("Octal number of given Decimal number: ");
    for (int i = (cnt - 1); i >= 0; i--)
        printf("%d", output[i]);
}

int DecimalToHexadecimal(unsigned long long input)
{
    int cnt = 0;
    char output[32];
    while (input > 0)
    {
        switch (input % 16)
        {
        case 10:
            output[cnt] = 'A';
            break;
        case 11:
            output[cnt] = 'B';
            break;
        case 12:
            output[cnt] = 'C';
            break;
        case 13:
            output[cnt] = 'D';
            break;
        case 14:
            output[cnt] = 'E';
            break;
        case 15:
            output[cnt] = 'F';
            break;
        default:
            output[cnt] = (input % 16) + '0';
        }
        input = input / 16;
        cnt++;
    }

    printf("Hexadecimal number of given Decimal number: ");
    for (int i = (cnt - 1); i >= 0; i--)
        printf("%c", output[i]);
}

int BinaryToDecimal(unsigned long long input)
{
    int decimal = 0, cnt = 0, lastDigit;
    while (input > 0)
    {
        lastDigit = input % 10;
        input /= 10;
        decimal += lastDigit * pow(2, cnt);
        cnt++;
    }
    printf("Decimal number of given Binary number: %d", decimal);
}

int BinaryToOctal(unsigned long long input)
{
    int octal = 0, decimal = 0, cnt = 0;
    while (input > 0)
    {
        decimal += (input % 10) * pow(2, cnt);
        cnt++;
        input /= 10;
    }

    int place = 1;

    while (decimal > 0)
    {
        octal += (decimal % 8) * place;
        decimal /= 8;
        place *= 10;
    }
    printf("Octal number of given Binary number: %d", octal);
}

int BinaryToHexadecimal(unsigned long long input)
{
    int hexadecimalCode[] = {0, 1, 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111};

    char output[32];
    int cnt, digit;

    cnt = 0;

    while (input > 0)
    {
        digit = input % 10000;

        for (int i = 0; i < 16; i++)
        {
            if (hexadecimalCode[i] == digit)
            {
                switch (i)
                {
                case 10:
                    output[cnt] = 'A';
                    break;
                case 11:
                    output[cnt] = 'B';
                    break;
                case 12:
                    output[cnt] = 'C';
                    break;
                case 13:
                    output[cnt] = 'D';
                    break;
                case 14:
                    output[cnt] = 'E';
                    break;
                case 15:
                    output[cnt] = 'F';
                    break;
                default:
                    output[cnt] = i + '0';
                }

                cnt++;
                break;
            }
        }

        input /= 10000;
    }

    printf("Hexadecimal number of given Binary number: ");
    for (int i = (cnt - 1); i >= 0; i--)
        printf("%c", output[i]);
}

int OctalToDecimal(unsigned long long input)
{
    int decimal = 0, cnt = 0;
    while (input > 0)
    {
        decimal += (input % 10) * pow(8, cnt);
        cnt++;
        input /= 10;
    }

    printf("Decimal number of given Octal number: %d", decimal);
}

int OctalToBinary(unsigned long long input)
{
    int octalCode[] = {0, 1, 10, 11, 100, 101, 110, 111};

    unsigned long long binary = 0, place = 1;
    int lastDigit;

    while (input > 0)
    {
        lastDigit = input % 10;
        binary = (octalCode[lastDigit] * place) + binary;
        input /= 10;
        place *= 1000;
    }
    printf("Binary number of given Octal number: %llu", binary);
}

int OctalToHexadecimal(unsigned long long input)
{
    int octalCode[] = {0, 1, 10, 11, 100, 101, 110, 111};

    unsigned long long binary = 0, place = 1;
    char output[64];
    int lastDigit, cnt = 0;

    while (input > 0)
    {
        lastDigit = input % 10;
        binary = (octalCode[lastDigit] * place) + binary;
        input /= 10;
        place *= 1000;
    }

    while (binary > 0)
    {
        lastDigit = binary % 10000;
        switch (lastDigit)
        {
        case 0:
            output[cnt] = '0';
            break;
        case 1:
            output[cnt] = '1';
            break;
        case 10:
            output[cnt] = '2';
            break;
        case 11:
            output[cnt] = '3';
            break;
        case 100:
            output[cnt] = '4';
            break;
        case 101:
            output[cnt] = '5';
            break;
        case 110:
            output[cnt] = '6';
            break;
        case 111:
            output[cnt] = '7';
            break;
        case 1000:
            output[cnt] = '8';
            break;
        case 1001:
            output[cnt] = '9';
            break;
        case 1010:
            output[cnt] = 'A';
            break;
        case 1011:
            output[cnt] = 'B';
            break;
        case 1100:
            output[cnt] = 'C';
            break;
        case 1101:
            output[cnt] = 'D';
            break;
        case 1110:
            output[cnt] = 'E';
            break;
        case 1111:
            output[cnt] = 'F';
            break;
        }

        cnt++;
        binary /= 10000;
    }
    printf("Hexadecimal number of given Octal number: ");
    for (int i = (cnt - 1); i >= 0; i--)
        printf("%c", output[i]);
}

int HexadecimalToDecimal()
{
    char input[64];
    unsigned long long decimal = 0, place = 1;
    int value;

    printf("\nEnter the Hexadecimal Number: ");
    scanf("%s", input);

    int size = strlen(input);
    size--;

    for (int cnt = 0; input[cnt] != '\0'; cnt++)
    {
        if (input[cnt] >= '0' && input[cnt] <= '9')
        {
            value = input[cnt] - 48;
        }
        else if (input[cnt] >= 'a' && input[cnt] <= 'f')
        {
            value = input[cnt] - 97 + 10;
        }
        else if (input[cnt] >= 'A' && input[cnt] <= 'F')
        {
            value = input[cnt] - 65 + 10;
        }

        decimal += value * pow(16, size);
        size--;
    }
    printf("Decimal number of given Hexadecimal number: %llu", decimal);
}

int HexadecimalToBinary()
{
    char input[32] = "", binary[64];

    printf("\nEnter the Hexadecimal Number: ");
    scanf("%s", input);

    for (int cnt = 0; input[cnt] != '\0'; cnt++)
    {
        switch (input[cnt])
        {
        case '0':
            strcat(binary, "0000");
            break;
        case '1':
            strcat(binary, "0001");
            break;
        case '2':
            strcat(binary, "0010");
            break;
        case '3':
            strcat(binary, "0011");
            break;
        case '4':
            strcat(binary, "0100");
            break;
        case '5':
            strcat(binary, "0101");
            break;
        case '6':
            strcat(binary, "0110");
            break;
        case '7':
            strcat(binary, "0111");
            break;
        case '8':
            strcat(binary, "1000");
            break;
        case '9':
            strcat(binary, "1001");
            break;
        case 'a':
        case 'A':
            strcat(binary, "1010");
            break;
        case 'b':
        case 'B':
            strcat(binary, "1011");
            break;
        case 'c':
        case 'C':
            strcat(binary, "1100");
            break;
        case 'd':
        case 'D':
            strcat(binary, "1101");
            break;
        case 'e':
        case 'E':
            strcat(binary, "1110");
            break;
        case 'f':
        case 'F':
            strcat(binary, "1111");
            break;
        default:
            printf("Invalid hexadecimal input.");
        }
    }

    printf("Binary number of given Hexadecimal number: %s", binary);
}

int HexadecimalToOctal()
{

    char input[64];
    unsigned long long decimal = 0, octal = 0;

    printf("\nEnter the Hexadecimal Number: ");
    scanf("%s", input);

    int len = strlen(input);

    for (int cnt = 0; input[cnt] != '\0'; cnt++, len--)
    {
        if (input[cnt] >= '0' && input[cnt] <= '9')
        {
            decimal = decimal + (input[cnt] - '0') * pow(16, len - 1);
        }
        if (input[cnt] >= 'A' && input[cnt] <= 'F')
        {
            decimal = decimal + (input[cnt] - 65 + 10) * pow(16, len - 1);
        }
        if (input[cnt] >= 'a' && input[cnt] <= 'f')
        {
            decimal = decimal + (input[cnt] - 97 + 10) * pow(16, len - 1);
        }
    }
    int place = 1;
    while (decimal != 0)
    {
        octal = octal + (decimal % 8) * place;
        decimal = decimal / 8;
        place = place * 10;
    }

    printf("Octal number of given Hexadecimal number: %llu", octal);
}

int main()
{
    int flagLoop = 1;
    while (flagLoop)
    {
        unsigned long long input;
        int choice;
        printf("\n\n************ MENU ************");
        printf("\nChoose from the options below: ");
        printf("\n1. Decimal to Binary");
        printf("\n2. Decimal to Octal");
        printf("\n3. Decimal to Hexadecimal");
        printf("\n4. Binary to Decimal");
        printf("\n5. Binary to Octal");
        printf("\n6. Binary to Hexadecimal");
        printf("\n7. Octal to Decimal");
        printf("\n8. Octal to Binary");
        printf("\n9. Octal to Hexadecimal");
        printf("\n10. Hexadecimal to Decimal");
        printf("\n11. Hexadecimal to Binary");
        printf("\n12. Hexadecimal to Octal");
        printf("\n13. EXIT");
        printf("\nEnter the option number: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the Decimal Number: ");
            scanf("%llu", &input);
            DecimalToBinary(input);
            break;

        case 2:
            printf("\nEnter the Decimal Number: ");
            scanf("%llu", &input);
            DecimalToOctal(input);
            break;

        case 3:
            printf("\nEnter the Decimal Number: ");
            scanf("%llu", &input);
            DecimalToHexadecimal(input);
            break;

        case 4:
            printf("\nEnter the Binary Number: ");
            scanf("%llu", &input);
            BinaryToDecimal(input);
            break;

        case 5:
            printf("\nEnter the Binary Number: ");
            scanf("%llu", &input);
            BinaryToOctal(input);
            break;

        case 6:
            printf("\nEnter the Binary Number: ");
            scanf("%llu", &input);
            BinaryToHexadecimal(input);
            break;

        case 7:
            printf("\nEnter the Octal Number: ");
            scanf("%llu", &input);
            OctalToDecimal(input);
            break;

        case 8:
            printf("\nEnter the Octal Number: ");
            scanf("%llu", &input);
            OctalToBinary(input);
            break;

        case 9:
            printf("\nEnter the Octal Number: ");
            scanf("%llu", &input);
            OctalToHexadecimal(input);
            break;

        case 10:
            HexadecimalToDecimal();
            break;

        case 11:
            HexadecimalToBinary();
            break;

        case 12:
            HexadecimalToOctal();
            break;

        case 13:
            printf("\nThank you for using the program! Exiting...\n");
            flagLoop = 0;
            break;

        default:
            printf("\nInvalid option number! Try Again!");
            break;
        }
    }
    return 0;
}
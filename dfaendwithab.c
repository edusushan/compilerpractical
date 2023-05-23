#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headerfile/DFA.h"

#define ENDING_STRING "ab"
#define ACCEPTED_LANGUAGE "ab"

int main()
{
    int res;
    char input[100];

    printf("Enter the string : ");
    scanf("%s", &input);

    if (!DFALanguageIsCorrect(ACCEPTED_LANGUAGE, input))
    {
        printf("Enter correct language!!");
        return 0;
    }

    res = DFAEndingString(ENDING_STRING, input);

    if (res == 0)
        printf("The string doesnot end with %s and is not accepted", ENDING_STRING);
    else if (res == 1)
        printf("The string ends with %s and is accepted", ENDING_STRING);
        else
        printf("check your input");
    return 0;
}
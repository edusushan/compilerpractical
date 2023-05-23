// C program to check an identifier
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int i = 0, flag = 0;
    char id[10];
    char keyw[32][32] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern","float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch","typedef", "union", "unsigned", "void", "volatile", "while"};

    printf("Enter an identifier: ");
    gets(id);

    for (i = 0; i < 32; i++)
    {
        if ((strcmp(keyw[i], id) == 0))
            flag = 1;
    }
    if (flag == 1)
    {
        printf("\n%s is a keyword.", id);
    }
    else
    {
        if ((id[0] == '_') || (isalpha(id[0])))
        {
            flag = 1;
            for (i = 1; id[i] != '\0'; i++)
            {
                if (!isdigit(id[i]) && !isalpha(id[i]))
                    flag = 0;
                break;
            }
        }
        if (flag == 1)
            printf("%s is an identifier.", id);
        else
            printf("%s is not an identifier.", id);
    }

    return 0;
}

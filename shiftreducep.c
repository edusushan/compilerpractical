#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char str[15];   // for input sring
char stack[15]; // for stack
int ip_ptr = 0, st_ptr = 0, len, i;
char temp[2], temp2[2];
char act[15]; // for action
void check();
int main()
{
    printf("\n\t\t SHIFT REDUCE PARSER\n");
    printf("\n GRAMMER\n");
    printf("\n E->E+E\n E->E/E");
    printf("\n E->E*E\n E->a/b");
    printf("\n enter the input String:\t");
    gets(str);
    printf("\n\t stack implementation table");
    printf("\n stack\t\t input symbol\t\t action");
    printf("\n______\t\t ____________\t\t ______\n");
    printf("\n $\t\t%s$\t\t\t------", str);
    strcpy(act, "shift ");
    temp[0] = str[ip_ptr];
    temp[1] = '\0';
    strcat(act, temp);
    len = strlen(str);
    for (i = 0; i <= len - 1; i++)
    {
        stack[st_ptr] = str[ip_ptr]; // st_prt=0, in_ptr=0
        stack[st_ptr + 1] = '\0';
        str[ip_ptr] = ' ';
        ip_ptr++;
        printf("\n $%s\t\t%s$\t\t\t%s", stack, str, act);
        strcpy(act, "shift ");
        temp[0] = str[ip_ptr];
        temp[1] = '\0';
        strcat(act, temp);
        check();
        st_ptr++;
    }
    st_ptr++;
    check();
    return 0;
}
void check()
{
    int flag = 0;
    temp2[0] = stack[st_ptr];
    temp2[1] = '\0';
    if ((!strcmpi(temp2, "a")) || (!strcmpi(temp2, "b")))
    {
        stack[st_ptr] = 'E';
        if (!strcmpi(temp2, "a"))
            printf("\n $%s\t\t%s$\t\t\tReduce E->a", stack, str);
        else
            printf("\n $%s\t\t%s$\t\t\t Reduce E->b", stack, str);
        flag = 1;
    }
    if ((!strcmpi(temp2, "+")) || (strcmpi(temp2, "*")) || (!strcmpi(temp2, "/")))
    {
        flag = 1;
    }
    if ((!strcmpi(stack, "E+E")) || (!strcmpi(stack, "E\E")) || (!strcmpi(stack, "E*E")))
    {
        strcpy(stack, "E");
        st_ptr = 0;
        if (!strcmpi(stack, "E+E"))
            printf("\n $%s\t\t%s$\t\t\treduce E->E+E", stack, str);
        else if (!strcmpi(stack, "E\E"))
            printf("\n $%s\t\t %s$\t\t\treduce E->E\E", stack, str);
        else
            printf("\n $%s\t\t%s$\t\t\treduce  E->E*E", stack, str);
        flag = 1;
    }
    if ((!strcmpi(stack, "E") || (!strcmpi(stack, "E+E")) || (!strcmpi(stack, "E/E")) || (!strcmpi(stack, "E*E"))) && ip_ptr == len)
    {
        printf("\n $%s\t\t%s$\t\t\tACCEPT", stack, str);
        exit(0);
    }
    if (flag == 0)
    {
        printf("\n%s\t\t\t%s\t\t reject", stack, str);
        exit(0);
    }
    return;
}

//C program to validate tokens(tokenization)
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

bool isDelimiter(char ch)
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == ',' || ch == ';' || ch == '=')
        return (true);
    return (false);
}

//returns true if the character is an Operator
bool isOperator(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    return false;
}

//returns true if the string is an Identiifier
bool validIdentifier(char* str){
    if(!isalnum(str[0])|| !isalpha(str[0]))
        return false;
    return true;
}

//returns true if the string is a Keyword
bool isKeyword(char* str){
    if(!strcmp(str, "int") || !strcmp(str, "float") || !strcmp(str, "char"))
        return true;
    return false;
}

//extracts the substring
char* subString(char* str, int left, int right){
    int i;
    char* subStr = (char*)malloc(sizeof(char)*(right-left+2));
    for(i = left; i <= right; i++)
        subStr[i-left] = str[i];
    subStr[right-left+1] = '\0';
    return subStr;
}

//Parsing the input String
void parse(char* str){
    int left = 0, right = 0;
    int len = strlen(str);

    while(right <= len && left <= right){
    	if (isDelimiter(str[right]) == false)
            right++;
        
		if(isDelimiter(str[right]) == true && left == right){
            if(isOperator(str[right]) == true)
                printf("'%c' is an Operator\n", str[right]);
            
			right++;
            left = right;
        }
        else if((isDelimiter(str[right]) == true && left != right) || (right == len && left != right)){
            char* subStr = subString(str, left, right-1);

            if(isKeyword(subStr) == true)
                printf("'%s' is a Keyword\n", subStr);
            else if(validIdentifier(subStr) == true)
                printf("'%s' is a valid Identifer\n", subStr);
            else if (validIdentifier(subStr) == false)
                printf("'%s' is not a valid Identifier\n", subStr);
            left = right;
        }
    }
    return;
}

int main(){
    char str[50] = "float a = b + c";
    parse(str); //calling in the parse function
    return 0;
}

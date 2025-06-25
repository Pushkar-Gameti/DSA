#include <stdio.h>
#include <string.h>

void sub(char str[], int idx, char newstr[])
{
    if (idx == strlen(str))
    {
        printf("\n%s", newstr);
        return;
    }
    char currChar = str[idx];

    int len = strlen(newstr);
    newstr[len] = currChar;
    newstr[len + 1] = '\0';
    sub(str, idx + 1, newstr);

    newstr[len] = '\0';
    sub(str, idx + 1, newstr);
}
int main()
{
    char str[]="abcd";
    char newstr[100]="";
    sub(str, 0, newstr);
    return 0;
}
#include<stdio.h>
#include<string.h>

void removeD(char str[], int idx, char newstr[]){
    static int map[26]={0};
    if(idx==(strlen(str))){
        printf("%s",newstr);
        return;
    }
    char currChar = str[idx];
    if(map[currChar-'a']){
        removeD(str, idx+1, newstr);
    }
    else{
        int len = strlen(newstr);
        newstr[len] = currChar;
        newstr[len + 1] = '\0';
        map[currChar-'a'] = 1;
        removeD(str, idx+1, newstr);
    }
}

int main(){
    char str[]= "abbccdaabdcbdbcabcbdbcbabdbcdax";
    char newstr[100]="";
    removeD(str, 0,newstr);

    return 0;
}
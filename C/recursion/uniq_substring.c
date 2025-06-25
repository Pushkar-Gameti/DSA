#include <stdio.h>
#include <string.h>

char unique[1000][100]; // To store unique subsequences
int count = 0;

// Function to check if subsequence is already stored
int isDuplicate(char str[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(unique[i], str) == 0)
            return 1;
    }
    return 0;
}

void subUnique(char str[], int idx, char newstr[]) {
    if (idx == strlen(str)) {
        if (!isDuplicate(newstr)) {
            strcpy(unique[count], newstr);
            count++;
            printf("\"%s\"\n", newstr);
        }
        return;
    }

    // Include current character
    int len = strlen(newstr);
    newstr[len] = str[idx];
    newstr[len + 1] = '\0';
    subUnique(str, idx + 1, newstr);

    // Backtrack
    newstr[len] = '\0';

    // Exclude current character
    subUnique(str, idx + 1, newstr);
}

int main() {
    char str[] = "aab";
    char newstr[100] = "";

    printf("Unique Subsequences of \"%s\":\n", str);
    subUnique(str, 0, newstr);

    return 0;
}

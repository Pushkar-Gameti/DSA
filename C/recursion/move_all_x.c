#include <stdio.h>
#include <string.h>

void move(char str[], int idx, int count, char newstr[]) {
    if (idx == strlen(str)) {
        // Add all 'x' characters at the end
        for (int i = 0; i < count; i++) {
            newstr[strlen(newstr)] = 'x';
        }
        newstr[strlen(newstr)] = '\0'; // Null-terminate
        printf("\nModified string: %s\n", newstr);
        return;
    }

    char currChar = str[idx];
    if (currChar == 'x') {
        move(str, idx + 1, count + 1, newstr);
    } else {
        int len = strlen(newstr);
        newstr[len] = currChar;
        newstr[len + 1] = '\0';
        move(str, idx + 1, count, newstr);
    }
}

int main() {
    char str[] = "axbcxxd";
    char newstr[100] = "";  // Empty string with enough size

    printf("Original string: %s\n", str);
    move(str, 0, 0, newstr);

    return 0;
}

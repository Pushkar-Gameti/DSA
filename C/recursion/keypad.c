#include <stdio.h>
#include <string.h>

char *keypad[] = {".", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tu", "vwx", "yz"};

void printCombination(char str[], int idx, char combination[]) {
    if (idx == strlen(str)) {
        printf("%s\n", combination);
        return;
    }

    char currChar = str[idx];
    char *mapping = keypad[currChar - '0'];

    for (int i = 0; i < strlen(mapping); i++) {
        int len = strlen(combination);
        combination[len] = mapping[i];
        combination[len + 1] = '\0';

        printCombination(str, idx + 1, combination);

        // backtrack
        combination[len] = '\0';
    }
}

int main() {
    char str[] = "23";
    char combination[100] = ""; // buffer to hold each result
    printCombination(str, 0, combination);
    return 0;
}

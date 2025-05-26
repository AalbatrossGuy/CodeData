//
// Created by AG on 5/26/2025.
//

#include <stdio.h>

void copyString(char to[], const char from[]);
void copyStringAlternative(char *to, char *from);

int main() {
    char str1[] = "This is String 1";
    char str2[] = "This is String 2";
    printf("BEFORE: str1 = %s, str2 = %s\n", str1, str2);
    copyString(str1, str2);
    // copyStringAlternative(str1, str2);
    printf("AFTER: str1 = %s, str2 = %s\n", str1, str2);
    return 0;
}

void copyString(char to[], const char from[]) {
    int i;
    for (i = 0; from[i] != '\0'; ++i) {
        to[i] = from[i]; // Copy each character from second string to first string.
    }
    to[i] = '\0'; // Add a null character at the end to make the string valid?.
}

void copyStringAlternative(char *to, char *from) {
    // for (; *from != '\0'; ++from, ++to) {
    //     *to = *from; // Copy from second string to first string.
    // }
    // *to = '\0'; // Add a null character at the end to make the string valid?.

    // ALTERNATIVE METHOD
    while (*from != '\0') {
        *to++ = *from++;
    }
    *to = '\0'; // Add a null character at the end to make the string valid?.

}
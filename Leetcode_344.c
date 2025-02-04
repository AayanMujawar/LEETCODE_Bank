#include <stdio.h>

void reverseString(char* s, int sSize) {
    int left = 0, right = sSize - 1;
    char temp;

    while (left < right) {
        // Swap characters
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;

        // Move pointers
        left++;
        right--;
    }
}

int main() {
    char s[] = {'H', 'a', 'n', 'n', 'a', 'h'};
    int sSize = sizeof(s) / sizeof(s[0]);
    int i;

    reverseString(s, sSize);

    // Print the reversed string
    for (i = 0; i < sSize; i++) {
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}


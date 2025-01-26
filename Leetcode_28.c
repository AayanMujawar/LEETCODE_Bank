#include <stdio.h>
#include <string.h>

int strStr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return 0; // If needle is empty, return 0.
    }

    int haystackLen = strlen(haystack);
    int needleLen = strlen(needle);

    for (int i = 0; i <= haystackLen - needleLen; i++) {
        if (strncmp(&haystack[i], needle, needleLen) == 0) {
            return i; // Found the first occurrence of needle.
        }
    }

    return -1; // If needle is not found, return -1.
}

int main() {
    const char *haystack1 = "sadbutsad";
    const char *needle1 = "sad";
    printf("Output: %d\n", strStr(haystack1, needle1)); // Expected output: 0

    const char *haystack2 = "leetcode";
    const char *needle2 = "leeto";
    printf("Output: %d\n", strStr(haystack2, needle2)); // Expected output: -1

    return 0;
}


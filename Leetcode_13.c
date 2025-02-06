#include <stdio.h>
#include <string.h>

int romanToInt(char *s) {
    // Map Roman numerals to integers
    int roman_to_int[128] = {0};
    roman_to_int['I'] = 1;
    roman_to_int['V'] = 5;
    roman_to_int['X'] = 10;
    roman_to_int['L'] = 50;
    roman_to_int['C'] = 100;
    roman_to_int['D'] = 500;
    roman_to_int['M'] = 1000;

    int result = 0, prev_value = 0;
int i;
    // Iterate over the string from right to left
    for ( i = strlen(s) - 1; i >= 0; i--) {
        int current_value = roman_to_int[s[i]];

        if (current_value < prev_value) {
            result -= current_value;
        } else {
            result += current_value;
        }

        prev_value = current_value;
    }

    return result;
}

int main() {
    printf("%d\n", romanToInt("III"));       // Output: 3
    printf("%d\n", romanToInt("LVIII"));     // Output: 58
    printf("%d\n", romanToInt("MCMXCIV"));   // Output: 1994

    return 0;
}


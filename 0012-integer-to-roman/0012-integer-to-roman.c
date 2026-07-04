#include <stdio.h>
#include <string.h>
typedef struct {
    int value;
    const char *symbol;
} RomanMapping;

char* intToRoman(int num) {
    const RomanMapping romanMap[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
        {1, "I"}
    };
    
    static char result[16]; 
    result[0] = '\0'; 
    
    int mapSize = sizeof(romanMap) / sizeof(romanMap[0]);

    for (int i = 0; i < mapSize; i++) {
        while (num >= romanMap[i].value) {
            strcat(result, romanMap[i].symbol);
            num -= romanMap[i].value;
        }
        if (num == 0) break;
    }
    return result;
}
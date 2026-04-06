// Exercício 13
// Implemente a sua versão da função strcat sem utilizar o operador [].

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void my_strcat(char* str1, const char* str2) {
    char* ptr = str1 + strlen(str1);
    while (*str2 != '\0') {
        *(ptr++) = *(str2++);
    }
    *ptr = '\0';
}

int main (void) {
    
    return 0;
}
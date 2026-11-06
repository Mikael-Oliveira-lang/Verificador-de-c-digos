#include <stdio.h>
#include <stdlib.h>



#define TAM 100

int main() {
    char str[TAM];
    int i, j, len;
    int isPalindrome = 1;

    printf("Digite uma string: ");
    fgets(str, TAM, stdin);

    // Remove o caractere de nova linha, se presente
    len = 0;
    while (str[len] != '\0' && str[len] != '\n') {
        len++;
    }
    str[len] = '\0'; // Substitui o '\n' por '\0'

    // Verifica se a string é um palíndromo
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome) {
        printf("A string é um palíndromo.\n");
    } else {
        printf("A string não é um palíndromo.\n");
    }

    return 0;

}
/*

  write a  Program to count vowels and consonants in a string using pointer.

*/

#include <stdio.h>

int main() {
    char A[] = "Arpit";
    char *c;
    int vowels = 0, consonants = 0;

    // printf("Enter a string: ");
    // fgets(A, sizeof(A), stdin);

    c = A;  

    while (*c != '\0') {
        char ch = *c;

        
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
        }

        
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        } 
       
        else if (ch >= 'a' && ch <= 'z') {
            consonants++;
        }

        c++; 
    }

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}

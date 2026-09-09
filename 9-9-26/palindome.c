#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int isPalindrome = 1;

    // Prompt the user for input
    printf("Input: ");
    
    // Read the string including spaces
    if (fgets(str, sizeof(str), stdin) != NULL) {
        // Remove the trailing newline character added by fgets
        str[strcspn(str, "\n")] = '\0';
    }

    // Task 1: Find the length of the string
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    // Task 2: Check Palindrome condition
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            isPalindrome = 0; // Set to false if a mismatch is found
            break;
        }
    }

    // Output the result
    if (isPalindrome) {
        printf("Output: Palindrome\n");
    } else {
        printf("Output: Not a Palindrome\n");
    }

    return 0;
}


#include <stdio.h>
#include <string.h>

void encrypt(char *input, char *output) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        int j = (i * 2) % len;
        output[j] = input[i] ^ (i + 1);
    }
    output[len] = '\0';
}

int main() {
    char userInput[100];
    char encryptedCorrectFlag[] = "N\\NUR]W7698;:a";
    char userEncryptedInput[100];

    printf("Enter the flag: ");
    scanf("%99s", userInput);

    encrypt(userInput, userEncryptedInput);

    if (strcmp(userEncryptedInput, encryptedCorrectFlag) == 0) {
        printf("Congratulations! You found the correct flag.\n");
    } else {
        printf("Sorry, that's not the correct flag. Try again.\n");
    }

    return 0;
}


#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    
    printf("A true Linux master (trainee) always knows what the flag is.\n");
    printf("So... what is the flag? ");
    scanf("%99s", password);

    if (strcmp(password, "YZUIMSC{https://youtu.be/zCbfcBIwrrY?si=qqXdb-RZCdI6V1m2}") == 0) {
        printf("Congratulations! Although you have passed the test, there is still much for you to learn.\n");
    } else {
        printf("Go back and train harder.\n");
    }

    return 0;
}

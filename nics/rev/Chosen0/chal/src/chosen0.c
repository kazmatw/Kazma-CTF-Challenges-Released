#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    printf("The real linux master(trainee) always know what the flag is."); 
    printf("So...what is the flag: ");
    scanf("%99s", password);

    if(strcmp(password, "YZUIMSC{https://youtu.be/zCbfcBIwrrY?si=qqXdb-RZCdI6V1m2}") == 0) {
        printf("Congratulations, although you have passed the test, there is still much for you to learn.\n");
    } else {
        printf("Go back and train harder.\n");
    }

    return 0;
}


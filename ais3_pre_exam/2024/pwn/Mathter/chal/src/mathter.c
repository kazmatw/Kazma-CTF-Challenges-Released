#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void win1(unsigned int check) {
    if (check == 0xdeadbeef) {
        FILE *fp = fopen("flag", "r");
        if (fp != NULL) {
            char flag_part[128];
            if (fgets(flag_part, sizeof(flag_part), fp) != NULL) {
                char* token = strtok(flag_part, "b");
                if (token != NULL) {
                    printf("%s", token);
                }
            }
            fclose(fp);
        } else {
            printf("Failed to open flag file.\n");
        }
    } else {
        printf("Sorry, wrong argument. Try again!\n");
    }
}

void win2(unsigned int check) {
    if (check == 0xcafebabe) {
        FILE *fp = fopen("flag", "r");
        if (fp != NULL) {
            char flag_part[128];
            if (fgets(flag_part, sizeof(flag_part), fp) != NULL) {
                char* token = strtok(flag_part, "_");
                token = strtok(NULL, "\n");
                if (token != NULL) {
                    printf("%s\n", token);
                }
            }
            fclose(fp);
        } else {
            printf("Failed to open flag file.\n");
        }
    } else {
        printf("Sorry, wrong argument. Try again!\n");
    }
}

int goodbye() {
    char response[4];
    printf("Are you sure you want to leave? [Y/n]\n");
    gets(response);
    if (response[0] == 'y' || response[0] == 'Y') {
        printf("Goodbye!\n");
        return 1;
    }
    return 0;
}

void calculator() {
    char input[256]; 
    int x, y, result;
    char op;

    while (1) {
        printf("Enter an operation and two numbers (e.g., 1 + 1) : ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == 'q') {
            printf("Exiting calculator...\n");
            break;
        }

        if (sscanf(input, "%d %c %d", &x, &op, &y) == 3) {
            switch (op) {
                case '+':
                    result = x + y;
                    printf("%d + %d = %d\n", x, y, result);
                    break;
                case '-':
                    result = x - y;
                    printf("%d - %d = %d\n", x, y, result);
                    break;
                case '*':
                    result = x * y;
                    printf("%d * %d = %d\n", x, y, result);
                    break;
                case '/':
                    if (y != 0) {
                        result = x / y;
                        printf("%d / %d = %d\n", x, y, result);
                    } else {
                        printf("Error: Division by zero!\n");
                    }
                    break;
                default:
                    printf("Invalid operation!\n");
            }
        } else {
            printf("Invalid input format. Please use the format: 1 + 1\n");
        }
    }
}


int main() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    

    printf(" __        __   _                            _          __  __       _   _     _            \n");
    printf(" \\ \\      / /__| | ___ ___  _ __ ___   ___  | |_ ___   |  \\/  | __ _| |_| |__ | |_ ___ _ __ \n");
    printf("  \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  | |\\/| |/ _` | __| '_ \\| __/ _ \\ '__|\n");
    printf("   \\ V  V /  __/ | (_| (_) | | | | | |  __/ | || (_) | | |  | | (_| | |_| | | | ||  __/ |   \n");
    printf("    \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/  |_|  |_|\\__,_|\\__|_| |_|\\__\\___|_|\n\n");

    
    while (1) {
        calculator();
	if (goodbye()){
	    break;
	}
    }
    return 0;
}
//gcc -static -o mathter -no-pie -fno-stack-protector -z now -z relro mathter.c


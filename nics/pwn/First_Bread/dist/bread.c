#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}

void flag() {
    system("cat flag.txt");
}

int main() {
    init();
    printf("Return to here: %p\n", (void*)flag + 0x4);
    char buf[0x10];
    printf("Pwn me plz: ");
    gets(buf); 
}


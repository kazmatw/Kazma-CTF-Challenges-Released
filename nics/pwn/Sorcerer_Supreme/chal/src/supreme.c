#include <stdio.h>
#include <stdlib.h>

#define size 21
#define secret_value "FLAG{T1m3_tr4v3l_1s_3ff0rtl3ss_f0r_th3_S0rc3r3r_Supr3m3}"
#define coffee "Can you buy kazma a coffee?"

void init(){
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
}


int main() {
    init();
    char *years[size] = {
        "This year, you will join B33F 50UP.",
        "In one year, you will be stronger.",
        "In two years, you will have traveled the world.",
        "In three years, you will have learned a new language.",
        "In four years, you will have graduated.",
        "In five years, you will be in your dream job.",
        "In six years, you will have bought a house.",
        "In seven years, you will have started a family.",
        "In eight years, you will have written a book.",
        "In nine years, you will have a thriving business.",
        "In ten years, you will be a leader in your field.",
        "In eleven years, you will have visited the moon.",
        "In twelve years, you will be a tech mogul.",
        "In thirteen years, you will have a Nobel Prize.",
        "In fourteen years, you will be a renowned artist.",
        "In fifteen years, you will have invented something revolutionary.",
        "In sixteen years, you will have traveled to Mars.",
        "In seventeen years, you will have your own TV show.",
        "In eighteen years, you will be an ambassador.",
        "In nineteen years, you will have saved the world.",
        "In twenty years, you will be the President.",
    };
    char *secret = secret_value;
    char *foo = coffee;
    int year = 0;

    printf("Address of years: %p\n", (void*)years);
    printf("Address of secret: %p\n", (void*)&secret);
    printf("Enter the number of years you want to travel into the future (0~20): ");

    scanf("%d", &year);

    puts(years[year]);
}


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdint.h>
#define MAX 10
#define LOOP_LIMIT 15

void init(){
    setvbuf(stdout, 0, 2, 0);
    setvbuf(stdin, 0, 2, 0);
    setvbuf(stderr, 0, 2, 0);
}

typedef struct {
    char *content;
    int id;
} Dream;

Dream dreams[MAX];
int next_id = 1;

void welcome_message() {
    printf("Hello Dream Architect, you've been invited to join the Kazma Pikachu Team's Dream Building Training!\n");
    printf("Here in our Hyperbolic Time Chamber, you can hone your dream crafting skills and prepare for upcoming missions.\n\n");
}

void print_dream_layer_menu() {
    printf("How deep do you want to build the dream?\n");
    printf("1. First layer\n");
    printf("2. Second layer\n");
    printf("3. Third layer\n");
    printf("> ");
}

void build_dream(){
    print_dream_layer_menu();
    int choice;
    scanf("%d", &choice);
    uint64_t size = 0;

    switch(choice) {
        case 1: size = 0x38; break;
        case 2: size = 0x68; break;
        case 3: size = 0x108; break;
        default:
            printf("Invalid choice.\n\n");
            return;
    }

    for(int i = 0; i < MAX; ++i){
        if(!dreams[i].content){
            dreams[i].content = malloc(size);
            printf("Describe the dream: ");
            read(0, dreams[i].content, size - 1);
            dreams[i].content[size - 1] = '\0';
            dreams[i].id = next_id++;
            printf("Dream built with ID %d in the layer!\n\n", dreams[i].id);
            return;
        }
    }
    printf("All dream layers are occupied!\n\n");
}

void infiltrate_dream(){
    printf("Enter dream ID to infiltrate:\n> ");
    int id;
    scanf("%d", &id);

    for (int i = 0; i < MAX; ++i){
        if(dreams[i].id == id && dreams[i].content != NULL){
            printf("Infiltrating dream ID %d:\n%s\n\n", id, dreams[i].content);
            return;
        }
    }
    printf("No such dream with that ID!\n\n");
}

void destroy_dream(){
    printf("Enter dream ID to destroy:\n> ");
    int id;
    scanf("%d", &id);

    for (int i = 0; i < MAX; ++i){
        if(dreams[i].id == id && dreams[i].content != NULL){
            free(dreams[i].content);
            printf("Dream destroyed!\n\n");
            return;
        }
    }
    printf("No such dream with that ID!\n\n");
}

void menu(){
    printf("1. Build a dream\n");
    printf("2. Infiltrate a dream\n");
    printf("3. Destroy a dream\n");
    printf("4. Exit\n");
    printf("> ");
}

int main(){
    init();

    printf("\n  ██╗    ██╗███╗   ██╗ ██████╗███████╗██████╗ ████████╗██╗ ██████╗ ███╗   ██╗    ██╗  \n");
    printf(" ██╔╝    ██║████╗  ██║██╔════╝██╔════╝██╔══██╗╚══██╔══╝██║██╔═══██╗████╗  ██║    ╚██╗ \n");
    printf("██╔╝     ██║██╔██╗ ██║██║     █████╗  ██████╔╝   ██║   ██║██║   ██║██╔██╗ ██║     ╚██╗\n");
    printf("╚██╗     ██║██║╚██╗██║██║     ██╔══╝  ██╔═══╝    ██║   ██║██║   ██║██║╚██╗██║     ██╔╝\n");
    printf(" ╚██╗    ██║██║ ╚████║╚██████╗███████╗██║        ██║   ██║╚██████╔╝██║ ╚████║    ██╔╝ \n");
    printf("  ╚═╝    ╚═╝╚═╝  ╚═══╝ ╚═════╝╚══════╝╚═╝        ╚═╝   ╚═╝ ╚═════╝ ╚═╝  ╚═══╝    ╚═╝  \n");
    printf("                                                                                      \n");

    welcome_message();
    int loop_count = 0;

    while(loop_count < LOOP_LIMIT){
        menu();

        int n;
        scanf("%d", &n);

        switch(n){
            case 1:
                build_dream();
                break;
            case 2:
                infiltrate_dream();
                break;
            case 3:
                destroy_dream();
                break;
            case 4:
                printf("Enemies are waking up, time to retreat!\n\n");
                exit(0);
                break;
            default:
                printf("Capabilities insufficient.\n\n");
                break;
        }
        loop_count++;
    }

    printf("Oh no, running out of stamina...\n");
    return 0;
}


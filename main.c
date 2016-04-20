#include <stdio.h>
#include <stdlib.h>

void app();
void printMenu();

int main() {
    
    app();
}   

void app() {
    int ask = 0;
    
    do {
        printMenu();
        scanf("%d",&ask);
        switch(ask) {
            case 1:
                printf("Menu 1\n");
                break;
            case 2:
                printf("Menu 2\n");
                break;
            case 3:
                printf("Menu 3\n");
                break;
            case 4:
                printf("App end");
                exit(1);
        }
    } while(1);
}

void printMenu() {
    printf("(1) Display current date and time\n");
    printf("(2) Display the calendar of the current month\n");
    printf("(3) List the files in the current directory\n");
    printf("(4) Exit from the program\n");
    printf("Enter: ");
}
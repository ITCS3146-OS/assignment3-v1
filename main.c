#include <stdio.h>
#include <stdlib.h>

void app();
void printMenu();
void runSelected(int);

int main() {
    
    app();
}   

void app() {
    int select = 0;
    
    do {
        printMenu();
        scanf("%d",&select);
        runSelected(select);
    } while(1);
}

void printMenu() {
    printf("(1) Display current date and time\n");
    printf("(2) Display the calendar of the current month\n");
    printf("(3) List the files in the current directory\n");
    printf("(4) Exit from the program\n");
    printf("Enter: ");
}

void runSelected(int ask) {
    switch(ask) {
        case 1:
            system("date");
            break;
        case 2:
            system("cal");
            break;
        case 3:
            system("ls -l");    
            break;
        case 4:
            printf("App end\n");
            exit(0);
    }
}
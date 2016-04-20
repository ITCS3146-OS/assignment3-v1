#include <stdio.h>

void printMenu();

int main() {
    printMenu();
}   

void printMenu() {
    printf("(1) Display current date and time\n");
    printf("(2) Display the calendar of the current month\n");
    printf("(3) List the files in the current directory\n");
    printf("(4) Exit from the program\n");
}
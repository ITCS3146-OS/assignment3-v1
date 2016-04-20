#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void app();
void printMenu();
void printProcessesID(int,int);
void runSelected(int);


int main() {
    // start the app
    app();
}   

// application logic
void app() {
    int select = 0, status;
    pid_t currentPid, childPid, ppid, tempPid;
    currentPid = getpid();
    ppid = getppid();
    
    for(;;) {
        printf("Current process ID: %d, Parent process ID: %d\n",currentPid, ppid);
        printMenu();
        scanf("%d",&select);
        if(select >= 4) {
            printf("App end\n");
            exit(0);
        } else {
            tempPid = fork();
            
            // check for child process
            if(tempPid == 0) {
                currentPid = getpid();
                ppid = getppid();
                printProcessesID(currentPid,ppid);
                runSelected(select);
                exit(0);
            } else if( tempPid == -1) { // check fork() error
                printf("Failed to Fork.");
            }
            else {
                // wait child process to finish it's jobs
                childPid = wait(&status);
                printf("\n\n");
            }    
        }
    }
}

void printProcessesID(int p1,int p2) {
    printf("Child process ID: %d, Parent process ID: %d\n",p1,p2);
}

void printMenu() {
    printf("Choose the function to be performed by the child:\n");
    printf("(1) Display current date and time\n");
    printf("(2) Display the calendar of the current month\n");
    printf("(3) List the files in the current directory\n");
    printf("(4) Exit from the program\n");
    printf("Enter: ");
}

// child process's system command to run
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
    }
}
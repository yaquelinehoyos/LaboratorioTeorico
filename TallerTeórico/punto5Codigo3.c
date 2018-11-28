#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main () {
    pid_t pid_hijo1; 
    pid_t pid_hijo2; 
    pid_t pid_hijo3;
    pid_hijo1 = fork(); // Creo el primer hijo
    if (pid_hijo1 == 0) { // Hijo 1
      printf("Soy el hijo 1\n");
      sleep (5);
    } else {  // Padre
        pid_hijo1 = wait(NULL);
        pid_hijo2 = fork(); // Creo al segundo hijo
        if (pid_hijo2 == 0) { // Hijo 2
          printf("Soy el hijo 2\n");
          sleep (5);
        } else {  // Padre
            pid_hijo2 = wait(NULL);
            pid_hijo3 = fork();  // Creo al tercer hijo
            if (pid_hijo3 == 0) { // Hijo 3
                printf("Soy el hijo 3\n");
                sleep (5);
            } else {  // Padre
                pid_hijo3 = wait(NULL);
                printf("Soy el padre\n");
                sleep (5);
            }
        }
    }
    return 0;
}
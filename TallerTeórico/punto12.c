#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[]) {
    pid_t pid=fork();
    if (pid < 0) {
            perror("Fallo el fork");
    } else if (pid==0) {
            printf("Hijo: Se ha abierto el programa deseado \n");
        execlp(argv[1], argv[1], 0);        
    } else {
            printf("Padre: Soy el padre, el hijo será ejecutado \n");
            wait(NULL);
            printf("Padre: El hijo a terminado de ejecutarse, el programa terminará \n");
    } 
    return 0;
}

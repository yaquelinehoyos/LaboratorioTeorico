#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid1, pid2;
    printf("Padre: Hola \n");
    fflush(stdout); //Limpiar el buffer
    pid1 = fork();
    if(pid1 == -1){
        printf("fork falló");
        fflush(stdout); //Limpiar el buffer
    } else if(pid1 == 0){
        printf("Hijo: Mundo \n");
        fflush(stdout); //Limpiar el buffer
        pid2 = fork();
        if(pid2 == -1){
            printf("fork falló");
            fflush(stdout); //Limpiar el buffer
        }else if(pid2 == 0){
            printf("Nieto: ! \n");
            fflush(stdout); //Limpiar el buffer
        }
    }
    return 0;
}
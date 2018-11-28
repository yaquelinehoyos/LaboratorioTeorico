#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int factorial(int num){
    if(num == 1){
        return(1);
    }else{
        return(num*factorial(num-1));
    }
}

int main(){
    pid_t pid1, pid2;
    pid1 = fork();
    int fac;
    if (pid1 == -1){
        printf("fork 1 falló");
    } else if(pid1 == 0){
        for(int i = 1; i <= 10; i++){
            fac = factorial(i);
            printf("HIJO 1: El factorial de %d es : %d \n", i, fac);
        }
    } else {
        pid2 = fork();
        if(pid2 == -1){
            printf("fork 2 falló");
        } else if(pid2 == 0){
            for(int i = 1; i <= 10; i++){
                fac = factorial(i);
                printf("HIJO 2: El factorial de %d es : %d \n", i, fac);
            }
        } else {
            pid1 = wait(NULL);
            printf("Padre \n");
        }
    }
    return 0;
}
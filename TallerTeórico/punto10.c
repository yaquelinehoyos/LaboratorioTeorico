#include<stdio.h> 
#include <unistd.h>
#include <sys/types.h>
  
int main() { 
    pid_t pid, pidh, pidn, pidnn;
    int ppid;
    char str[10];
    pid = fork();
    if(pid == -1){
        printf("fork falló");
    } else if(pid == 0) { 
        pidn = fork();
        if(pidn == -1){
            printf("fork falló");
        }else if(pidn == 0){
            printf("Soy el nieto con pid %d, mi padre tiene pid %d \n", (int)getpid(), (int)getppid());
            sleep(5);
        }else{
            pidnn = fork();
            if(pidnn == -1){
                printf("fork falló");
            } else if(pidnn == 0){
                printf("Soy el nieto con pid %d, mi padre tiene pid %d \n", (int)getpid(), (int)getppid());
                sleep(5);
            } else {
                printf("Soy el hijo con pid %d, mi padre tiene pid %d \n", (int)getpid(), (int)getppid()); 
                sleep(5);
            }
        }
    } else {
        pidh = fork();
        if(pidh == -1){
            printf("fork falló");
        } else if(pidh == 0) { 
            printf("Soy el hijo con pid %d, mi padre tiene pid %d \n", (int)getpid(), (int)getppid());
            sleep(5);
        } else {
            ppid = (int)getpid();
            sprintf(str, "%d", ppid);
            printf("Luke, yo soy tu padre %d \n", (int)getpid());
            execlp("pstree", "pstree", "-a", str);
            sleep(5);
        }
    }
} 
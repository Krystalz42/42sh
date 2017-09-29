#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <fcntl.h>
#include <curses.h>
#include <term.h>
#include <stdbool.h>
#include <sys/types.h>
#include <dirent.h>

int main(void)
{
    pid_t pid;
    pid=fork();
    if(pid==-1){
        perror("fork failure");
        exit(EXIT_FAILURE);
    }
    else if(pid==0){
        printf("pid in child=%d and parent=%d\n",getpid(),getppid()); 
    }
    else{
        printf("pid in parent=%d and childid=%d\n",getpid(),getppid());
    }
    exit(EXIT_SUCCESS);
}

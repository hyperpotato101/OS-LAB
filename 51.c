#include<stdio.h>
#include<stdlib.h> 
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

//print the child pid and parent pid
int main(){ 
    pid_t pid;
    pid = fork();
    if(pid == 0){
         printf("child");
         printf("pid = %ld\n", (long)getpid());
	printf("parent");
printf("pid = %ld\n", (long)getppid());
         exit(0);
    }
    wait(NULL); 
    return 0;   
} 




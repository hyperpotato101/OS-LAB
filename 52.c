#include<stdio.h> 
#include <unistd.h> 
#include<string.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
//print the child pid and parent pid
int main(int argc, char *argv[]){ 
    pid_t pid;
    char s[25][25],temp[25];
    for(int i=1;i<argc;i++){
       strcpy(s[i],argv[i]); 
    }
    pid = fork();
    if (pid == 0) { 
        printf("Child Process \n");
        for (int i = 0; i < 5; i++) { 
            for(int j=0;j<5-i-1;j++){
                if(strcmp(s[j+1],s[j])<0){
                    strcpy(temp,s[j]);
                    strcpy(s[j],s[j+1]);
                    strcpy(s[j+1],temp);
                }
            }
        } 
  
        printf("Sorted list");
        for(int i=0;i<5;i++){
            printf("%s\n",s[i]);
        }
        exit(0);
    } 
    else { 
        wait(NULL);
        printf("Parent Process \n");
        printf("Unsorted list");
        for(int i=0;i<5;i++){
            printf("%s\n",s[i]);
        }
    } 
    return 0;   
} 



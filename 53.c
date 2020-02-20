#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
int main(int argc,char *argv[]){
    int n=argc;
    char a[25][25];
    for(int i=1;i<n;i++)
        strcpy(a[i],argv[i]);
   pid_t c1=fork();
   
   if(c1==0){
        char t[25];
        for(int i=1;i<n;i++){
            for(int j=1;j<n-i;j++){
                if(strcmp(a[j],a[j+1])>0){
                    strcpy(t,a[j]);
                    strcpy(a[j],a[j+1]);
                    strcpy(a[j+1],t);
                }     
            }
   }
        printf("sorted using bubble sort: \n");
        for(int i=1;i<n;i++){printf("%s\n",a[i]);}
        exit(0);
   }
    else
    {
        wait(NULL);
        printf("inside parent process\n");
    }
    pid_t c2=fork();
    if(c2==0){
        for(int i=1;i<n;i++)
            strcpy(a[i],argv[i]);
        char min[25],temp[25];
        int pos;
        for(int i=1;i<n;i++){
            strcpy(min,a[i]);
            pos=i;
            for(int j=i+1;j<n;j++){
                if(strcmp(a[j],min)<0){
                    strcpy(min,a[j]);
                pos=j;
                }
            }
        if(pos!=i){
            strcpy(temp,a[i]);
            strcpy(a[i],a[pos]);
            strcpy(a[pos],temp);
        }
       }
    printf("sorted using selection sort: \n");
    for(int i=1;i<n;i++){printf("%s\n",a[i]);}
    exit(0);
    }

    else
    { wait(NULL);
      printf("INSIDE PARENT PROCESS\n");
    }
    return 0;
}

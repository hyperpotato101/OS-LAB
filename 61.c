#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdlib.h>
#include <stdbool.h> 
#include<string.h>

struct Process { 
    int pid;
    int bt;
    int art;
}; 
  
void findWaitingTimes(struct Process proc[], int n, 
                                int wt[]) 
{ 
    int rt[n]; 
    for (int i = 0; i < n; i++) 
        rt[i] = proc[i].bt; 
  
    int complete = 0, t = 0, minm = 10000000; 
    int shortest = 0, finish_time; 
    bool check = false; 
  
    while (complete != n) { 
        for (int j = 0; j < n; j++) { 
            if ((proc[j].art <= t) && 
            (rt[j] < minm) && rt[j] > 0) { 
                minm = rt[j]; 
                shortest = j; 
                check = true; 
            } 
        } 
  
        if (check == false) { 
            t++; 
            continue; 
        } 
        rt[shortest]--; 
        minm = rt[shortest]; 
        if (minm == 0) 
            minm = 1000000; 
        if (rt[shortest] == 0) { 
            complete++; 
            check = false; 
            finish_time = t + 1; 
            wt[shortest] = finish_time - 
                        proc[shortest].bt - 
                        proc[shortest].art; 
  
            if (wt[shortest] < 0) 
                wt[shortest] = 0; 
        } 
        t++; 
    } 
} 
  
void findTurnAroundTimes(struct Process proc[], int n, 
                        int wt[], int tat[]) 
{ 
    for (int i = 0; i < n; i++) 
        tat[i] = proc[i].bt + wt[i]; 
} 
   
void findavgTimes(struct Process proc[], int n) 
{ 
    int wt[n], tat[n], total_wt = 0, 
                    total_tat = 0; 
    findWaitingTimes(proc, n, wt); 
    findTurnAroundTimes(proc, n, wt, tat); 
    printf("Processes ");
    printf("Burst time ");
    printf("Waiting time ");
    printf("Turn around time \n");
    for (int i = 0; i < n; i++) { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        printf(" %d \t\t %d \t\t %d \t\t %d \n " , proc[i].pid , proc[i].bt,  wt[i] , tat[i]);
    } 
    float avgw = (float)total_wt/(float)n; 
    float avgtat = (float)total_tat/(float)n; 
    printf("\nAverage waiting time = %f",avgw );
    printf("\nAverage turn around time = %f",avgtat);
} 

void findWaitingTimer(int processes[], int n, 
             int bt[], int wt[], int quantum) 
{ 
    int rem_bt[n]; 
    for (int i = 0 ; i < n ; i++) 
        rem_bt[i] =  bt[i]; 
  
    int t = 0;
    while (1) 
    { 
        bool done = true; 
        for (int i = 0 ; i < n; i++) 
        {
            if (rem_bt[i] > 0) 
            { 
                done = false;  
  
                if (rem_bt[i] > quantum) 
                { 
                    t += quantum;  
                    rem_bt[i] -= quantum; 
                } 
                else
                {
                    t = t + rem_bt[i]; 
                    wt[i] = t - bt[i]; 
                    rem_bt[i] = 0; 
                } 
            } 
        } 
        if (done == true) 
          break; 
    } 
} 
  
void findTurnAroundTimer(int processes[], int n, 
                        int bt[], int wt[], int tat[]) 
{ 
    for (int i = 0; i < n ; i++) 
        tat[i] = bt[i] + wt[i]; 
} 
  
void findavgTimer(int processes[], int n, int bt[], 
                                     int quantum) 
{ 
    int wt[n], tat[n], total_wt = 0, total_tat = 0; 
   
    findWaitingTimer(processes, n, bt, wt, quantum); 
    findTurnAroundTimer(processes, n, bt, wt, tat); 

    printf("Processes ");
    printf("Burst time ");
    printf("Waiting time ");
    printf("Turn around time \n");
    for (int i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
         printf(" %d \t\t %d \t\t %d \t\t %d \n " , i+1 ,bt[i],  wt[i] , tat[i]);
    } 
  
    float avgw = (float)total_wt/(float)n; 
    float avgtat = (float)total_tat/(float)n; 
    printf("\nAverage waiting time = %f",avgw );
    printf("\nAverage turn around time = %f",avgtat);
} 

void Priority(){
    int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;          
    }

    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;  

    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;   
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]; 
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;   
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
}

int main() 
{ 
    int ch=1;
    printf("Enter Choice (0 -EXIT , 1-SJF , 2-RR , 3-Priority) : ");
    scanf("%d",&ch);
    while(1){
        if(ch==0){
            break;
        }
        if(ch==1){
            int n;
            printf("\n Enter the number of processes");
            scanf("%d",&n);
            struct Process proc[n];
            for(int i =0;i<n;i++)
            {
            	printf("\nEnter the process id");
            	scanf("%d",&proc[i].pid);
            	printf("\nEnter the arrival time ");
            	scanf("%d",&proc[i].art);
            	printf("\nEnter the burst time ");
            	scanf("%d",&proc[i].bt);
            }


            findavgTimes(proc, n); 
        }
        else if(ch==2){
            int n;
            printf("\n Enter the number of processes");
            scanf("%d",&n);
            int quantum,processes[n],burst_time[n]; 
            
            printf("\n Enter the process id");
            for(int i =0;i<n;i++)
            {
             	scanf("%d",&processes[i]);
             	}            
              printf("\n Enter the burst time  ");
            for(int i =0;i<n;i++)
            {
            	scanf("%d",&burst_time[i]);
            }
            printf("\n Enter the time quantum");
            scanf("%d",&quantum);
            findavgTimer(processes, n, burst_time, quantum); 
        }
        else if(ch==3){
            Priority();
        }
        else{
            printf("\n\n!!!!!!!Wrong Choice  (0 -EXIT , 1-SJF , 2-RR , 3-Priority) :");
            scanf("%d",&ch);
            continue;
        }
        printf("\n\nEnter Choice (0 -EXIT , 1-SJF , 2-RR , 3-Priority) : ");
        scanf("%d",&ch);
    }
    return 0; 
} 

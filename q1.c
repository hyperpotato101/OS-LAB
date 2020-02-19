#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
  
// A structure to represent a queue 
struct Queue 
{ 
    int front, rear, size; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a queue of given capacity.  
// It initializes size of queue as 0 
struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;  
    queue->rear = capacity - 1;  // This is important, see the enqueue 
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 
  
// Queue is full when size becomes equal to the capacity  
int isFull(struct Queue* queue) 
{  return (queue->size == queue->capacity);  } 
  
// Queue is empty when size is 0 
int isEmpty(struct Queue* queue) 
{  return (queue->size == 0); } 
  
// Function to add an item to the queue.   
// It changes rear and size 
void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
        return; 
    queue->rear = (queue->rear + 1)%queue->capacity; 
    queue->array[queue->rear] = item; 
    queue->size = queue->size + 1; 
    printf("%d enqueued to queue\n", item); 
} 
  
// Function to remove an item from queue.  
// It changes front and size 
int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 
  
// Function to get front of queue 
int front(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->front]; 
} 
  
// Function to get rear of queue 
int rear(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
        return INT_MIN; 
    return queue->array[queue->rear]; 
} 


struct process
{
    char a; //process names
    int at;  //arrival time
    int bt;  //burst time 
    int priority; // priority
};




// A function to implement bubble sort  
void bubbleSort(struct process arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j].priority > arr[j+1].priority)
        {
            char c = arr[j].a;
            arr[j].a = arr[j+1].a;
            arr[j+1].a = c;
            int p;


            p = arr[j].at;
            arr[j].at = arr[j+1].at;
            arr[j+1].at = p;


            p = arr[j].bt;
            arr[j].bt = arr[j+1].bt;
            arr[j+1].bt = p;



            p = arr[j].priority;
            arr[j].priority = arr[j+1].priority;
            arr[j+1].priority = p;
        }  
            
}  



int main()
{
    int ch;
    printf("enter choice 1(RR) 2(SJF) 3(PRIORITY) \n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 3: printf("enter the number of process");
                int n;
                scanf("%d",&n);
                struct process p[n];
                for(int i=0;i<n;i++)
                {
                    scanf("%c",&p[i].a);
                    scanf("%d",&p[i].at);
                    scanf("%d",&p[i].bt);
                    scanf("%d",&p[i].priority);

                }
                boolean arrived[n];
                for(i =0;i<n;i++)
                {
                    arrived[i] = false;
                }
                bubbleSort(p,n);
                int time = 0;
                for(i=0;i<n;i++)
                {

                }


    }
    return 0;
    

}
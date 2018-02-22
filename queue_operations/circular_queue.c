//Queue Operations work as follows:
// Two pointers called FRONT and REAR are used to keep track of the first and last elements in the queue.
// When initializing the queue, we set the value of FRONT and REAR  to -1.
// On enqueing an element, we circularly increase the value of REAR index and place the new element in the position pointed to by REAR.
// On dequeueing an element, we return the value pointed to by FRONT and circularly increase the FRONT index.
// Before enqueing , we check if queue is already full.
// Before dequeuing, we check if queue is already empty.
// When enqueing the first element, we set the value of FRONT to 0
// When dequeing the last element, we reset the value of front and rear to -1
//
// Check for full queue has new additional cases
// Case 1: front == 0 and Rear == size-1
// Case 2: front = rear+1
#include <stdio.h>

#define SIZE 5

int item[SIZE];
int front = -1;
int rear = -1;

void printFrontRear(front, rear) {
    printf("Value of front is %d and rear is %d\n",front,rear);
}

int isFull() {
    // front = 0 and rear = SIZE-1. When no elemented are enqueued 
    // front != 0 and front = rear + 1. When there is a rotation and rear is behind front
    if(((front == rear + 1)) || (front == 0 && rear == SIZE-1)) {
        return 1;
    }
    return 0;
}

int isEmpty() {
    //We initialize front to -1 initally and change it to 0 when we insert a new element for hte first time. 
    if(front == -1) {
        return 1;
    }
    return 0;
}


void enQueue(int element) {
    //Before adding an element, check if queue is full
    if(isFull()) 
    {
        printf("Queue is Full !!!\n");
        printFrontRear(front, rear);
    }
    else
    {
        //If there are no elements and you are inserting the first element
        //for the first time, make front 0 and calculate rear before enqueue
        if(front == -1) 
        {
            front = 0;
        }
        rear = (rear+1)%SIZE;
        item[rear] = element;
        printf("Inserted -> %d at %d\n",element,rear);
    }
}

void deQueue() {
    int element;
    if(isEmpty()) {
        printf("Queue is empty !!\n");
        printFrontRear(front, rear);
    }
    else
    {
        element = item[front];
        //When there is only one element front will be rear
        if(front == rear) {
            front = -1;
            rear = -1;
        }
        else
        {
            //If more than one element in queue, decrement front
            front = (front+1) % SIZE;
        }
        printf("\nDeleted element -> %d\n",element);
    }
}

void display() {
    int i;
    if(isEmpty())
    {
        printf("Queue is empty \n");
        printFrontRear(front, rear);
    }
    else
    {
        printf("Front -> %d\n",front);
        printf("\nItems -> ");
        //Starting from front till rear including the rotated elements
        //Print items
        for(i = front; i!=rear; i=(i+1)%SIZE) {
            printf("%d ",item[i]);
        }
        printf("%d",item[i]);
        printf("\nRear -> %d\n",rear);
    }
}

int main() {
    deQueue();
    enQueue(1);
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    
    enQueue(6);
    
    deQueue();
    deQueue();
    deQueue();
    deQueue();
    deQueue();

    display();
    enQueue(8);
    enQueue(9);
    enQueue(10);
    enQueue(11);

    display();
    return 0;
}

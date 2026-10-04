/*
    Jack O'Toole
    queue type linked integer list
    head , elements...., tail, null

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
} Node;

typedef struct Queue{
    Node *head;
    Node *tail;
    int   size;
} Queue;

Queue *create_queue();
int size(Queue *queue);
bool is_empty(Queue *queue);
int peek(Queue *queue,bool *status);   // value at head of queue
void enqueue(Queue *queue, int value); // add value to tail of queue
int dequeue(Queue *queue,bool *status);// remove value from head of queue
void destroy_queue(Queue *queue);

int main(){
/* */
    Queue *queue = create_queue();
    enqueue(queue,4);
    if (is_empty(queue)){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue is not empty\n");
    }
    enqueue(queue,5);
    enqueue(queue,6);
    printf("Queue size: %d\n", size(queue));

    bool status;//
    int value;
    value = peek(queue,&status);
    printf("Front of queue: %d\n", value);
    printf("Queue size: %d\n", size(queue));

    value = dequeue(queue,&status);
    if (status) {
        printf("Dequeued value: %d\n", value);
    }
   destroy_queue(queue);
   printf("Queue destroyed\n");
   //printf("Queue size: %d\n", size(queue));  random integer value printed after queue destroyed


    return 0 ;
}

Queue *create_queue(){
    
    Queue *queue =  malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;

}

int size(Queue *queue){
    
    return queue->size;
}

bool is_empty(Queue *queue){

    return (queue->size == 0);

}

int peek(Queue *queue,bool *status){
    if (is_empty(queue)){
        *status = false;
        return -1;  // ?????
    }
    return queue->head->value;
    *status = true;

}  

void enqueue(Queue *queue, int value){
    Node *newNode = malloc(sizeof(Node));
    
    newNode->value = value;
    newNode->next = NULL;
    if (is_empty(queue)) {
        queue->head = newNode;
        queue->tail = newNode;
    }
    else{
        queue->tail->next = newNode;
        queue->tail = newNode;
    }
    queue->size++;

}
int dequeue(Queue *queue,bool *status){
    if (is_empty(queue)){
        *status = false;
        return -1;
    }
   
    *status = true;
    int value = queue->head->value;

    Node *oldHead = queue->head;
    if (queue->size == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = queue->head->next;// ??? oldHead
    }
    free(oldHead);
    queue->size--;
    return value;
}
void destroy_queue(Queue *queue){
    Node *currentNode = queue->head;
    while (currentNode != NULL){
        Node *temp =currentNode;
        currentNode= currentNode->next;
        free(temp);
    }
    free(queue);
}

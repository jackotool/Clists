/*
    Jack O'Toole October 2026
    queue type linked string list ie;
    head , elements...., tail, null
    head,elements and tail are nodes containing strings and and a pointer to the next node

*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    char str[100];
    struct Node *next;
} Node;


typedef struct Queue{
    Node *head;
    Node *tail; 
    int   size;
} Queue;

Queue *create_queue();
int size_of(Queue *queue);
bool is_empty(Queue *queue);
char *peek(Queue *queue,bool *status);  
     // str at head of queue, status indicates if queue is empty
void enqueue(Queue *queue, char *str); // add str to tail of queue
void dequeue(Queue *queue,bool *status);// remove str from head of queue
void destroy_queue(Queue *queue);
void print_queue(Queue *queue);

int main(){

    bool status;//    
    Queue *queue = create_queue();
    enqueue(queue,"Hello");
    enqueue(queue,"World");
    enqueue(queue,"!");
    enqueue(queue,"This");
    enqueue(queue,"is");
    enqueue(queue,"a");
    enqueue(queue,"short list");
    printf("Queue size: %zu \n", size_of(queue));

    //print queue contents
    char *a_str;
    Queue *current = queue;
    Node *currentNode = queue->head;

    if  (current->head != NULL) { 
        while (currentNode != NULL) {
            printf("%s :\n", currentNode->str);
            currentNode = currentNode->next;
        }
    }


   // dequeue all elements from the queue
    int count = 0;
    while (!is_empty(queue)) {
        dequeue(queue,&status);
        count++;
    }
    printf("%d nodes dequeued. \n", count );
        
   destroy_queue(queue);
   printf("Queue destroyed\n\n");
   
    return 0 ;
}

Queue *create_queue(){
    
    Queue *queue =  malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;
    printf("Queue created, size: %d\n", queue->size);

    return queue;

}

int size_of(Queue *queue){
    
    return queue->size;
}

bool is_empty(Queue *queue){

    return (queue->size == 0);

}

char *peek(Queue *queue,bool *status){
    if (is_empty(queue)){
        *status = false;
        return NULL;  // ?????
    }
    return queue->head->str;
    *status = true;

}  

void enqueue(Queue *queue, char *str){
    Node *newNode = malloc(sizeof(Node));
    
    strcpy(newNode->str, str);
    
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

void dequeue(Queue *queue,bool *status){
    if (is_empty(queue)){
        *status = false;
        return ;
    }
   
    *status = true;
    char *str = queue->head->str;

    Node *oldHead = queue->head;
    if (queue->size == 1) {
        queue->head = NULL;
        queue->tail = NULL;
    } else {
        queue->head = queue->head->next;// ??? oldHead
    }
    //printf("Old Head str: %s dequeued\n", oldHead->str);

    free(oldHead);
    queue->size--;
    return ; 
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

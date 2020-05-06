// 3.2
// Stack Min: How would you design a stack which, in addition to push and pop, 
//has a function min which returns the minimum eiement? Push, pop and min 
//should all operate in 0 ( 1 ) time.

#include <iostream>
#include <stdio.h>

typedef struct stack{
    struct stack *prev;
    int value;
    int min;
} Stack;

Stack *queue;

void push(int value){
    Stack *s = new Stack;
    s->value = value;
    if (queue == NULL){
        s->min = value;
        s->prev = NULL;
    }else{
        s->prev = queue;
        if (value < queue->min){
            s->min = value;
        }else{
            s->min = queue->min;
        }
    }
    queue = s;
}

void pop(){
    if (!queue->prev){
        return;
    }
    Stack *q = queue->prev;
    queue = q;
}

void minimum(){
    printf("min: %d\n", queue->min);
}

int main(){
    queue = NULL;

    while(1){
        std::string command;
        std::cin >> command;
        
        if (command == "push"){
            int value;
            std::cin >> value;
            push(value);
            printf("v: %d\n", queue->value);
        }else if(command == "pop"){
            pop();
            printf("v: %d\n", queue->value);
        }else if(command == "min"){
            minimum();
            continue;
        }else{
            std::cout<< "Not an option\n";
        }
    }
}
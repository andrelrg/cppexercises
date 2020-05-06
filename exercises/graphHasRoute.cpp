#include <iostream>
#include <stdio.h>

// 4.1
// Route Between Nodes: Given a directed graph, design an algorithm to find out 
//whether there is a route between two nodes.
int size;
bool isEmpty;

typedef struct node {
    int value;
    bool visited;
    int cNumber;
    node *children[5];
} Node;

typedef struct stack{
    struct stack *next;
    Node *node;
} Stack;

Stack *queue;

void push(Node *node){
    Stack *s = new Stack;
    s->node = node;
    Stack *aux = queue;
    s->next = NULL;
    if (queue == NULL){
        queue = s;
    }else{
        while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = s;
    }
}

Node *pop(){
    if (queue == NULL){
        return NULL;
    }
    if (queue->next == NULL){
        Node *n = queue->node;
        queue = NULL;
        return n;
    }
    
    Node *n = queue->node;
    queue = queue->next;
    
    return n;
}

void addVertice(Node *from, Node *to){
    from->cNumber++;
    from->children[from->cNumber-1] = to;
}

bool hasRoute(Node *graph[], int from, int to){
    for (int i = 0; i<size; i++){ // putting all the flags to false
        graph[i]->visited = false;
    }

    queue = NULL;
    graph[from]->visited = true;
    push(graph[from]);

    while(!isEmpty){
        Node *n;
        n = pop();
        if (n != NULL){
            printf("Passing through: %d\n", n->value);
            
            if (n->value == to){
                return true;
            }
            for (int i = 0; i<n->cNumber; i++){
                if (!n->children[i]->visited){
                    n->children[i]->visited = true;
                    printf("Pushing: %d\n", n->children[i]->value);
                    push(n->children[i]);
                }
            }
        }else{
            return false;
        }
    }

    return false;
}

int main(){
    
    int from, to;

    // printf("Size of the graph: ");
    // scanf("%d", &size);

    size = 6;
    isEmpty = false;
    
    Node *graph[size];

    for (int i = 0; i<size; i++){
        Node *n = new Node;
        n->value = i;
        printf("%d\n", n->value);
        n->cNumber = 0;
        graph[i] = n;
    }

    addVertice(graph[0], graph[1]);
    addVertice(graph[0], graph[4]);
    addVertice(graph[0], graph[5]);
    addVertice(graph[1], graph[4]);
    addVertice(graph[1], graph[3]);
    addVertice(graph[2], graph[1]);
    addVertice(graph[3], graph[2]);
    addVertice(graph[3], graph[4]);


    while(1){
        printf("Has route? from to: ");
        scanf("%d %d", &from, &to);
        printf("%s\n", hasRoute(graph, from, to) ? "true": "false");
    }
    
}
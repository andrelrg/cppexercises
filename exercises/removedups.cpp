#include <iostream>
#include <stdio.h>

// 2.1
// RemoveDups Write code to remove duplicates from an unsorted linked list.(not finished)
typedef struct node
{
    int item;
    node *next;
} Node;

typedef struct hash
{
    int item;
    bool initiated;
    hash *next;
} Hash;

const int MAX = 10;
Node *head,*tail;
Hash hashtable[MAX];

void removeDups(){
    Node *n = head;
    while(n){
        Hash *h = new Hash;
        h->item = n->item;
        h->initiated = true;
        h->next = NULL;
        if (!hashtable[n->item%MAX].initiated){
            hashtable[n->item%MAX] = *h;
        }else{
            hashtable[n->item%MAX].next = h;
        }
        n = n->next;
    }
    for (int i = 0; i<MAX; i++){
        Hash *h = &hashtable[i];
        Hash *h2 = &hashtable[i];
        while(h){

            printf("%d,", h->item);
            h = h->next;
        }
        printf("\n");
    }
}

void add_node(int n){
    Node *tmp = new Node;
    tmp->item = n;
    tmp->next = NULL;

    if(head == NULL){
        head = tmp;
        tail = tmp;
        return;
    }
    else{
        tail->next = tmp;
        tail = tail->next;
    }
}  

int main()
{
    int random[] = {3,2,6,3,7,4,6,8,9,45,3,5,7,8,6};
    int s = sizeof(random)/sizeof(random[0]);
    for (int i = 0; i<s; i++){
        add_node(random[i]);
    }

    removeDups();
}
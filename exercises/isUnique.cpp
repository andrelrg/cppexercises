#include <iostream>
#include <stdio.h>

// 1.1
// Is Unique: Implement an algorithm to determine if a string has all unique characters.

const int MAX = 26;
typedef struct node{
    char c;
} Node;

Node hashing[MAX];

bool isUnique(std::string word){
    for (char& c: word){
        if (hashing[(int)c%MAX].c == c){
            return false;
        }else{
            hashing[(int)c%MAX].c = c;
        }
    }

    return true;
}

int main(){
    for (int i = 0; i< MAX; i++) {
        Node n;
        hashing[i] = n;
    }

    std::string s;
    std::getline(std::cin, s);
    printf("%s", (isUnique(s) ? "true" : "false"));
}

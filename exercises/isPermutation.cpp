#include <iostream>
#include <stdio.h>

// 1.2 
// Check Permutation: Given two strings, write a method to decide if one is a permutation of the other.
const int MAX = 26;

typedef struct node {
    char c;
} Node;

Node hashing[MAX];

bool isPermutation(std::string s1, std::string s2){
    if (s1.length() != s2.length()) return false;
    for(char& c : s1){
        hashing[(int)c%MAX].c = c;
    }
    for(char& c : s2){
        if (!hashing[(int)c%MAX].c){
            return false;
        }
    }
    return true;
}

int main(){
    for (int i = 0; i< MAX; i++){
        Node n;
        hashing[i] = n;
    }

    std::string s1;
    std::getline(std::cin, s1);
    std::string s2;
    std::getline(std::cin, s2);
    printf("%d", isPermutation(s1, s2));
}
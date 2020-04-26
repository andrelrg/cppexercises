#include "bigofunctions.h"

int lookIndex(const int arr[], const int index){ //Constant O(1)
    return arr[index];
}

int binarySearch(const int arr[], const int size, int searchNumber){ //Logarithimic O(log(n))
    int half = size/2;

    if (arr[half] == searchNumber){
        return half;
    } 
    else if (arr[half] > searchNumber){
        int narr[half];
        for (int a = 0; a<half; a++){
            narr[a] = arr[a];
        }
        return binarySearch(narr, half, searchNumber);
    } 
    else{
        int narr[half];
        for (int a = half; a<size; a++){
            narr[a] = arr[a];
        }
        return binarySearch(narr, half, searchNumber);
    } 
}

int maxUnsorted(const int arr[], const int size){ //Linear O(n)
    int max = -99;
    for(int i = 0; i<size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}



bool hasDuplicates(const int arr[], const int size){ // Quadratic O(n^2)
    int n = 0;
    for (int a=0; a < size; a++){
        for (int b=0; b < size; b++){
            if (a == b) continue;
            if (arr[a] == arr[b]) n++;
        }
    }
    return n > 0;
}

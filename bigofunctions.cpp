#include "bigofunctions.h"

//Constant O(1)
int lookIndex(const int arr[], const int index){ 
    return arr[index];
}

//Logarithimic O(log(n))
int binarySearch(const int arr[], const int size, int searchNumber){ 
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

//Linear O(n)
int maxUnsorted(const int arr[], const int size){ 
    int max = -99;
    for(int i = 0; i<size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}


// Quadratic O(n^2)
bool hasDuplicates(const int arr[], const int size){ 
    int n = 0;
    for (int a=0; a < size; a++){
        for (int b=0; b < size; b++){
            if (a == b) continue;
            if (arr[a] == arr[b]) n++;
        }
    }
    return n > 0;
}

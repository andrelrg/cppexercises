#ifndef BIGO_F_H
#define BIGO_F_H

#include <bits/stdc++.h> 

int lookIndex(const int arr[], const int index); //Constant O(1)
int binarySearch(const int arr[], const int size, int searchNumber); //Logarithimic O(log(n))
int maxUnsorted(const int arr[], const int size); //Linear O(n)

bool hasDuplicates(const int arr[], const int size); // Quadratic O(n^2)
int fibonacci(int n); // Exponential O(2^n)
void permutation(std::string string, int start, int end); //Factorial O(n!)

#endif // HEADER_FLAG


#include "bigo.h"

int const smallArraySize = 10;
int const bigArraySize = 50;

const int unsortedSmallArray[smallArraySize] = {2,4,1,3,7,6,8,9,10,5};
const int sortedSmallArray[smallArraySize] = {1,2,3,4,5,6,20,8,9,10};
const int unsortedBigArray[bigArraySize] = {50,44,24,1,37,15,7,9,27,42,33,46,6,13,32,48,29,31,8,22,25,38,19,14,12,17,11,43,23,35,39,45,40,16,5,49,26,21,2,34,4,3,47,30,36,20,18,28,10,41};
const int sortedBigArray[bigArraySize] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};

void constant(){
    printf("O(1) Constant Time\n\n");
    printf("O(1) It's algorithms that takes the same amount of time regardless of the size of the input.\n");
    printf("  Some examples are:\n");
    printf("    - Look for a especific index inside an array\n");
    printf("    - Print an especific element of an array.\n\n");
    printf("This function will be executed using the first time an array of size %d and then one of size %d, in both looking for the 7 index. It's expected that the time will be equivalent\n", smallArraySize, bigArraySize);

    std::cout << ""
"    int lookIndex(int arr[], int index){ \n"
"        return arr[index]; \n"
"    }\n"<<std::endl;
    
    std::chrono::steady_clock::time_point ts1 = std::chrono::steady_clock::now();
    lookIndex(unsortedSmallArray, 7);
    std::chrono::steady_clock::time_point te1 = std::chrono::steady_clock::now();

    std::chrono::steady_clock::time_point ts2 = std::chrono::steady_clock::now();
    lookIndex(unsortedBigArray, 7);
    std::chrono::steady_clock::time_point te2 = std::chrono::steady_clock::now();

    std::cout << "First time: " << std::chrono::duration_cast<std::chrono::microseconds>(te1 - ts1).count() << "[µs]" 
    " Second time: " << std::chrono::duration_cast<std::chrono::microseconds>(te2 - ts2).count() << "[µs]" << std::endl;
}



void linear(){
    printf("O(n) Linear time\n\n");
    printf("O(n) It's algorithms that takes more time, the bigger input. \n");
    printf("  Some examples are:\n");
    printf("    - Get the max value in an array.\n");
    printf("    - Print all the values in an array.\n");
    printf("This function will be executed using the first time an array of size %d and then one of size %d.\n", smallArraySize, bigArraySize);


        std::cout << ""
"   int maxUnsorted(int arr[]){\n"
"       int max = -99;\n"
"       for(int i = 0; i<sizeof(arr); i++){\n"
"           if (arr[i] > max){\n"
"               max = arr[i];\n"
"           }\n"
"       }\n"
"       return max;\n"
"   }\n"
""<<std::endl;
    
    std::chrono::steady_clock::time_point ts1 = std::chrono::steady_clock::now();
    maxUnsorted(unsortedSmallArray, smallArraySize);
    std::chrono::steady_clock::time_point te1 = std::chrono::steady_clock::now();

    std::chrono::steady_clock::time_point ts2 = std::chrono::steady_clock::now();
    maxUnsorted(unsortedBigArray, bigArraySize);
    std::chrono::steady_clock::time_point te2 = std::chrono::steady_clock::now();

    std::cout << "First time: " << std::chrono::duration_cast<std::chrono::microseconds>(te1 - ts1).count() << "[µs]" 
    " Second time: " << std::chrono::duration_cast<std::chrono::microseconds>(te2 - ts2).count() << "[µs]" << std::endl;

}



void quadratic(){
    printf("O(n^2) Quadratic time\n\n");
    printf("O(n^2) It's algorithms that will grow in n^2 rate, basically if the input has a 2 size it will do 4 opperations, and if it has a 8 size it will do 64 opperations. \n");
    printf("  Some examples are:\n");
    printf("    - Check for duplicated values in an array.\n");
    printf("    - Sort elements (bubble sort, etc).\n");
    printf("This function will be executed using the first time an array of size %d and then one of size %d.\n", smallArraySize, bigArraySize);

std::cout << ""
"    bool hasDuplicates(int arr[], int size){\n"
"        int n = 0;\n"
"        for (int a=0; a < size; a++){\n"
"            for (int b=0; b < size; b++){\n"
"                if (a == b) continue;\n"
"                if (arr[a] == arr[b]) n++;\n"
"            }\n"
"        }\n"
"        return n > 0;\n"
"    }\n\n"
""<<std::endl;

    std::chrono::steady_clock::time_point ts1 = std::chrono::steady_clock::now();
    hasDuplicates(unsortedSmallArray, smallArraySize);    
    std::chrono::steady_clock::time_point te1 = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point ts2 = std::chrono::steady_clock::now();
    hasDuplicates(unsortedBigArray, bigArraySize);        
    std::chrono::steady_clock::time_point te2 = std::chrono::steady_clock::now();
    std::cout << "First time: " << std::chrono::duration_cast<std::chrono::microseconds>(te1 - ts1).count() << "[µs]" 
    " Second time: " << std::chrono::duration_cast<std::chrono::microseconds>(te2 - ts2).count() << "[µs]" << std::endl;
    
}



void logarithimic(){
    printf("O(log n) Logarithmic time\n\n");
    printf("O(log n) It's algorithms that in every iteration divide the problem in half\n");
    printf("  Some examples are:\n");
    printf("    - Binary search\n");
    printf("This function will find the index that has value 7 be executed using the first time an array of size %d and then one of size %d, both of them already sorted.\n\n", smallArraySize, bigArraySize);

    std::cout << ""
"    int binarySearch(const int arr[], const int size, int searchNumber){ \n"
"        int half = size/2;\n"
"\n"
"        if (arr[half] == searchNumber){\n"
"            return half;\n"
"        } \n"
"        else if (arr[half] > searchNumber){\n"
"            int narr[half];\n"
"            for (int a = 0; a<half; a++){\n"
"                narr[a] = arr[a];\n"
"            }\n"
"            return binarySearch(narr, half, searchNumber);\n"
"        } \n"
"        else{\n"
"            int narr[half];\n"
"            for (int a = half; a<size; a++){\n"
"                narr[a] = arr[a];\n"
"            }\n"
"            return binarySearch(narr, half, searchNumber);\n"
"        } \n"
"    }\n"
""<<std::endl;

    std::chrono::steady_clock::time_point ts1 = std::chrono::steady_clock::now();
    binarySearch(sortedSmallArray, smallArraySize, 7);   
    std::chrono::steady_clock::time_point te1 = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point ts2 = std::chrono::steady_clock::now();
    binarySearch(sortedBigArray, bigArraySize, 7);
    std::chrono::steady_clock::time_point te2 = std::chrono::steady_clock::now();
    std::cout << "First time: " << std::chrono::duration_cast<std::chrono::microseconds>(te1 - ts1).count() << "[µs]" 
    " Second time: " << std::chrono::duration_cast<std::chrono::microseconds>(te2 - ts2).count() << "[µs]" << std::endl;

}

void linearithmic(){
    printf("O(n log n) Logarithmic time\n\n");
    printf("O(log n) It's algorithms that in every iteration divide the problem in half\n");
    printf("  Some examples are:\n");
    printf("    - Binary search\n");
    printf("This function will sort an array of size %d and then an array of size %d", smallArraySize, bigArraySize);
}

void polynomic(){

}

void exponential(){
    printf("O(2^n) Exponential time\n\n");
    printf("O(2^n) It's algorithms that double it's running time for each new element.\n");
    printf("  Some examples are:\n");
    printf("    - Fibonacci\n");
    printf("    - Power Set\n");
    printf("This function will produce fibonacci numbers, first %d numbers, and then %d numbers.\n", smallArraySize, bigArraySize-20);
    std::cout << ""
"    int fibonacci(int n){\n"
"        if (n <= 1){\n"
"            return n;\n"
"        }\n"
"        return fibonacci(n-1) + fibonacci(n-2);\n"
"    }\n"
""<<std::endl;

    std::chrono::steady_clock::time_point ts1 = std::chrono::steady_clock::now();
    fibonacci(smallArraySize);
    std::chrono::steady_clock::time_point te1 = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point ts2 = std::chrono::steady_clock::now();
    fibonacci(bigArraySize-20);
    std::chrono::steady_clock::time_point te2 = std::chrono::steady_clock::now();

    std::cout << "First time: " << std::chrono::duration_cast<std::chrono::microseconds>(te1 - ts1).count() << "[µs]" 
    " Second time: " << std::chrono::duration_cast<std::chrono::microseconds>(te2 - ts2).count() << "[µs]" << std::endl;

    
}

void factorial(){
    printf("O(n!) Factorial time\n\n");
    printf("O(2^n) It's algorithms that do factorial expressions. So it grows factorially.\n");
    printf("  Some examples are:\n");
    printf("    - Permutations\n");
    printf("This function will do permutations on a char array of %d positions and one of %d.\n", smallArraySize-5, bigArraySize-40);
    std::cout << ""
"    void permutation(std::string a, int start, int end){\n"
"        if (start == end) std::cout<<a<<std::endl;  \n"
"        else{   \n"
"            for (int i = start; i <= end; i++)  \n"
"            {   \n"
"                std::swap(a[start], a[i]);  \n"
"                permutation(a, start+1, end);  \n"
"                std::swap(a[start], a[i]);  \n"
"            }  \n"
"        }  \n"
"    }\n"
""<<std::endl;

    std::chrono::steady_clock::time_point ts1 = std::chrono::steady_clock::now();
    permutation("abcde", 0, 4);
    std::chrono::steady_clock::time_point te1 = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point ts2 = std::chrono::steady_clock::now();
    permutation("abcdefghij", 0, 9);
    std::chrono::steady_clock::time_point te2 = std::chrono::steady_clock::now();

    std::cout << "First time: " << std::chrono::duration_cast<std::chrono::microseconds>(te1 - ts1).count() << "[µs]" 
    " Second time: " << std::chrono::duration_cast<std::chrono::microseconds>(te2 - ts2).count() << "[µs]" << std::endl;

    
}

void enterbigo(int py){
    system("clear");
    gotoxy(0,0);
    switch(py){
        case BIGO_1:
            constant();
            break;
        case BIGO_2:
            logarithimic();
            break;
        case BIGO_3:
            linear();
            break;
        case BIGO_4:
            linearithmic();
            break;
        case BIGO_5:
            quadratic();
            break;
        case BIGO_6:
            polynomic();
            break;
        case BIGO_7:
            exponential();
            break;
        case BIGO_8:
            factorial();
            break;
    }
}

void bigoMenu(){
    gotoxy(3,3);
    printf("O(1)");
    gotoxy(3,4);
    printf("O(log n)");
    gotoxy(3,5);
    printf("O(n)");
    gotoxy(3,6);
    printf("O(n log n) (Missing)");
    gotoxy(3,7);
    printf("O(n^2)");
    gotoxy(3,8);
    printf("O(n^c) (Missing)");
    gotoxy(3,9);
    printf("O(2^n)");
    gotoxy(3,10);
    printf("O(n!)");
}
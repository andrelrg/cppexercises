#include "bigo.h"

int lookIndex(int arr[], int index){
    return arr[index];
}
void bigo1(){
    printf("O(1) Constant Time");
    printf("O(1) It's algorithms that takes the same amount of time regardless of the size of the input.\n");
    printf("  Some examples are:\n");
    printf("    - Look for a especific index inside an array\n");
    printf("    - Print an especific element of an array.\n\n");
    printf("This function will be executed using the first time an array of size 10 and then one of size 50, in both looking for the 7 index. It's expected that the time will be equivalent\n");

    std::cout << ""
"    int lookIndex(int arr[], int index){ \n"
"        return arr[index]; \n"
"    }\n"<<std::endl;

    static int myArray[10] = {1,2,3,4,5,6,7,8,9,10};
    static int myArray2[50] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,28,9,10,1,2,3,4,5,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,28,9,10,1,2,3,41,5};
    
    std::chrono::steady_clock::time_point ts1 = std::chrono::steady_clock::now();
    lookIndex(myArray, 7);
    std::chrono::steady_clock::time_point te1 = std::chrono::steady_clock::now();

    std::chrono::steady_clock::time_point ts2 = std::chrono::steady_clock::now();
    lookIndex(myArray2, 7);
    std::chrono::steady_clock::time_point te2 = std::chrono::steady_clock::now();

    std::cout << "First time: " << std::chrono::duration_cast<std::chrono::microseconds>(te1 - ts1).count() << "[µs]" 
    " Second time: " << std::chrono::duration_cast<std::chrono::microseconds>(te2 - ts2).count() << "[µs]" << std::endl;
}

int maxUnsorted(int arr[], int size){
    int max = -99;
    for(int i = 0; i<size; i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void bigo2(){
    printf("O(n) Linear time");
    printf("O(n) It's algorithms that takes more time, the bigger input. \n");
    printf("  Some examples are:\n");
    printf("    - Get the max value in an array.\n");
    printf("    - Print all the values in an array.\n");
    printf("This function will be executed using the first time an array of size 10 and then one of size 50.\n");


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

    static int myArray[10] = {1,2,3,4,5,6,20,8,9,10};
    static int myArray2[50] = {1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,28,9,10,1,2,3,4,5,1,2,3,4,5,6,7,8,9,10,1,2,3,4,5,6,7,28,9,10,1,2,3,41,5};
    
    std::chrono::steady_clock::time_point ts1 = std::chrono::steady_clock::now();
    maxUnsorted(myArray, 10);
    std::chrono::steady_clock::time_point te1 = std::chrono::steady_clock::now();

    std::chrono::steady_clock::time_point ts2 = std::chrono::steady_clock::now();
    maxUnsorted(myArray2, 50);
    std::chrono::steady_clock::time_point te2 = std::chrono::steady_clock::now();

    std::cout << "First time: " << std::chrono::duration_cast<std::chrono::microseconds>(te1 - ts1).count() << "[µs]" 
    " Second time: " << std::chrono::duration_cast<std::chrono::microseconds>(te2 - ts2).count() << "[µs]" << std::endl;

}

void enterbigo(int py){
    system("clear");
    gotoxy(0,0);
    switch(py){
        case BIGO_1:
            bigo1();
            break;
        case BIGO_2:
            bigo2();
            break;
        case BIGO_3:
            printf("BIGO_3");
            break;
        case BIGO_4:
            printf("BIGO_4");
            break;
        case BIGO_5:
            printf("BIGO_5");
            break;
        case BIGO_6:
            printf("BIGO_6");
            break;
        case BIGO_7:
            printf("BIGO_7");
            break;
        case BIGO_8:
            printf("BIGO_8");
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
    printf("O(n log n)");
    gotoxy(3,7);
    printf("O(n^2)");
    gotoxy(3,8);
    printf("O(n^3)");
    gotoxy(3,9);
    printf("O(2^n)");
    gotoxy(3,10);
    printf("O(n!)");
}
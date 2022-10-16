#include <iostream>
#include "fulcrum.h"
#include "debug.h"
#define SIZE 100000
int main() {
    Debug timer;
    // time test for adding elements at front and removing them using a standard array
    int array[SIZE];
    int size = SIZE;
    for (int i=0; i<size; i++){
        for (int j=i; j>=0; j--){
            array[j+1] = array[j];
        }
        array[0] = i;
    }
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            array[j] = array[j+1];
        }
    }
    std::cout << "PRIMITIVE ARRAY TIMER: \n";
    timer.print();

    Debug mytimer;
    std::fulcrum<int> arr(SIZE);
    for (int i=0; i<SIZE; i++){
        arr.push_front(i);
    }
    for (int i=0; i<arr.size(); i++){
        arr.pop_front();
    }
    std::cout << "\nFULCRUM ARRAY TIMER: \n";
    mytimer.print();
    std::cin >> size;
}

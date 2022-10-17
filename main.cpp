#include <iostream>
#include "fulcrum.h"
#include "debug.h"
#include <vector>
#define SIZE 100000
int main() {
    std::fulcrum<std::string> one(10);
    one.push_front("This is the start of the string");
    std::fulcrum<std::string> two ({"This is what happens", "When you concat two array of arrays together", "Oki-oki!"});
    one.concat(two);
    for (auto i: one){
        std::cout << i << std::endl;
    }




    /*
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

    Debug vector_timer;
    std::vector<int> my_vector;
    for (int i=0; i<SIZE; i++){
        my_vector.insert(my_vector.begin(), i);
    }
    for (int i=0; i<SIZE; i++){
        my_vector.erase(my_vector.begin());
    }

    std::cout << "\nVECTOR ARRAY TIMER: \n";
    vector_timer.print();
    */
    getchar();
}

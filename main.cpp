#include <iostream>
#include "fulcrum.h"
#include "debug.h"
#include <vector>
#define SIZE 100000
using namespace csl;
int main() {
    std::string mystring;
    csl::fulcrum<int> flc;
    flc.push_back(4);
    flc.push_back(2);
    flc.push_back(9);
    for (auto i : flc){
        std::cout << i;
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
    std::vector<int> my_vector(100000);
    for (int i=0; i<SIZE; i++){
        my_vector.insert(my_vector.begin(), i);
    }
    for (int i=0; i<SIZE; i++){
        my_vector.erase(my_vector.begin());
    }

    std::cout << "\nVECTOR ARRAY TIMER: \n";
    vector_timer.print();

    getchar();
     */
}

#include <iostream>
#include "../Dive/Fulcrum/fulcrum.h"
#include "debug.h"
#include <vector>
#define SIZE 100000
using namespace dive;
int main() {
    dive::fulcrum<int> arr(100);
    dive::fulcrum<int> second_arr = {3, 1, 5, 1, 15, 6, 23, 14, 12, 13, 51, 123};
    arr.concat(second_arr);
    arr.array()[2];
    for (auto i: arr){
        std::cout << i << " ";
    }








    /*
    Debug timer;
    // time test for adding elements at front and removing them using a standard m_array
    int m_array[SIZE];
    int size = SIZE;
    for (int i=0; i<size; i++){
        for (int j=i; j>=0; j--){
            m_array[j+1] = m_array[j];
        }
        m_array[0] = i;
    }
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            m_array[j] = m_array[j+1];
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
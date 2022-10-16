#include <iostream>
#include "fulcrum.h"
int main() {
    std::fulcrum<int> arr(10);
    arr.push_front(5);
    std::cout << "CHECK: " << arr.array[0] << std::endl;
    arr.push_front(12);
    std::cout << "CHECK: " << arr.array[0] << std::endl;
    arr.push_front(1);
    std::cout << "CHECK: " << arr.array[0] << std::endl;
    arr.push_front(21);
    std::cout << "CHECK: " << arr.array[0] << std::endl;
    arr.push_front(4);
    std::cout << "CHECK: " << arr.array[0] << std::endl;
    arr.push_front(15);
    std::cout << "CHECK: " << arr.array[0] << std::endl;
    std::cout << "ITERATOR END: " << *(arr.end()-1) << std::endl;
    std::cout << "PRINTING INITIAL ARRAY: " << std::endl;
    for (auto cur = arr.begin() ; cur!=arr.end(); cur++){
        std::cout << *cur << std::endl;
    }
    std::cout << "SORTING ARRAY: " << std::endl;
    arr.sort(false);
    for (int i=0; i<arr.size(); i++){
        std::cout << arr.array[i] << std::endl;
    }




}

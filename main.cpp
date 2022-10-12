#include <iostream>
#include "fulcrum.h"
int main() {
    std::fulcrum arr(5);
    arr.enqueue(5);
    arr.push(3);
    arr.push(2);
    arr.enqueue(4);
    std::cout << arr.pop() << std::endl;
    for (int i=0; i<arr.arrsize(); i++){
        std::cout << arr.array[i] << std::endl;
    }
    return 0;
}

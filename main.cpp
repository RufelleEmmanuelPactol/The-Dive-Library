#include <iostream>
#include "fulcrum.h"
int main() {
    int temp []= {3, 4, 5, 1, 2, 3, 5, 1};
    std::fulcrum arr(temp, 8);
    for (int i=0; i<arr.arrsize(); i++){
        std::cout << arr.array[i] << std::endl;
    }
    return 0;
}

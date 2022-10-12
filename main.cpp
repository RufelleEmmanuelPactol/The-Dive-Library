#include <iostream>
#include "fulcrum.h"
int main() {
    std::fulcrum<int> arrone(10);
    std::fulcrum<int> arrtwo(5);
    for (int i=0; i<5; i++){
        arrone.push_back(5+i);
    }
    for (int i=0; i<5; i++){
        arrtwo.push_back(20+i);
    }
    arrone.concat(arrtwo);
    for (int i=0; i<10; i++){
        std::cout << arrone.array[i] << std::endl;
    }


}

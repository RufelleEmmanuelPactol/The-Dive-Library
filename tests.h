
#include "fulcrum.h"
#include <iostream>

void result_printer(bool result){
    if (result){
        std::cout << "PASSED\n";
    } else {
        std::cout << "FAILED\n";
    }
}

bool test_one (dive::fulcrum<int> fulc){
    for (int i=0; i<9000; i++){
        fulc.push_back(rand());
    }
    return true;
}

bool test_two (dive::)

void run_test(){
    dive::fulcrum<int> fulc(10000);
    std::cout<< "test case 1 [ random inserts ]: ";
    result_printer(test_one(fulc));
    std::cout << "test case 2 [ concat ]: ";

}

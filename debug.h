//
// Created by Rufelle on 17/10/2022.
//

#ifndef UNTITLED12_DEBUG_H
#define UNTITLED12_DEBUG_H

#include <chrono>
#include <unistd.h>
#include <iostream>

class Debug {
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
public:
    Debug(){
        start = std::chrono::steady_clock::now();
    }

    void print(){
        end = std::chrono::steady_clock::now();
        std::cout << "Elapsed time in nanoseconds: "
             << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count()
             << " ns" << std::endl;

        std::cout << "Elapsed time in microseconds: "
             << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
             << " µs" << std::endl;

        std::cout << "Elapsed time in milliseconds: "
             << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
             << " ms" << std::endl;

        std::cout << "Elapsed time in seconds: "
             << std::chrono::duration_cast<std::chrono::seconds>(end - start).count()
             << " sec";
    }



};


#endif //UNTITLED12_DEBUG_H

/*
 * Created by Rufelle Emmanuel Pactol
 * This module is part of the DIVE CPP libraries
 *
 * This module contains the fulcrum array library,
 * (c) 2022, Dive Libraries of CubeClub Inc.
 *
 * This library is free to use under the premise that
 * the products herein are assumed to be free of warranty
 * and do not guarantee of fitness for a particular purpose.
 *
 * This library is free to use and can be reused for any purpose
 * given that this disclaimer tag will not be removed.
 */

#ifndef UNTITLED12_FULCRUM_ERRORS_H
#define UNTITLED12_FULCRUM_ERRORS_H

#include <error.h>
#include <stdexcept>

namespace dive{

    /*
     * Sets the warning levels for all
     * dive modules
     */
    enum WARNINGS{
        OFF, ON
    };




    auto ArrayIndexOutOfBounds(int max_index, int index){
        return std::out_of_range("\tThrown by dive::fulcrum\n\t\t\tInvalid index access, where you are accessing range [" + std::to_string(index) + "] when accessible range is [0 - " + std::to_string(max_index-1) + "]");
    }

    namespace m_private {
        void m_DepracatedWarning(std::string method){
            throw std::invalid_argument("\tThrown by dive::fulcrum\n\t\t\tUse of deprecated method. To turn off fulcrum warnings, use dive::fulcrum::warnings(dive::OFF)\n\t\t\tThrown with use of method: " + method);
        }
    }
    void DepracatedWarning (bool assist, std::string method){
        if (!assist){
            return;
        } m_private::m_DepracatedWarning(method);
    }

    void InvalidReserve (int init, int req){
        throw std::invalid_argument("\tThrown by dive::fulcrum\n\t\t\tInvalid allocate behavior. Allocating with requested reserve size of " +
                                            std::to_string(req) + " but initial size is " + std::to_string(init + '.')
                                            + "\n\t\t\tPlease ensure that requested reserve size is smaller than actual array size.\n\t\t\tTo get the full size,"
                                              + " use the dive::fulcrum::size() method.");
    }

    void ArrayWarning(bool assist){

        if (assist){
            std::cerr << "Warning [INVOKED METHOD USE UNDEFINED]:\n\t\tWith use of method dive::fulcrum::array():\n\t\t\tUsing this method is not encouraged as this can break the fulcrum array object.\n\t\t\tThis method does not provide memory safety.\n";
        }
    }

    void PopException(){
        throw std::out_of_range("\tThrown by dive::fulcrum\n\t\t\tInvalid pop behavior. No more elements to pop.");
    }

    void TopException(){
        throw std::out_of_range("\tThrown by dive::fulcrum\n\t\t\tCannot invoke dive::fulcrum::top(). No element to return.");
    }
}


#endif //UNTITLED12_FULCRUM_ERRORS_H

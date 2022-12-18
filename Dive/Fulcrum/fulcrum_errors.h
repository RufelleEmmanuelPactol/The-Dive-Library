//
// Created by Rufelle on 17/12/2022.
//

#ifndef UNTITLED12_FULCRUM_ERRORS_H
#define UNTITLED12_FULCRUM_ERRORS_H

#include <error.h>
#include <stdexcept>
namespace dive{
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
}


#endif //UNTITLED12_FULCRUM_ERRORS_H

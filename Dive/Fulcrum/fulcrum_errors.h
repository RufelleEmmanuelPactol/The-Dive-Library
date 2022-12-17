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
        void m_DepracatedWarning(){
            throw std::invalid_argument("\tThrown by dive::fulcrum\n\t\t\tUse of deprecated method. To turn off fulcrum warnings, use dive::fulcrum::warnings(false)");
        }
    }
    void DepracatedWarning (bool assist){
        if (!assist){
            return;
        } m_private::m_DepracatedWarning();
    }
}


#endif //UNTITLED12_FULCRUM_ERRORS_H

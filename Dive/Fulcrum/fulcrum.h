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

#ifndef fulcrum_h
#define fulcrum_h
#include <functional>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <memory>
#include "fulcrum_errors.h"
#define let auto const // undefined at end for safety
#define func auto constexpr // undefined at end for safety

namespace dive{ // Cube Standard Library



    //template allows for multiple data types
    /*
         * The fulcrum m_array is a special type of m_array
         * that allows for faster operations, wherein
         * any operation (aside from resizing)
         * will take at MOST O(log n) time meanwhile
         * basic operations (push_front and push_back)
         * will take O(1), with basic removes
         * also taking O(1)
         */
    template <typename T> class fulcrum {

    private:

        static constexpr float R = 1.0/3.0;
        size_t m_arrsize; // the size of the full array
        T * m_container; // the reallocated base m_array
        size_t positive; // number of positions unfilled on the positive index before reallocating
        size_t negative; // number of positions unfilled on the negative index before reallocating
        size_t m_index; // index to past-the-last index
        bool m_warning = true;
        int m_cached_pos; //cache values counting the adds and removes of the positive side
        int m_cached_neg;//cache values counting the adds and removes of the megative side
        bool m_thread = false;

    private:


        /*
         * Principle of realloc:
         * it must be where the number of elements is less than round(1/3 of the capacity)
         * for example, where the max capacity is 10, the number of elements must not be less than or equal to four, where if it is,
         * we reduce the capacity of the m_array
         * the new size of the m_array should be (round(R*capacity))*2
         * the starting point of the m_array should be after the 15%
         * the ending point of the m_array should be right before the last 15%
         * positive, negative = (15% of size_of_array)
         *
         */
        func decrease(){
            if (m_index<=round(m_arrsize * (R))){

            }
            return;
        }
        func increase(){
            return;
        }



    private: T * m_array; //pointer to index zero
    void __init_to_zero__ (){
        m_index = 0;
        m_cached_neg = 0;
        m_cached_pos = 0;
    }

    /*
     * Helper functions for reallloc
     */
    int floor_quart(){
        return floor(capacity()/4);
    }
    int max_quart(){
        return ceil(capacity()/4);
    }


    public: // HEADER GUARDS AND STANDARD DICTATORS
            /*
             * Warning! We do not recommend using the array
             * object. Not only is it dangerous, but it can also
             * disrupt this object's behavior.
             * To be deprecated.
             *
             */
        T * array (){
            ArrayWarning(m_warning);
            DepracatedWarning(m_warning, "array()");
            return m_array;
        }

        /*
         * This method allows you to set the warning levels of the object.
         * When fulcrum's warning level is set to dive::ON, using
         * deprecated methods will cause an error to be thrown.
         *
         * When using namespace dive, this method can be shortened to
         * array->warnings(ON) or array->warnings(OFF)
         *
         * if not, use array->warnings(dive::ON) or array->warnings(dive::OFF)
         * to toggle the warning levels
         *
         * params(WARNINGS warn):
         *      set to true to raise warning levels when using deprecated methods
         *      set to false when you want to use deprecated methods
         */
        constexpr void warnings(WARNINGS warn){
            if (warn==ON){
                m_warning = true;
            } else {
                m_warning = false;
            }
        }

        /*
         * As of fulcrum 1.1.0, multithreading is EXPERIMENTAL
         *
         * params:
         *      void
         *
         * usage:
         *      dive::fulcrum::set_multithreading() = false;
         *      dive::fulcrum::set_multithreading() = true;
         *
         * returns a boolean reference which can be set to a particular value.
         * set thread_status to true if you want multithreading to be
         * enabled. Currently, the following methods are planned to support
         * multi-threading:
         *
         *      concat();
         *      resize_up(); [private method]
         *      resize_down(); [private method]
         *      fulcrum({<initializer lists>}) [is a constructor]
         *      fulcrum(<T*>, <size_t>) [is a constructor]
         *      fulcrum = [assignment operator]
         */
        constexpr bool& set_multithreading(){
            return m_thread;
        }

        /*
         * returns the multithreading status of the object.
         * returns true if multithreading is on and false if not.
         */
        constexpr bool is_multithreaded(){
            return m_thread;
        }


        // OPERATORS
        auto operator[](int n){
            return get(n);
        }
        auto operator=(std::initializer_list<T> inputs){
            int n = inputs.size();
            m_arrsize = n * 2;
            positive = 0;
            negative = n;
            m_container = new T[m_arrsize];
            m_array = m_container + n;
            m_index = n;
            for (int i=0; i<n; i++){
                m_array[i] = inputs.begin()[i];
            }
        }




        /*
         * The default constructor of the fulcrum object. Has no params.
         * It has a default size of 5, but it can hold at max 10, where
         * tail-inclined-additions and head-inclined additions are both
         * of equal value.
         *
         * inclined additions are of the following:
         *      array capacity is 20, when capacity constructor is set to 10
         *      additions to tail will be tail-inclined additions
         *      moreover, additions to indexes >n/2 (where n is the total no. of elements)
         *      are all tail-inclined additions.
         *
         *      On the other hand, additions to tail and addition to indexes where <=n/2
         *      are all head-inclined additions.
         *
         */
        fulcrum(){
            m_arrsize = 5 * 2;
            positive = 5;
            negative = 5;
            m_container = new T[m_arrsize];
            m_array = m_container + 5;
            __init_to_zero__();
        }



        fulcrum(std::initializer_list<T> inputs){ // where you can add the m_array initialization body as a parameter (i.e., fulcrum<int> arr({4,3,2})
            int n = inputs.size();
            m_arrsize = n * 2;
            positive = 0;
            negative = n;
            m_container = new T[m_arrsize];
            m_array = m_container + n;
            m_index = n;
            for (int i=0; i<n; i++){
                m_array[i] = inputs.begin()[i];
            }
        }

        /*
        * The reserve constructor of the fulcrum object.
        * params (int size):
        *      size determines the size of the array, where size = 10,
        *      you can have at most 10 of the same-inclined additions
        *
        * inclined additions are of the following:
        *      array capacity is 20, when capacity constructor is set to 10
        *      additions to tail will be tail-inclined additions
        *      moreover, additions to indexes >n/2 (where n is the total no. of elements)
        *      are all tail-inclined additions.
        *
        *      On the other hand, additions to tail and addition to indexes where <=n/2
        *      are all head-inclined additions.
        *
        */
        fulcrum(int reserve){
            m_arrsize = reserve * 2;
            positive = reserve;
            negative = reserve;
            m_container = new T[m_arrsize];
            m_array = m_container + reserve;
            __init_to_zero__();
        }

        fulcrum(T * arr, size_t n){ //transforms an m_array into a fulcrum m_array,
            m_arrsize = n * 2; //where n is the last element to be added and is NOT the max capacity of the last m_array
            positive = 0;
            negative = n;
            m_container = new T[m_arrsize];
            m_array = m_container + n;
            for (int i=0; i<n; i++){
                *(m_array + i) = *(arr + i);
            }
            m_index = n;
            m_cached_neg = 0;
            m_cached_pos = 0;
        }

        /*
         * This method adds element of typename T at the front of the m_array
         */
        bool push_front (T n){ // adds element at the front
            m_array = m_array - 1;
            m_index++;
            negative--;
            *(m_array) = n;
            m_cached_pos++;
            return true;
        }


        bool push_back (T n){ // adds element at the back
            positive--;
            *(m_array + m_index) = n;
            m_index++;
            m_cached_neg++;
            return true;
        }

        bool reserve(int requested_reserve){
            if (requested_reserve<=m_index){
                InvalidReserve(m_index, requested_reserve);
            }
            auto size = m_index * 2;
            auto quarter = size / 4;
            auto m_allocate = new T[size];
            auto m_start = m_allocate + quarter;
            memcpy(m_start, m_array, m_index*sizeof(T));
            auto _m_index = m_start + m_index;
            positive = quarter;
            negative = quarter;
            m_array = m_start;
            m_container = m_allocate;
            m_arrsize = size;
            return true;
        }


        /*
         * This method returns the used-up size in the fulcrum array
         */
        int size (){
            return m_index;
        }

        /*
         * This method returns all the available spaces in the fulcrum array.
         * This includes non-utilized buckets
         */
        int capacity (){
            return m_arrsize;
        }

        /*
         * returns the amount of free capacity available in the current
         * iteration of the arra
         */
        int free_capacity(){
            return positive + negative;
        }

        /*
         * This method returns the last element and removes it from the array.
         */
        T pop (){
            if (m_index==0){
                PopException();
                return top();
            }
            T temp = *(m_array + m_index - 1);
            m_index--;
            positive++;
            m_cached_pos--;
            return temp;
        }

        /*
         * This method returns the first element and removes it from the array.
         * Params:
         *      (bool direction)
         *      where bool true = pops at front
         *      where bool false = pops at back
         */
        T pop(bool direction){ // removes the element at the front
            if(!direction){
                return pop();
            }
            if (m_index==0){
                PopException();
                return top();
            }
            T temp = *(m_array);
            m_index--;
            negative++;
            m_array = m_array + 1;
            m_cached_neg--;
            return temp;
        }

        bool replace(int indexAt, T element){ //replaces element at indexAt with the element specified at T element
            DepracatedWarning(m_warning, "replace(int, T)");
            T temp = m_array[indexAt];
            m_array[indexAt] = element;
            return true;
        }

        void concat (dive::fulcrum<T>& fulcrum_two){ // concats the start of fulcrum_2 from the end of fulcrum_1
            if (m_thread){
                std::cout << "threading enabled";
                return;
            }

            for (auto i : fulcrum_two){
                push_back(i);
            }
            return;
        }


        T* begin (){ // iterator

            return m_array;
        }

        T* end (){ // iterator
            return m_array + m_index;
        }

        constexpr void sort(void){ // overload for sort, where it automatically sorts in ascending
            std::sort(this->begin(), this->end());
        }

        constexpr void sort(bool method){ // sorts, and if method = true, sorts in ascending, descending if false
            if (method){
                std::sort(this->begin(), this->end());
            } else{
                std::sort(this->begin(), this->end(), std::greater<T>());
            }
        }

        int get_memory_size (){
            return sizeof(T) * m_arrsize;
        }


        // setter methods for setting at particular index,
    private:
        class element_construct;




    public:
        /*
         * To be used with the 'to' method. Returns an element_construct
         * object which has the to method. This allows to set the value of a
         * particular element at specified index. Returns smart pointers.
         *
         * Syntax:
         * sample_arr.set(<index>).to(<value>);
         */
        element_construct set (int index){
            if (index>this->m_index || index < 0){
                throw ArrayIndexOutOfBounds(this->m_index, index);
            }
            element_construct temp(index, this, true);
            return temp;
        }
        /*
         * To be used with the 'to' method. Returns an element_construct
         * object which has the to method. This allows to set the value of a
         * particular element at specified index. Returns smart pointers.
         *
         * Syntax:
         * sample_arr->set_value(<index>)->to(<value);
         */
        element_construct*  set_value (int index){
            if (index>this->index || index < 0){
                throw ArrayIndexOutOfBounds(this->index, index);
            }

            auto temp = new element_construct(index, this);
            return temp;
        }

        /*
         * Gets the value at a specified index. The returned value is mutable,
         * and doing the following syntax:
         *
         *      array->get(2) = 12;
         *
         * will replace the element at index 2 with the value 12. To use this
         * method without the risk of mutating the value of the array, use the
         * at() method.
         */
        T& get (int index){
            if (index>=this->m_index){
                throw ArrayIndexOutOfBounds(this->m_index, index);
            } else if (index<0){
                throw ArrayIndexOutOfBounds(this->m_index, index);
            }
            return *(m_array + index);
        }


        /*
         * Returns the value at a specified index. The returned value is immutable,
         * and doing the following syntax:
         *
         *      array->get(2) = 12;
         *
         * will not replace the element at index 2 with the value 12. To use this
         * method with mutation enabled, use the get() method. Moreover, to explicitly
         * set the value without explicitly recovering the value, use the set().to() method
         */
        T at (int index){
            return get(index);
        }

    private:
        class element_construct{
            friend class fulcrum<T>;
            bool deleter{};

            int * elem_locator;
        public:
            /*
             * Replaces the element from the set method to the specified
             * element.
             *
             * params: (T value)
             *      value will replace the element at the index specified int
             *      the dive::fulcrum::set() method
             */
            void to (int value){
                *elem_locator = value;
                if (!deleter){
                    delete this;
                }

            }

            ~element_construct()= default;
        protected:
            element_construct(int num, fulcrum<T> * instance){
                elem_locator = instance->m_array + num;
                deleter = false;
            }
            element_construct(int num, fulcrum<T> * instance, bool deleter){
                elem_locator = instance->m_array + num;
                this->deleter = deleter;
            }

        };

    private:
        class move_object{
        private:
            T * m_move_position;

        public:
            move_object(T * ptr){
                ptr = m_move_position;
            }

            bool to (int index){
                return true;
            }
        };
    public:
        // moves element x at position y to position z, moving respective elements
        move_object move (int index){
            return move_object(m_array + index);
        }
        /*
         * finds the index of the first instance of an element, returns -1 if not found
         * params: (T value)
         *      'value' is the object to find
         * returns: (int)
         *      the return value is the index of the element
         */
        int find (T value){
            return -1;
        }

        /*
         * finds the index of the first instance of an element, returns -1 if not found
         * params: (T value, int instance)
         *      'value' is the object to find
         *      'instance' is the nth instance to find. i.e., find(5, 2) in arr [1, 2, 5, 3, 5]
         *          returns 4 since that is the index of the second instance
         * returns: (int)
         *      the return value is the index of the element
         */
        int find (T value, int instance){
            return -1;
        }

        T& top(){
            if (m_index == 0){
                TopException();
            }
          return *(m_array + m_index - 1);
        }

        T& bottom(){
            return *m_array;
        }



    };



}

#undef let
#undef func
#endif

//
// Created by Rufelle on 12/10/2022.
//

#ifndef fulcrum_h
#define fulcrum_h
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>


namespace csl{ // Cube Standard Library


    //template allows for multiple data types
    /*
         * The fulcrum array is a special type of array
         * that allows for faster operations, wherein
         * any operation (aside from resizing)
         * will take at MOST O(log n) time meanwhile
         * basic operations (push_front and push_back)
         * will take O(1), with basic removes
         * also taking O(1)
         */
    template <typename T> class fulcrum {

        const float R = 1.0/3.0;
        int arrsize;
        T * array;
        T * basearray; // the reallocated base array
        int positive; //number of positions unfilled on the positive index before reallocating
        int negative; //number of positions unfilled on the negative index before reallocating
        int index; //pointer to past-the-last index



        /*
         * Principle of realloc:
         * it must be where the number of elements is less than round(1/3 of the capacity)
         * for example, where the max capacity is 10, the number of elements must not be less than or equal to four, where if it is,
         * we reduce the capacity of the array
         * the new size of the array should be (round(R*capacity))*2
         * the starting point of the array should be after the 15%
         * the ending point of the array should be right before the last 15%
         * positive, negative = (15% of size_of_array)
         *
         */
        void decrease(){
            if (index<=round(arrsize*(R))){

            }
            return;
        }
        void increase(){
            return;
        }

    public:

    /*public:
        T * array; //pointer to index zero
        class iterator{
        private:
            static T*it;
        public:
            T* operator=(const T*ptr){
                this->it = ptr;
                return this;
            }
        }; */

        fulcrum(){ // base case, where it creates a fulcrum array with size 5, but with maxsize 10
            arrsize = 5*2;
            positive = 5;
            negative = 5;
            basearray = new T[arrsize];
            array = basearray+5;
            index = 0;
        }



        fulcrum(std::initializer_list<T> inputs){ // where you can add the array initialization body as a parameter (i.e., fulcrum<int> arr({4,3,2})
            int n = inputs.size();
            arrsize = n*2;
            positive = 0;
            negative = n;
            basearray = new T[arrsize];
            array = basearray+n;
            index = n;
            for (int i=0; i<n; i++){
                array[i] = inputs.begin()[i];
            }
        }

        fulcrum(int n){ // creates a fulcrum array with size n
            arrsize = n*2;
            positive = n;
            negative = n;
            basearray = new T[arrsize];
            array = basearray+n;
            index = 0;
        }

        fulcrum(T * arr, int n){ //transforms an array into a fulcrum array,
            arrsize = n * 2; //where n is the last element to be added and is NOT the max capacity of the last array
            positive = 0;
            negative = n;
            basearray = new T[arrsize];
            array = basearray + n;
            for (int i=0; i<n; i++){
                *(array + i) = *(arr + i);
            }
            index = n;
        }

        T push_front (T n){ // adds element at the front
            array = array-1;
            index++;
            negative--;
            *(array) = n;
            return n;
        }


        T push_back (T n){ // adds element at the back
            positive--;
            *(array+index) = n;
            index++;
            return n;
        }

        int size (){ // returns the size
            return index;
        }

        T pop_back (){ // removes the element at the back
            T temp = *(array+index-1);
            index--;
            positive++;
            return temp;
        }

        T pop_front(){ // removes the element at the front
            T temp = *(array);
            index--;
            negative++;
            array = array+1;
            return temp;
        }

        T replace(int indexAt, T element){ //replaces element at indexAt with the element specified at T element
            T temp = array[indexAt];
            array[indexAt] = element;
            return temp;
        }

        void concat (csl::fulcrum<T> fulcrum_two){ // concats the start of fulcrum_2 from the end of fulcrum_1
            for (auto i : fulcrum_two){
                push_back(i);
            }
            return;
        }

        T * begin (){ // iterator

            return array;
        }

        T * end (){ // iterator
            return array+index;
        }

        void sort(void){ // overload for sort, where it automatically sorts in ascending
            std::sort(this->begin(), this->end());
        }

        void sort(bool method){ // sorts, and if method = true, sorts in ascending, descending if false
            if (method){
                std::sort(this->begin(), this->end());
            } else{
                std::sort(this->begin(), this->end(), std::greater<T>());
            }
        }

        int getmemorysize (){
            return sizeof(T)*arrsize;
        }




    };

}


#endif

//
// Created by Rufelle on 12/10/2022.
//

#ifndef fulcrum_h
#define fulcrum_h


namespace std{
    template <typename T>
    //template allows for multiple data types
    class fulcrum {
        int arrsize;
        T * basearray; // the reallocated base array
        int positive; //number of positions unfilled on the positive index before reallocating
        int negative; //number of positions unfilled on the negative index before reallocating
        int index; //pointer to last filled index
    public:
        T * array; //pointer to index zero

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

        void concat (std::fulcrum<T> fulcrum_two){ // concats the start of fulcrum_2 from the end of fulcrum_1
            int size2 = fulcrum_two.size();
            int temp_i = 0;
            for (int i=index; i<index+size2; i++){
                //to-do, check if the size if full and realloc if needed
                array[i] = fulcrum_two.array[temp_i];
                temp_i++;
            }
            return;
        }
    };
}


#endif

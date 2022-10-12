//
// Created by Rufelle on 12/10/2022.
//

#ifndef fulcrum_h
#define fulcrum_h

namespace std{
    class fulcrum {
        int size;
        int * basearray; // the reallocated base array
        int positive; //number of positions unfilled on the positive index before reallocating
        int negative; //number of positions unfilled on the negative index before reallocating
        int index; //pointer to last filled index
    public:
        int * array; //pointer to index zero
        fulcrum(int n){
            size = n*2;
            positive = n;
            negative = n;
            basearray = new int[size];
            array = basearray+n+1;
            index = 0;
        }

        int enqueue (int n){
            array = array-1;
            index++;
            negative--;
            *(array) = n;
            return n;
        }

        int push (int n){
            positive--;
            *(array+index) = n;
            index++;
            return n;
        }

        int arrsize (){
            return index;
        }

        int pop (){
            int temp = *(array+index-1);
            index--;
            positive++;
            return temp;
        }
    };
}


#endif fulcrum_h

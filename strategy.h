#ifndef __STRATEGY_H__
#define __STRATEGY_H__

#include "container.h"

class Sort {
    public: 
        /* Constructors */
        Sort();

        /* Pure Virtual Functions */
        virtual void sort(Container* container) = 0;
};

class SelectionSort: public Sort
{
    public:
//        SelectionSort() : Sort(){}
        void sort(Container*);
};

class BubbleSort: public Sort
{
    public:
//        BubbleSort(): Sort(){}
        void sort(Container*);
};

 
#endif // __STRATEGY_H__

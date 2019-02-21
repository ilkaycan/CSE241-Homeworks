#include "Iterator.h"
#include <vector>
namespace GTU{

    //Constructor
    template <typename T, typename C>
    Iterator<T, C>::Iterator(C &containerVariable): container(containerVariable){
       // container = containerVariable;
        sizeCheck = 1;
        it = containerVariable.begin();
    }

    //This function returns true if iterator has a next
    template <typename T, typename C>
    bool Iterator<T, C>::hasNext(void){
        if(container.size() == 0){
            return false;
        }else if(container.size() != sizeCheck){
            return true;
        } else {
            return false;
        }
    }

    //This function makes iterator move forward and returns the element

    template <typename T, typename C>
    T Iterator<T, C>::next(void) throw(std::out_of_range){
        if(this->hasNext()) {
            ++it;
            ++sizeCheck;
        } else {
            throw std::out_of_range("Next element does not exist!!");
        }

        return *it;
    }

    //This function removes the last element returned by this iterator

    template <typename T, typename C>
    void Iterator<T, C>::remove(void) throw(std::length_error){
        if(container.size()!=0){
            container.erase(it);
        } else {
            throw std::length_error("This collection is empty; You can not remove an element!!\n");
        }
    }

    //This function returns the current element returned by this iterator
    template <typename T, typename C>
    T Iterator<T,C>::elementgetter(void) throw(std::out_of_range){

        if(0 == container.size()){
            throw std::out_of_range("This container is empty!!");
        }
        return *it;
    }



}


#include "LinkedList.h"
#include <iostream>
#include <algorithm>

namespace GTU {

    //Constructors

    template<typename T, typename C>
    LinkedList<T, C>::LinkedList(void) {
        /* INTENTIONALLY EMPTY */
    }

    template<typename T, typename C>
    LinkedList<T, C>::LinkedList(C &c) {
        auto it = c.begin();
        for (int i = 0; i < c.size(); ++i) {
            data.insert(data.end(), *(it));
            ++it;
        }
        this->sortList();

    }

    template<typename T, typename C>
    LinkedList<T, C>::LinkedList(int initialCapacity) {
        /* INTENTIONALLY EMPTY */
    }

    //Returns the value at the begin of this collection

    template<typename T, typename C>
    T LinkedList<T, C>::element(){
        auto i = data.begin();
        return *i;
    }

    //Adds given value to end of this collection

    template<typename T, typename C>
    bool LinkedList<T, C>::offer(T e){
        this->add(e);
        return 0;
    }

    //Removes the head

    template<typename T, typename C>
    T LinkedList<T, C>::poll(void)throw(std::out_of_range){
        if(this->isEmpty()){
            throw std::out_of_range("This collection is empty!!\n");
        } else {
            auto i = data.begin();
            data.erase(i);
        }
        return *(data.begin());
    }

    //This function creates an Iterator for collection

    template<typename T, typename C>
    Iterator<T, C> LinkedList<T, C>::iterator(void) {
        //Iterator<T, C> it = Iterator<T,C>(data);
        return Iterator<T, C>(data);
    }

    //Adds given element to the end of the collection

    template <typename T, typename C>
    bool LinkedList<T, C>::add(T e){

        data.insert(data.end(), e);
        this->sortList();

        //if(emptyCapacity == 0) {
        //} else{
        //   data[data.size() - emptyCapacity] = e;
        //   --emptyCapacity;
        // }
        return true;
    }

    //Adds all of given collection to the end of this collection

    template <typename T, typename C>
    bool LinkedList<T, C >::addAll(Collection<T, C> &c){
        for(int i = 0 ; i < c.size() ; ++i) {
            this->add(c[i]);
        }
        return true;
        /*auto i = c.iterator();

        if(!(c.isEmpty())) {

            while (i.hasNext()) {
                this->add(i.elementgetter());
                i.next();
            }
            this->add(i.elementgetter());
        }
        return true;*/
    }

    //Makes size of this collection empty

    template <typename T, typename C>
    void LinkedList<T, C>::clear(){
        data.clear();
    }

    //Checks if given element exist in this collection

    template <typename T, typename C>
    bool LinkedList<T, C>::contains(T e){
        for(auto i = data.begin(); i != data.end(); ++i){
            if( e == *i){
                return true;
            }
        }

        return false;
    }

    //Checks if all of given collection exists in this collection

    template <typename T, typename C>
    bool LinkedList<T, C>::containsAll(Collection<T, C > &c) {

        for(int i = 0; i < c.size(); ++i){
            if(!(this->contains(c[i]))) {
                return false;
            }
        }

        return true;
/*  //Alternative code
               auto i = c.iterator();

        if(!(c.isEmpty())) {

            while (i.hasNext()) {
                if(this->contains(i.elementgetter())) {

                    return false;
                }
                i.next();
            }
            if(this->contains(i.elementgetter())) {
                return false;
            }
        }*/
    }

    //Checks if this collection is empty

    template<typename T, typename C>
    bool LinkedList<T, C>::isEmpty(void) {
        if (data.size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    //Removes the given element if it exists in this collection

    template <typename T, typename C>
    bool LinkedList<T, C>::remove(T e)throw(std::invalid_argument) {
        if(this->contains(e)){
            auto i = data.begin();
            if(e == *i) {
                data.erase(i);
                return true;
            } else{
                throw std::invalid_argument("This element can not be removed because this collection is FIFO\n");
            }
        } else {
            throw std::invalid_argument("This element does not exist!!\n");
        }
    }

    //Removes all of the given element if it exists in this collection

    template <typename T, typename C>
    bool LinkedList<T, C>::removeAll(Collection<T, C> &c){
  /*      for(int i = 0; i < c.size(); ++i){
            this->remove(c[i]);
        }
*/
  //I use iterator to make sure that Iterator it works
        auto i = c.iterator();

        if(!(c.isEmpty())) {

            while (i.hasNext()) {
                remove(i.elementgetter());
                i.next();
            }
            this->remove(i.elementgetter());
        }
        return true;
    }

    //Returns intersection

    template <typename T, typename C>
    LinkedList<T, C>& LinkedList<T, C>::retainAll(Collection<T, C > &c){
        int j;
        auto it = c.iterator();
        static LinkedList<T, C> temp;
		//To make temp empty (it is static) i call clear function
		temp.clear();
        if(!(c.isEmpty())) {
            for (auto i = data.begin(); i != data.end(); ++i) {
                if(c.contains(*i)){
                    temp.add(*i);
                }
            }
        }
        return temp;
    }

    //Returns size of this collection

    template <typename T, typename C>
    int LinkedList<T, C>::size(void){
        return data.size();
    }

    //[] overloading to reach elements of this collection

    template <typename T, typename C>
    T LinkedList<T, C>::operator [](int i){
        auto it = data.begin();
        for( int j = 0; j < i; ++j ){
            ++it;
        }
        return *it;
    }

    //Sorts lists

    template <typename T, typename C>
    void LinkedList<T, C>::sortList(void){
        std::vector<T> temp;

        for (auto i = data.begin(); i != data.end(); ++i){
            temp.push_back(*i);
        }

        data.clear();

        std::sort(temp.begin(), temp.end());

        for (auto i = 0 ; i < temp.size() ; ++i){
            data.insert(data.end(), temp[i]);
        }    }
}

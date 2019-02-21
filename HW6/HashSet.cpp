#include "HashSet.h"
#include <iostream>
using std::cout;
using std::endl;
using std::iterator;
namespace GTU{

    //Constructors

    template <typename T, typename C>
    HashSet<T, C>::HashSet(void){
        /* INTENTIONALLY EMPTY */
    }

    template <typename T, typename C>
    HashSet<T, C>::HashSet(C &c){
        auto it = c.begin();
        for(int i = 0; i< c.size(); ++i) {
            if (!(this->contains(*it))) {
                data.insert(data.end(), *(it));
                ++it;
            }
        }
    }

    template <typename T, typename C>
    HashSet<T, C>::HashSet(int initialCapacity){
        /* INTENTIONALLY EMPTY */
    }

    //This function creates an Iterator for collection

    template <typename T, typename C>
    Iterator<T, C> HashSet<T, C>::iterator(void){
        //Iterator<T, C> it = Iterator<T,C>(data);
        return Iterator<T,C>(data);
    }

    //Adds given element to the end of the collection

    template <typename T, typename C>
    bool HashSet<T, C>::add(T e)throw(std::invalid_argument){
        //if(emptyCapacity == 0) {
        if(!(this->contains(e))){
            data.insert(data.end(), e);
        }else {
            throw std::invalid_argument("This value is already exists in hashset");
        }
        //} else{
        //   data[data.size() - emptyCapacity] = e;
        //   --emptyCapacity;
        // }
        return true;
    }

    //Adds all of given collection to the end of this collection

    template <typename T, typename C>
    bool HashSet<T, C >::addAll(Collection<T, C> &c){

        for(int i = 0 ; i < c.size() ; ++i) {
            this->add(c[i]);
        }
        return true;

    }

    //Makes size of this collection empty

    template <typename T, typename C>
    void HashSet<T, C>::clear(){
        /*for(auto i = data.begin(); i != data.end(); ++i){
            data.erase(i);
        }*/
        data.clear();
    }

    //Checks if given element exist in this collection

    template <typename T, typename C>
    bool HashSet<T, C>::contains(T e){
        for(auto i = data.begin(); i != data.end(); ++i){
            if( e == *i){
                return true;
            }
        }

        return false;
    }

    //Checks if all of given collection exists in this collection

    template <typename T, typename C>
    bool HashSet<T, C>::containsAll(Collection<T, C > &c) {

        for(int i = 0; i < c.size(); ++i){
            if(!(this->contains(c[i]))) {
                return false;
            }
        }

        return true;
 /*       auto i = c.iterator();
        if(c.size()==1){
            if(!(this->contains(i.elementgetter()))) {
                return false;
            }
        }
        while(i.hasNext()){
            if(!(this->contains(i.elementgetter()))) {
                return false;
            }
            i.next();
        }
        if(!(this->contains(i.elementgetter()))) {
            return false;
        }

        return true;*/
    }

    //Checks if this collection is empty

    template<typename T, typename C>
    bool HashSet<T, C>::isEmpty(void) {
        if (data.size() == 0) {
            return true;
        } else {
            return false;
        }
    }

    //Removes the given element if it exists in this collection

    template <typename T, typename C>
    bool HashSet<T, C>::remove(T e)throw(std::invalid_argument){
        if(this->contains(e)){
            for (auto i = data.begin(); i != data.end(); ++i){
                if(e == *i){
                    data.erase(i);
                    return true;
                }
            }
        } else {
            throw std::invalid_argument("This element does not exist!!\n");
        }
        // alternative remove code
        /*  std::vector<T> temp;
          bool flag = false;
          for (auto i = data.begin(); i != data.end(); ++i){
              temp.push_back(*i);
          }
          data.clear();
          std::sort(temp.begin(), temp.end());
          for (auto i = 0 ; i < temp.size() ; ++i){
              if((e != temp[i])) {
                  data.push_back(temp[i]);
                  flag = true;
              }
          }
          return flag;*/
        return false;
    }

    //Removes all of the given element if it exists in this collection

    template <typename T, typename C>
    bool HashSet<T, C>::removeAll(Collection<T, C> &c){

        for(int i = 0; i < c.size(); ++i){
            this->remove(c[i]);
        }
       /* auto i = c.iterator();

        if(!(c.isEmpty())) {

            while (i.hasNext()) {
                remove(i.elementgetter());
                i.next();
            }
            this->remove(i.elementgetter());
        }*/
        return true;
    }

    //Returns intersection

    template <typename T, typename C>
    HashSet<T, C>& HashSet<T, C>::retainAll(Collection<T, C > &c){
        int j;
        auto it = c.iterator();
        static HashSet<T, C> temp;
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
    int HashSet<T, C>::size(void){
        return data.size();
    }

    //[] overloading to reach elements of this collection

    template <typename T, typename C>
    T HashSet<T, C>::operator [](int i){
        auto it = data.begin();
        for( int j = 0; j < i; ++j ){
            ++it;
        }
        return *it;
    }

    //Following functions are intentionally empty
    //to prevent this class to be abstract
    template <typename T, typename C>
    void HashSet<T, C>::sortList(void){
        /*INTENTIONALLY EMPTY*/
    }
    template <typename T, typename C>
    T HashSet<T, C>::element(){
        /*INTENTIONALLY EMPTY*/
    }

    template <typename T, typename C>
    bool HashSet<T, C>::offer(T e){
        /*INTENTIONALLY EMPTY*/

    }

    template <typename T, typename C>
    T HashSet<T, C>::poll(void){
        /*INTENTIONALLY EMPTY*/

    }

}

#ifndef HW6_QUEUE_H
#define HW6_QUEUE_H

#include "Collection.h"
#include <set>
#include <vector>
#include <list>
namespace GTU {
    template<typename T, typename C=std::vector<T> >
    class Queue : virtual public Collection<T,C>  {
        virtual T element()=0;
        virtual bool offer(T e)=0;
        virtual T poll(void)=0;
        virtual bool add(T e)=0;
        virtual Iterator<T, C> iterator(void)=0;
        virtual bool addAll(Collection<T,C> &c)=0;
        virtual void clear()=0;
        virtual bool contains(T e)=0;
        virtual bool containsAll(Collection<T,C> &c)=0;
        virtual bool isEmpty(void)=0;
        virtual bool remove(T e)=0;
        virtual bool removeAll(Collection<T,C> &c)=0;
        virtual Collection<T, C>& retainAll(Collection<T,C> &c)=0;
        virtual int size(void)=0;
        virtual T operator [](int i)=0;
        virtual void sortList(void)=0;

    };
}

#endif //HW6_QUEUE_H

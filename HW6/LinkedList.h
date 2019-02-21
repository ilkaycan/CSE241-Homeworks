#ifndef HW6_LINKEDLIST_H
#define HW6_LINKEDLIST_H

#include "List.h"
#include "Queue.h"
#include <exception>
#include <stdexcept>
namespace GTU {
    template<typename T, typename C>
    class LinkedList :  public Queue<T, C >, public List<T, C > {
    public:
        LinkedList(void);
        LinkedList(C &c);
        LinkedList(int initialCapacity);

        T element();
        bool offer(T e);
        T poll(void)throw(std::out_of_range);  //

        Iterator<T, C > iterator(void);
        bool add(T e);
        bool addAll(Collection<T, C > &c);
        void clear();
        bool contains(T e);
        bool containsAll(Collection<T, C > &c);
        bool isEmpty(void);
        bool remove(T e)throw(std::invalid_argument);  //
        bool removeAll(Collection<T, C > &c);
        LinkedList<T, C>& retainAll(Collection<T, C > &c);
        int size(void);
        T operator [](int i);
        void sortList(void);

    private:
        C data;
    };
}

#endif //HW6_LINKEDLIST_H

#ifndef HW6_HASHSET_H
#define HW6_HASHSET_H

#include "Set.h"
#include <exception>
#include <stdexcept>
namespace GTU{
    template<typename T, typename C>
    class HashSet : public Set<T, C >{
    public:
        HashSet(void);
        HashSet(C &c);
        HashSet(int initialCapacity);

        Iterator<T, C > iterator(void);
        bool add(T e)throw(std::invalid_argument);
        bool addAll(Collection<T, C > &c);
        void clear();
        bool contains(T e);
        bool containsAll(Collection<T, C > &c);
        bool isEmpty(void);
        bool remove(T e)throw(std::invalid_argument);
        bool removeAll(Collection<T, C > &c);
        HashSet<T, C>& retainAll(Collection<T, C > &c);
        int size(void);
        T operator [](int i);
        void sortList(void);
        T element();
        bool offer(T e);
        T poll(void);
    private:
        C data;
    };
}

#endif //HW6_HASHSET_H

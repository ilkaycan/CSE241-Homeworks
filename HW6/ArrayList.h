#ifndef HW6_ARRAYLIST_H
#define HW6_ARRAYLIST_H

#include "List.h"
namespace GTU {
    template<typename T, typename C=std::vector<T> >
    class ArrayList : public List<T, C > {
    public:
        ArrayList(void);
        ArrayList(C &c);
        ArrayList(int initialCapacity);
        Iterator<T, C > iterator(void);
        bool add(T e);
        bool addAll(Collection<T, C > &c);
        void clear();
        bool contains(T e);
        bool containsAll(Collection<T, C > &c);
        bool isEmpty(void);
        bool remove(T e)throw(std::invalid_argument);
        bool removeAll(Collection<T, C > &c);
        ArrayList<T, C>& retainAll(Collection<T, C > &c);
        int size(void);
        void sortList(void);
        T operator [](int i);
        T element();
        bool offer(T e);
        T poll(void);

    private:
        C data;
    };
}

#endif //HW6_ARRAYLIST_H

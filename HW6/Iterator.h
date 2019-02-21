#ifndef HW6_ITERATOR_H
#define HW6_ITERATOR_H

#include <iterator>
#include <exception>
#include <stdexcept>
namespace GTU {
    template <typename T, typename C >
    class Iterator {
    public:
        Iterator(C &containerVariable);

        bool hasNext(void);
        T next(void)throw(std::out_of_range);
        void remove(void)throw(std::length_error);
        T elementgetter(void)throw(std::out_of_range);
    private:
        C& container;
        typename C::iterator it;
        int sizeCheck;
    };
}

#endif //HW6_ITERATOR_H


#ifndef HW5_NEGATIVITY_EXCEPTION_H
#define HW5_NEGATIVITY_EXCEPTION_H

#include <exception>
using namespace std;
extern const int NEGATIVE_VALUE_ERROR;
namespace GTU {
    class NegativityException : public exception {
    public:
        NegativityException(); //No param constructor
        const char* what() const throw();

    private:
        const char* NEGATIVE_VALUE_ERROR;

    };
}

#endif //HW5_NEGATIVITY_EXCEPTION_H

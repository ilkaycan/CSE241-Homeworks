
#ifndef HW5_NOPARAMCONSTRUCTOREXCEPTION_H
#define HW5_NOPARAMCONSTRUCTOREXCEPTION_H

#include <exception>
using namespace std;
extern const int CONSTRUCTOR_ERROR;
namespace GTU {
    class NoParamConstructorException : public exception {
    public:
        NoParamConstructorException(); //No param constructor
        const char* what() const throw();

    private:
        const char* CONSTRUCTOR_ERROR;

    };
}




#endif //HW5_NOPARAMCONSTRUCTOREXCEPTION_H

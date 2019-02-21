#include "NoParamConstructorException.h"
namespace GTU{
    const int CONSTRUCTOR_ERROR = 2;

    NoParamConstructorException::NoParamConstructorException(){
        /* Preparing the error message */
        CONSTRUCTOR_ERROR = "This class needs parameter to create an object!!!\n";
    }


    const char* NoParamConstructorException::what() const throw() {
        /* Returning message */
        return CONSTRUCTOR_ERROR;
    }

}
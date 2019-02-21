#include "NegativityException.h"
namespace GTU{
    const int NEGATIVE_VALUE_ERROR = 1;

    NegativityException::NegativityException(){
        /* Preparing the error message */
        NEGATIVE_VALUE_ERROR = "Negative position or length value is unacceptable for SVG!!\n";
    }


    const char* NegativityException::what() const throw() {
        /* Returning message */
        return NEGATIVE_VALUE_ERROR;
    }

}
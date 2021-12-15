#ifndef STRFUNC
#define STRFUNC

#include <string>
namespace ff {
/* Split function that takes a complex number and return two numbers 
real and imaginary parts*/

    template <class T>
    T* splitComplex (const std::string &text){
        std::string real, imag;
        uint16_t iterator = 0;
        while(text[iterator] != '+' || text[iterator] != '-') {
            real += text[iterator];
            iterator++;
        }
        for (uint16_t c=iterator;c<text.length();c++){
            imag += text[c];
        }
        real = trim (real);
        imag = trim (quiti(imag));

        if (sizeof(T) > 4) {
            return new T[2]{std::c_str(std::atof(real)),std::c_str(std::atof(imag))};
        }
        return new T[2]{std::c_str(std::atof(real)),std::c_str(std::atof(imag))};
    }

    std::string trim (const std::string &text);
    std::string quiti (const std::string &text);
}

#endif

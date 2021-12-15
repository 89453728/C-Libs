#include "cmp.h"
#include <iostream>
#include <string>

int main(void) {
    doubleComplex a(23.33,3.38);
    doubleComplex b(1.89,-32.64);
    doubleComplex e(0.66,5.44);

    e += a*i + b*4.55;
    e -= b + a*i;

    e.c_print();
    
    std::cout << "angle: "  << 180*e.angle()/(3.1415) << "\n"; 

    return 0;
}

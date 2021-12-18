#include "cmp.h"
#include "narray.h"
#include <iostream>


using namespace ff;

int main(){
	doubleComplex a(2,3);
	doubleComplex b(4.55,-7.84);
	a += a*b;
	a.c_print();

	intNArray arr(6);
	for(narray_len i=0;i<6;i++)
		arr[i] = i+1;
	

	for(narray_len i=0;i<6;i++)
		std::cout << "arr[" << i << "] = " << arr[i] << "\n";
	
    // arr[9] = 10;

    std::cout << arr.print();
    arr.print(true);
	
    std::cout << "Element arr(1) = " << arr(1) << "\n";
    intNArray arr2(4);

    arr2(0) = 2; arr2(1) = 67; arr2(2) = 88; arr2(3) = -90;


    std::cout << "arr: " << arr.print();
    std::cout << "arr2: " << arr2.print();
    
    if (arr == arr2) {
        std::cout <<"arr and arr2 are equal\n";
    }
    else if(arr != arr2){
        std::cout <<"arr and arr2 are diferents\n";
    }
    
    
    if (arr > arr2) {
        std::cout << "arr is bigger than arr2\n";
    }
    else {
        std::cout << "arr is less than arr2\n";
    }

    return 0;
}

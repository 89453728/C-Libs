#include "cmp.h"
#include "narray.h"
#include <iostream>


using namespace ff;

int main(){
	doubleComplex a(2,3);
	doubleComplex b(4.55,-7.84);
	a += a*b;
	a.c_print();

	ff::NArray<int> arr(6);
	for(narray_len i=0;i<6;i++)
		arr[i] = i+1;
	

	for(narray_len i=0;i<6;i++)
		std::cout << "arr[" << i << "] = " << arr[i] << "\n";
	
	return 0;
}

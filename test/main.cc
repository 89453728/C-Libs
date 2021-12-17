#include "cmp.h"

using namespace ff;

int main(){
	doubleComplex a(2,3);
	doubleComplex b(4.55,-7.84);
	a += a*b;
	a.c_print();
	return 0;
}

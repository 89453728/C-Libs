#ifndef NARRAY_H
#define NARRAY_H

#include <iostream>
#include <fstream>
#include "cmp.h"

typedef int narray_len; 

namespace ff {	
	
	template <class T>
	class NArray {
		private: 
			T *a;
			narray_len size; 
		public: 
			NArray();
			NArray(const narray_len s);
			NArray(const T *e,const narray_len tam);
			
			NArray operator +(const NArray &a) const;
			NArray operator -(const NArray &a) const;
			NArray operator *(const NArray &a) const;
			NArray operator *(const T a) const;
			NArray operator /(const T a) const;
			
            T& operator [](const narray_len p);
            T& operator ()(const narray_len p);
            // Don't use this operator
            std::ostream& operator <<(std::ostream &out); 
            
            NArray operator =(const NArray &a);
            NArray operator +=(const NArray &a);
            NArray operator -=(const NArray &a);
            NArray operator *=(const NArray &a);
            NArray operator *=(const T a);

            bool operator ==( NArray &a)const;
            bool operator !=( NArray &a)const;
            bool operator >(const NArray &a)const;
            bool operator <(const NArray &a)const;
            bool operator >=(const NArray &a)const;
            bool operator <=(const NArray &a)const;

            std::string print(bool pr=false);
            narray_len len()const;
	        T abs() const;
    };
}

template<class T>
ff::NArray<T>::NArray() {
	this->size = 0;
}
template<class T>
ff::NArray<T>::NArray(const narray_len s){
	this->a = new T[s];
	this->size = s;
}
template<class T>
ff::NArray<T>::NArray(const T *e,const narray_len tam){
	this->m = new T[tam];
}

template<class T>
ff::NArray<T> ff::NArray<T>::operator +(const ff::NArray<T> &a)const{
	if(this->len() != a.len())
		return ff::NArray<T>();
		
	ff::NArray<T> ret(this->len());
	for(narray_len i=0;i<this->len();i++){
		ret[i] = this[i] + a[i];
	}
	return ret;
}

template<class T>
ff::NArray<T> ff::NArray<T>::operator -(const ff::NArray<T> &a)const{
	if(this->len() != a.len())
		return ff::NArray<T>();
	
	ff::NArray<T> ret(this->len());
	for(narray_len i=0;i<this->len();i++){
		ret[i] = this[i] - a[i];
	}
	return ret;
}	

template<class T>
ff::NArray<T> ff::NArray<T>::operator *(const ff::NArray<T> &a)const{
	if(this->len() != a.len())
		return ff::NArray<T>();
	
	ff::NArray<T> ret(this->len());
	for(narray_len i=0;i<this->len();i++){
		ret[i] = this[i] * a[i];
	}
	return ret;
}
template<class T>
ff::NArray<T> ff::NArray<T>::operator *(const T a)const {
	ff::NArray<T> ret(this->len());
	for(narray_len i=0;i<this->len();i++){
		ret[i] = this[i]*a;
	}
	return ret;
}
template<class T>
ff::NArray<T> ff::NArray<T>::operator /(const T a)const {
	ff::NArray<T> ret(this->len());
	for(narray_len i=0;i<this->len();i++){
		ret[i] = this[i]/a;
	}
	return ret;
}
template<class T>
ff::NArray<T> ff::NArray<T>::operator =(const ff::NArray<T> &a){
    this->a = new T[a.len()];
    this->size = a.len();
    for(narray_len i=0;i<a.len();i++){
        this->a[i] = a[i];
    }
    return *this;
}
template<class T>
ff::NArray<T> ff::NArray<T>::operator +=(const ff::NArray<T> &a){
    if(this->len() == a.len()) {    
        for(narray_len i=0;i<a.len();i++){
            this->a[i] += a[i];
        }
        return *this;
    }
    std::cerr << "Narray's length must be the same\n";
}
template<class T>
ff::NArray<T> ff::NArray<T>::operator -=(const ff::NArray<T> &a){
    if(this->len() == a.len()) {    
        for(narray_len i=0;i<a.len();i++){
            this->a[i] -= a[i];
        }
        return *this;
    }
    std::cerr << "Narray's length must be the same\n";
}

template<class T>
ff::NArray<T> ff::NArray<T>::operator *=(const ff::NArray<T> &a){
    if(this->len() == a.len()) {    
        for(narray_len i=0;i<a.len();i++){
            this->a[i] *= a[i];
        }
        return *this;
    }
    std::cerr << "Narray's length must be the same\n";
}
template<class T>
ff::NArray<T> ff::NArray<T>::operator *=(const T a){
    if(this->len() == a.len()) {    
        for(narray_len i=0;i<a.len();i++){
            this->a[i] *= a;
        }
        return *this;
    }
    std::cerr << "Narray's length must be the same\n";
}
template<class T>
T& ff::NArray<T>::operator [](const narray_len p) {
	if(p < this->len())
		return this->a[p];

	std::cerr << "NArray error: position must be less than vector\n"; 
}
template<class T>
T& ff::NArray<T>::operator ()(const narray_len p) {
    if(p < this->len())
		return this->a[p];

	std::cerr << "NArray error: position must be less than vector\n"; 
}
template<class T>
bool ff::NArray<T>::operator ==( ff::NArray<T> &a)const {
    if(this->len() != a.len()){
        return false;
    }
    for(narray_len i=0;i<this->len();i++){
        if(this->a[i] != a[i])
            return false;
    }
    return true;
}
template<class T>
bool ff::NArray<T>::operator !=( ff::NArray<T> &a)const {
    if(this->len() != a.len()){
        return true;
    }
    for(narray_len i=0;i<this->len();i++){
        if(this->a[i] != a[i])
            return true;
    }
    return false;
}
template<class T>
bool ff::NArray<T>::operator <(const ff::NArray<T> &a)const {
    return this->abs() < a.abs();
}
template<class T>
bool ff::NArray<T>::operator >(const ff::NArray<T> &a)const {
    return this->abs() > a.abs();
}
template<class T>
bool ff::NArray<T>::operator <=(const ff::NArray<T> &a)const {
    return this->abs() <= a.abs();
}
template<class T>
bool ff::NArray<T>::operator >=(const ff::NArray<T> &a)const {
    return this->abs() >= a.abs();
}

template<class T>
std::ostream& ff::NArray<T>::operator <<(std::ostream &out){
    std::string ret = "[ " + this->a[0];
    for(narray_len i=1; i<this->len();i++) {
        ret += " " + std::to_string(this[i]);
    }
    ret += " ]\n";
    out << ret;
    return out;
}

template<class T>
T ff::NArray<T>::abs()const{
    T sum = 0;
    for(narray_len i=0;i<this->len();i++){
        sum += this->a[i];
    }
    return sum;
}
template<class T>
std::string ff::NArray<T>::print(bool pr){
    std::string ret = "[ " + std::to_string(this->a[0]);
    for(narray_len i=1; i<this->len();i++) {
        ret += " " + std::to_string(this->a[i]);
    }
    ret += " ]\n";
    if (pr)
        std::cout << ret;


    return ret;
}
template<class T>
narray_len ff::NArray<T>::len()const{
	return this->size;
}

typedef ff::NArray<doubleComplex> complexNArray;
typedef ff::NArray<double> doubleNArray;
typedef ff::NArray<int> intNArray;
typedef ff::NArray<int8_t> int8NArray; 
typedef ff::NArray<int16_t> int16NArray; 
typedef ff::NArray<int32_t> int32NArray; 
typedef ff::NArray<int64_t> int64NArray; 
typedef ff::NArray<uint8_t> uint8NArray; 
typedef ff::NArray<uint16_t> uint16NArray; 
typedef ff::NArray<uint32_t> uint32NArray; 
typedef ff::NArray<uint64_t> uint64NArray; 

#endif

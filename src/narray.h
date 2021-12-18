#ifndef NARRAY_H
#define NARRAY_H

#include <iostream>

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
			NArray operator +(const T a) const;
			NArray operator -(const NArray &a) const;
			NArray operator -(const T a) const;
			NArray operator *(const NArray &a) const;
			NArray operator *(const T a) const;
			NArray operator /(const T a) const;
			T& operator [](const narray_len p);
			narray_len len()const;
	};
}

template<class T>
ff::NArray<T>::NArray() {
	*this.size = 0;
}
template<class T>
ff::NArray<T>::NArray(const narray_len s){
	this->a = new T[s];
	this->size = s;
}
template<class T>
ff::NArray<T>::NArray(const T *e,const narray_len tam){
	*this.m = new T[tam];
}

template<class T>
ff::NArray<T> ff::NArray<T>::operator +(const ff::NArray<T> &a)const{
	if(*this.len() != a.len())
		return ff::NArray<T>();
		
	ff::NArray<T> ret(*this.len());
	for(narray_len i=0;i<*this.len();i++){
		ret[i] = *this[i] + a[i];
	}
	return ret;
}
template<class T>
ff::NArray<T> ff::NArray<T>::operator +(const T a)const{
	ff::NArray<T> ret(*this.len());
	for(narray_len i=0;i<*this.len();i++){
		ret[i] = *this[i]+a;
	}
	return ret;
}
template<class T>
ff::NArray<T> ff::NArray<T>::operator -(const ff::NArray<T> &a)const{
	if(*this.len() != a.len())
		return ff::NArray<T>();
	
	ff::NArray<T> ret(*this.len());
	for(narray_len i=0;i<*this.len();i++){
		ret[i] = *this[i] - a[i];
	}
	return ret;
}	
template<class T>
ff::NArray<T> ff::NArray<T>::operator -(const T a)const{
	ff::NArray<T> ret(*this.len());
	for(narray_len i=0;i<*this.len();i++){
		ret[i] = *this[i]-a;
	}
	return ret;
}
template<class T>
ff::NArray<T> ff::NArray<T>::operator *(const ff::NArray<T> &a)const{
	if(*this.len() != a.len())
		return ff::NArray<T>();
	
	ff::NArray<T> ret(*this.len());
	for(narray_len i=0;i<*this.len();i++){
		ret[i] = *this[i] * a[i];
	}
	return ret;
}
template<class T>
ff::NArray<T> ff::NArray<T>::operator *(const T a)const {
	ff::NArray<T> ret(*this.len());
	for(narray_len i=0;i<*this.len();i++){
		ret[i] = *this[i]*a;
	}
	return ret;
}
template<class T>
ff::NArray<T> ff::NArray<T>::operator /(const T a)const {
	ff::NArray<T> ret(*this.len());
	for(narray_len i=0;i<*this.len();i++){
		ret[i] = *this[i]/a;
	}
	return ret;
}
template<class T>
T& ff::NArray<T>::operator [](const narray_len p) {
	if(p < *this.len())
		return *this->a[p];
	
	std::cerr << "NArray error: position must be less than vector\n"; 
}
template<class T>

narray_len ff::NArray<T>::len()const{
	return *this.size;
}

#endif

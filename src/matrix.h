#ifndef MATRIX_F
#define MATRIX_F

#include "cmp.h"
#include "narray.h"

#define ALL -2
#define END -1
#define START 0

namespace ff {
    template<class T>
    class Matrix {
        private:
            ff::NArray<T> *m;
            narray_len size[2] = {0,0};
            bool square = false;
        public: 
            Matrix();
            Matrix(ff::NArray<T> *_m, narray_len *s);
            Matrix(const unsigned int a, const unsigned int b);
            Matrix(const Matrix &m);

            Matrix operator +(const Matrix &m) const;
            Matrix operator -(const Matrix &m) const;
            Matrix operator *(const Matrix &m) const;
            Matrix operator *(const T a) const;

            Matrix operator =(const Matrix &m);
            Matrix operator +=(const Matrix &m);
            Matrix operator -=(const Matrix &m);
            Matrix operator *=(const Matrix &m);
            Matrix operator *=(const T a);
            
            bool operator ==(const Matrix &m);
            bool operator !=(const Matrix &m);
            bool operator <(const Matrix &m);
            bool operator >(const Matrix &m);
            bool operator <=(const Matrix &m);
            bool operator >=(const Matrix &m);
            
            T& operator ()(const unsigned int row, const unsigned int col);
            
            T det() const;
            NArray<T> col(const unsigned int col)const;
            NArray<T> row(const unsigned int row)const;
            Matrix<T> inv() const;
            NArray<T> diag(const unsigned int d)const;
    };
}


template <class T>
ff::Matrix<T>::Matrix() {}
template <class T>
ff::Matrix<T>::Matrix(ff::NArray<T> *_m, narray_len *s) {
    bool nomatch = true;
    for(unsigned int i=0;i<s[0];i++){
        if(_m[i].len() != s[1]){
            nomatch = false;
            break;
        }
    }
    if(nomatch){
        this->size[0] = s[0];
        this->size[1] = s[1];

        this->m = new ff::NArray<T>[s[0]];
        for(unsigned int i=0;i<s[1];i++){
            this->m[i] = ff::NArray<T>(_m[i]);
        }
        if(s[1] == s[0]) {
            this->square=true;
        }
    }
}
template <class T>
ff::Matrix<T>::Matrix(const unsigned int a, const unsigned int b) {}
template <class T>
ff::Matrix<T>::Matrix(const ff::Matrix<T> &m) {}

template<class T>
ff::Matrix<T>::operator +(const ff::Matrix<T> &m) const {}
template<class T>
ff::Matrix<T>::operator -(const ff::Matrix<T> &m) const {}
template<class T>
ff::Matrix<T>::operator *(const ff::Matrix<T> &m) const {}
template<class T>
ff::Matrix<T>::operator *(const T a) const {}

template<class T>
ff::Matrix<T>::operator =(const ff::Matrix<T> &m) {}
template<class T>
ff::Matrix<T>::operator +=(const ff::Matrix<T> &m) {}
template<class T>
ff::Matrix<T>::operator -=(const ff::Matrix<T> &m) {}
template<class T>
ff::Matrix<T>::operator *=(const ff::Matrix<T> &m) {}
template<class T>
ff::Matrix<T>::operator *=(const T a) {}
            
template<class T>
bool ff::Matrix<T>::operator ==(const ff::Matrix<T> &m) {}
template<class T>
bool ff::Matrix<T>::operator !=(const ff::Matrix<T> &m) {}
template<class T>
bool ff::Matrix<T>::operator <(const ff::Matrix<T> &m) {}
template<class T>
bool ff::Matrix<T>::operator >(const ff::Matrix<T> &m) {}
template<class T>
bool ff::Matrix<T>::operator <=(const ff::Matrix<T> &m) {}
template<class T>
bool ff::Matrix<T>::operator >=(const ff::Matrix<T> &m) {}

template<class T>            
T& ff::Matrix<T>::operator ()(const unsigned int row, const unsigned int col) {}
            
template<class T>
T ff::Matrix<T>::det() const {}
template<class T>
ff::NArray<T> ff::Matrix<T>::col(const unsigned int col)const {}
template<class T>
bool ff::Matrix<T>::col(const ff::NArray<T> &col) {}
template<class T>
bool ff::Matrix<T>::row(const ff::NArray<T> &row) {}
template<class T>
ff::Matrix<T> ff::Matrix<T>::inv() const {}
template<class T>
ff::NArray<T> ff::Matrix<T>::diag(const unsigned int d)const {}

#endif

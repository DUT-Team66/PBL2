
#include "QuanLy.h"


template <typename T>

QuanLy<T>::QuanLy(T* list,int length) {
    this->list = list;
    this->length = length;
}

template <typename T>
void QuanLy<T>::Add(T) {
    *(this->list + length) = T;
    this->length++; 
}
template <typename T>
void QuanLy<T>::Show() {
    for(int i = 0; i < this->length; ++i) {
        cout << T << endl;
    }
}


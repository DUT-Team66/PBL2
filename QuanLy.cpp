
#include "QuanLy.h"


template <typename T>

QuanLy<T>::QuanLy(T* list,int length) {
    this->list = list;
    this->length = length;
}

template <typename T>
void QuanLy<T>::Add() {
    cout << "Nhap thong tin doi tuong can them" << endl;
    *(this->list + length) = T;
    this->length++; 
}
template <typename T>
void QuanLy<T>::Show() {
    for(int i = 0; i < this->length; ++i) {
        cout << T << endl;
        //T.show();
    }
}

template <typename T>
void QuanLy<T>::Search() {
    string id;
    cout << "Nhap ma doi tuong can tim kiem:" << endl;;
    cin >> id;
    for(int i = 0; i <  this->length; ++i) {
        if((this->list + i)-> == id) {
            cout << *(this->list + i) << endl;
        } 
    }
} // xai operator
template <typename T>
void QuanLy<T>::Update() {
    string id;
    cout << "Nhap ma doi tuong can cap nhat:" << endl;
    cin >> id;
    T.Update();
}
template <typename T>
void QuanLy<T>::Delete()  {

}


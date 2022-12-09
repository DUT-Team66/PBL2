#include "List.h"
#include <windows.h>
#include "Table.h"
#include <iostream>
#include <iomanip>

using namespace std;
template <class T>
List<T>::List() {
    this->pHead = nullptr;
    this->pTail = nullptr;
}
template <class T>
List<T>::~List() {
    Node<T> *k;  
    while (this->pHead != nullptr)
    {
        k = this->pHead;
        this->pHead = this->pHead->pNext;
        delete k;
    }
    this->pTail = nullptr;
}
template <class T>
void List<T>::Add(const T& t) {
    Node<T> *p = new Node<T>;
    if(p == nullptr) {
        std::cout<<"\nNot enough memory to allocate\n"<<endl;
    }
    p->data = t;
    p->pNext = nullptr;
    if (this->pHead == nullptr)
    {
        this->pHead = this->pTail = p;
    }
    else
    {
        this->pTail->pNext = p;
        this->pTail = p;
    }
}
template <class T>
void List<T>::Delete(string m) {
    bool index = false;
    if(this->pHead->data.getID() == m) {
        if(this->pTail == this->pHead){
            this->pHead = this->pTail = nullptr;
            index = true;
        } else {
            Node<T> *p = this->pHead;
            this->pHead = this->pHead->pNext;
            delete p;
            index = true;
        }
    } else if (this->pTail->data.getID() == m) {
        for(Node<T> *k = this->pHead; k != nullptr; k = k->pNext) {
            if(k->pNext == this->pTail) {
                delete this->pTail;
                k->pNext = nullptr;
                this->pTail = k;
                index = true;
            }
        }
    } else {
        Node<T> *g = new Node<T>;
        for(Node<T> *k = this->pHead; k != nullptr; k = k->pNext) {
            if(k->data.getID() == m) {
                g->pNext = k->pNext;
                delete k;
                index = true;
                break;
            } else {
                g = k;
            }
        }
    }
    if (index == true) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, brightgreen);
        std::cout << "\n" << setw(45) << "" << "Delete successfully!\n";
        SetConsoleTextAttribute(hConsole, brightwhite); 
    } else {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, brightred);
        std::cout << "ID does not exist!\n";
        SetConsoleTextAttribute(hConsole, brightwhite); 
    }
}
template <class T>
int List<T>::size() const {
    int cnt = 0;
    for(Node<T>* tmp = this->pHead; tmp != nullptr; tmp = tmp->pNext) {
        ++cnt;
    }
    return cnt;
}
template <class T>
Node<T>*& List<T>::HeadNode() {
    return this->pHead;
}
template <class T>
Node<T>*& List<T>::TailNode() {
    return this->pTail;
}
// template <class T>
// const List<T>& List<T>::operator= (const List<T>& l) {
//     cout << "this = " << this << "\n";
//     cout << "&l = " << &l << "\n";
//     if(this->pHead == nullptr) {
//         cout << "null phead\n";
//     } 
//     else this->pHead->data.show();

//     if(this != &l) {
//         Node<T> *k;
//         cout << "Enter list\n";
//         while(this->pHead != nullptr) {
//             k = this->pHead;
//             cout << "loop list\n";
//             this->pHead = this->pHead->pNext;
//             delete k;
//         }
//         cout << "list =\n";
//         this->pTail = nullptr;
//         for(Node<T> *tmp = l.pHead; tmp != nullptr; tmp = tmp->pNext) {
//             this->Add(tmp->data);
//         }
//         cout << "End list = \n";
//     }
//     return *this;
// }



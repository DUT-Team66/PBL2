#ifndef _LIST_
#define _LIST_

#include <string>
using namespace std;

template <class T>
class Node {
    private:
        T data;
        Node<T> *pNext;
        template<class U> friend class List;
    public:
        Node() {
            this->pNext = nullptr;
        }
        Node<T> operator = (const Node<T>& n) {
            this->data = n.data;
            this->pNext = n.pNext;
        }
        T& Data() {
            return this->data;
        }
        Node<T>*& NextNode() {
            return this->pNext;
        }
};


template <class T>
class List {
    protected:
        Node<T> *pHead;
        Node<T> *pTail;
    public:
        List();
        ~List();
        
        void Add(const T&);
        void Delete(string);

        int size() const;

        Node<T>*& HeadNode();
        Node<T>*& TailNode();

        // const List<T>& operator = (const List<T>&);

};



#endif
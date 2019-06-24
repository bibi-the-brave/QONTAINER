/*
 * DeepPtr<T> implementa una gestione automatica della memoria “profonda” e polimorfa di
 * puntatori a T richiedendo che T si un tipo che supporti la clonazione e la distruziona
 * polimorfa
 *
 * Simile ad unique_ptr della stl
 *
 * PRECONDIZIONE: T* ptr non deve essere inizializzato ad un puntatore nullo
 */

#ifndef DEEPPTR_H
#define DEEPPTR_H
//https://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c
#include <exception>

template <typename T>
class DeepPtr {
    T* ptr;
public:
    DeepPtr(T*);
    DeepPtr(const DeepPtr&);
    ~DeepPtr();
    DeepPtr& operator=(const DeepPtr&);
    bool operator==(const DeepPtr&);
    T* operator->() const;
    T& operator*() const;
    T* get() const;
};

template <typename T>
DeepPtr<T>::DeepPtr(T* p) {
    ptr = p->clone();
}

template <typename T>
DeepPtr<T>::DeepPtr(const DeepPtr& dptr) {
    ptr = dptr.ptr->clone();
}

template <typename T>
DeepPtr<T>::~DeepPtr() {
    delete ptr;
}

template <typename T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr<T>& dptr) {
    if(this != &dptr) {
        delete ptr;
        ptr = dptr.pt->clone();
    }
    return *this;
}

template <typename T>
bool DeepPtr<T>::operator==(const DeepPtr& dptr) {
    return *ptr == *dptr.ptr;
}

template <typename T>
T* DeepPtr<T>::operator->() const {
    return ptr;
}


template <typename T>
T& DeepPtr<T>::operator*() const {
    return *ptr;
}

template <typename T>
T* DeepPtr<T>::get() const {
    return  ptr;
}

#endif // DEEPPTR_H


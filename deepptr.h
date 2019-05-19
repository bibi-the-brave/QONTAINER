#ifndef DEEPPTR_H
#define DEEPPTR_H
//cancellare deeppratleta
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
};

template <typename T>
DeepPtr<T>::DeepPtr(T* p)
try : ptr(p->clone()) {
} catch( std::exception& e ) {
    throw e;
}

template <typename T>
DeepPtr<T>::DeepPtr(const DeepPtr& dptr)
try : ptr(dptr.ptr.clone()) {
} catch( std::exception& e ) {
    throw e;
}

template <typename T>
DeepPtr<T>::~DeepPtr() {
    delete ptr;
}

template <typename T>
DeepPtr<T>& DeepPtr<T>::operator=(const DeepPtr<T>& dptr) {
    if(this != &dptr) {
        delete ptr;
        ptr = dptr.ptr.clone();
    }
    return *this;
}

template <typename T>
bool DeepPtr<T>::operator==(const DeepPtr& dptr) {
    return ptr == dptr.ptr;
}

template <typename T>
T* DeepPtr<T>::operator->() const {
    return ptr;
}


template <typename T>
T& DeepPtr<T>::operator*() const {
    return *ptr;
}

/*template <typename T>
DeepPtr<T>::
*/
#endif // DEEPPTR_H

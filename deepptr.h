#ifndef DEEPPTR_H
#define DEEPPTR_H

#include "allenamento.h"

template <typename T>
class DeepPtr {
    Allenamento* ptr;
public:
    DeepPtr(Allenamento*);
    DeepPtr(const DeepPtr&);
    ~DeepPtr();
    DeepPtr& operator==(const DeepPtr&);
    Allenamento* operator->() const;
    Allenamento& operator*() const;
};

template <typename T>
DeepPtr<T>::DeepPtr(Allenamento* p): ptr(p->clone()) {}

template <typename T>
DeepPtr<T>::DeepPtr(const DeepPtr& dptr): ptr(dptr.ptr.clone()) {}

template <typename T>
DeepPtr<T>::~DeepPtr() {
    delete ptr;
}

template <typename T>
DeepPtr<T>& DeepPtr<T>::operator==(const DeepPtr<T>& dptr) {
    if(this != &dptr) {
        delete ptr;
        ptr = dptr.ptr.clone();
    }
    return *this;
}


template <typename T>
Allenamento* DeepPtr<T>::operator->() const {
    return ptr;
}


template <typename T>
Allenamento& DeepPtr<T>::operator*() const {
    return *ptr;
}

/*template <typename T>
DeepPtr<T>::
*/
#endif // DEEPPTR_H

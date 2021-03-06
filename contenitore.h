/*
 * Andrea Favero: andrea.favero.8@studenti.unipd.it
 *
 * Classe Contenitore.
 * Descrizione: contenitore templatizzato costruito utilizzando
 * una lista doppiamente concatenata.
 */
#ifndef CONTENITORE_H
#define CONTENITORE_H

#include <typeinfo>
#include "errori.h"
#include <list>
#include <vector>

template <typename T>
class Contenitore {
    friend class iterator;
    friend class const_iterator;
private:
    class Nodo {
    public:
        T elemento;
        Nodo *sx, *dx;

        Nodo(T, Nodo* = 0, Nodo* = 0);
        ~Nodo();
    };

    Nodo *primo, *ultimo;
    unsigned int size;

    static Nodo* copiaProfonda(Nodo*);
    static Nodo* getUltimo(Nodo*);
    static void eliminaNodo(Nodo*&, Nodo*&, Nodo*&);

public:
    Contenitore();
    Contenitore(T);
    Contenitore(T, unsigned int);
    Contenitore(const Contenitore&);
    Contenitore& operator=(const Contenitore&);
    ~Contenitore();
    unsigned int Size() const;
    void pushBack(const T&);
    void pushFront(const T&);
    void insertAt(const T&, unsigned int);
    const T& At(unsigned int) const;
    const T& At(int) const;
    void popFront();
    void popBack();
    void remove(const T&);
    void removeAt(unsigned int);
    bool elementoPresente(const T&);
    bool operator==(const Contenitore&) const;
    unsigned int count(const T&) const;
    void clear();
    std::list<T> stdList() const;
    std::vector<T> stdVector() const;

    class iterator {
        friend class Contenitore<T>;
    private:
        Nodo* punt;
    public:
        bool operator==(iterator) const;
        bool operator!=(iterator) const;
        iterator& operator++();    //prefisso
        iterator operator++(int); //postfisso
        iterator& operator--();
        iterator operator--(int);
        T* operator->() const;
        T& operator*() const;
    };

    class const_iterator {
        friend class Contenitore<T>;
    private:
        const Nodo* punt;
    public:
        bool operator ==(const_iterator) const;
        bool operator !=(const_iterator) const;
        const_iterator& operator++() const;
        const_iterator operator++(int) const;
        const_iterator& operator--() const;
        const_iterator operator--(int) const;
        const T* operator->() const;
        const T& operator*() const;
    };

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    T& operator[](iterator) const;
    iterator erase(iterator);
    iterator find(const T&) const;
};

template <typename T>
Contenitore<T>::Nodo::Nodo(T e,  typename Contenitore<T>::Nodo* s,
                           typename Contenitore<T>::Nodo* d):
    elemento(e), sx(s), dx(d) {}

template <typename T>
Contenitore<T>::Nodo::~Nodo() {
    if(dx)
        delete dx;  //deallocazione ricorsiva della memoria
}

template <typename T>
typename Contenitore<T>::Nodo*
Contenitore<T>::copiaProfonda(typename Contenitore<T>::Nodo* p) {
    if(!p)
        return 0;

    typename Contenitore<T>::Nodo *inizio, *scorri;
    inizio = new typename Contenitore<T>::Nodo(p->elemento, 0, 0);
    p = p->dx;
    scorri = inizio;

    while(p) {
        scorri->dx = new typename Contenitore<T>::Nodo(p->elemento, scorri, 0);
        p = p->dx;
        scorri = scorri->dx;
    }

    return inizio;
}

/*
 * Ritorna un puntatore di tipo Nodo* all'ultimo elemento delle lista p
 */
template <typename T>
typename Contenitore<T>::Nodo*
Contenitore<T>::getUltimo(typename Contenitore<T>::Nodo* p) {
    if(!p)
        return 0;
    while(p->dx)
        p = p->dx;
    return p;
}

/*
 * PRE-CONDIZIONE: primo, ultimo e attuale devono essere dei puntatori NON nulli.
 * POST-CONDIZIONE: attuale punta ad un'area indefinita di memoria,
 * primo e ultimo puntano rispettivamente al primo ed all'ultimo elemento della
 * lista. La size del contenitore non è stata decrementata, è necessario farlo a mano
 * nella funzione chiamante.
 */
template <typename T>
void Contenitore<T>::eliminaNodo(typename Contenitore<T>::Nodo*& primo,
                                 typename Contenitore<T>::Nodo*& ultimo,
                                 typename Contenitore<T>::Nodo*& attuale)
{
    if( !primo || !ultimo || !attuale)
        throw ErrContenitore();
    if(attuale == primo && primo == ultimo)
        primo = ultimo = 0;
    else if(attuale == primo) {
        primo = primo->dx;
        primo->sx = 0;
        attuale->dx = 0;
    } else if( attuale == ultimo ) {
        ultimo = attuale->sx;
        ultimo->dx = 0;
    } else {
        (attuale->sx)->dx = attuale->dx;
        (attuale->dx)->sx = attuale->sx;
        attuale->dx = attuale->sx = 0;
    }
    delete attuale;
}

template <typename T>
bool Contenitore<T>::elementoPresente(const T& el) {
    Nodo* scorri = primo;
    while(scorri) {
        if(scorri->elemento == el)
            return true;
        scorri = scorri->dx;
    }
    return false;
}

template <typename T>
Contenitore<T>::Contenitore(): primo(0), ultimo(0), size(0) {}

template <typename T>
Contenitore<T>::Contenitore(T el): primo(new Nodo(el)), ultimo(primo), size(1) {}

//PRE: occ >= 1
template <typename T>
Contenitore<T>::Contenitore(T el, unsigned int occ)
    : primo(new Nodo(el)), ultimo(primo), size(occ)
{
    if(occ == 0) {
        delete primo;
        throw ErrContenitore();
    }

    Nodo* scorri = primo;
    for(unsigned int i = 1; i < occ; ++i) {
        scorri->dx = new typename Contenitore<T>::Nodo(el, scorri->dx, 0);
        scorri = scorri->dx;
    }
}

template <typename T>
Contenitore<T>::Contenitore(const Contenitore &l)
    : primo(copiaProfonda(l.primo)), ultimo(getUltimo(primo)), size(l.size) {}

template <typename T>
Contenitore<T>& Contenitore<T>::operator=(const Contenitore& l) {
    if(this != &l) {
        delete primo;   //pulizia dello heap
        primo = copiaProfonda(l.primo);
        ultimo = getUltimo(primo);
        size = l.size;
    }
    return *this;
}

template <typename T>
Contenitore<T>::~Contenitore() {
    if(primo)
        delete primo;
}

template <typename T>
unsigned int Contenitore<T>::Size() const {
    return size;
}

template <typename T>
void Contenitore<T>::pushBack(const T& el) {
    if( !primo )
        primo = ultimo = new typename Contenitore<T>::Nodo(el);
    else {
        ultimo->dx = new typename Contenitore<T>::Nodo(el, ultimo );
        ultimo = ultimo->dx;
    }
    size++;
}

template <typename T>
void Contenitore<T>::pushFront(const T& el) {
    if( !primo )
        primo = ultimo = new typename Contenitore<T>::Nodo(el);
    else {
        primo = new typename Contenitore<T>::Nodo(el, 0, primo);
        primo->dx->sx = primo;
    }
    size++;
}

template <typename T>
void Contenitore<T>::insertAt(const T& el, unsigned int pos) {
    if(pos >= size || !primo)
        throw ErrContenitore();

    if(pos == 0)
        pushFront(el);
    else if(pos == size - 1)
        pushBack(el);
    else {
        typename Contenitore<T>::Nodo *daInserire = primo;
        for(unsigned int i = 0; i < pos; ++i, daInserire = daInserire->dx) ;
        daInserire =
          new typename Contenitore<T>::Nodo(el, daInserire->sx, daInserire->dx);
        size++;
    }
}

template <typename T>
const T& Contenitore<T>::At(unsigned int pos) const {
    typename Contenitore<T>::Nodo *scorre = primo;
    unsigned int cont = 0;
    while (scorre && cont < pos) {
        scorre = scorre->dx;
        cont++;
    }

    if(cont < pos)  //caso in cui pos < 0 o maggiore del #elementi
        throw ErrContenitore();

    return scorre->elemento;
}

template <typename T>
const T& Contenitore<T>::At(int pos) const {
    typename Contenitore<T>::Nodo *scorre = primo;
    int cont = 0;
    while (scorre && cont < pos) {
        scorre = scorre->dx;
        cont++;
    }

    if(cont < pos)
        throw ErrContenitore();

    return scorre->elemento;
}

template <typename T>
void Contenitore<T>::popFront() {
    if( !primo )
        throw ErrContenitore();

    typename Contenitore<T>::Nodo *daRimuovere = primo;
    primo = primo->dx;
    if(primo)
        primo->sx = 0;
    daRimuovere->dx = 0;
    delete daRimuovere;

    if(!primo) //se ho svuotato la lista sistemo anche il puntatore a ultimo
        ultimo = 0;
    size--;
}

template <typename T>
void Contenitore<T>::popBack() {
    if( !primo )
        throw ErrContenitore();

    typename Contenitore<T>::Nodo *daRimuovere = ultimo;
    ultimo = ultimo->sx;
    if( ultimo )
        ultimo->dx = 0;
    else
        primo = ultimo;

    delete daRimuovere;
    size--;
}

/*
 * Rimuove tutti gli elementi che sono uguali a quello passato come parametro
 */
template <typename T>
void Contenitore<T>::remove(const T& el) {

    if( !primo )
        throw ErrContenitore();

    typename Contenitore<T>::Nodo *scorre = primo;
    while(scorre) {
        if( scorre->elemento == el ) {
            typename Contenitore<T>::Nodo *daEliminare = scorre;
            scorre = scorre->dx;
            try {
                eliminaNodo(primo, ultimo, daEliminare);
            } catch (ErrContenitore) {throw;}
            size--;
        } else
            scorre = scorre->dx;
    }

}

template <typename T>
void Contenitore<T>::removeAt(unsigned int pos) {
    if( pos >= size || size == 0)
        throw ErrContenitore();

    if(pos == 0)
        popFront();
    else if(pos == size - 1)
        popBack();
    else {
        typename Contenitore<T>::Nodo *daEliminare = primo;
        for (unsigned int i = 0; i < pos; ++i, daEliminare = daEliminare->dx) ;
        eliminaNodo(primo, ultimo, daEliminare);
        size--;
    }
}

/* Come operator== di std::list. Controlla che il numero di size
 * della lista di invocazione sia uguale a quello della lista passata
 * come parametro, e che ciascun elemento delle due che compare alla stessa
 * posizione sia uguale */
template <typename T>
bool Contenitore<T>::operator==(const Contenitore& l) const {

    if( !l.primo && !primo )
        return true;

    if( (!l.primo && primo) || (l.primo && !primo) )
        return false;

    if( size != l.size )
        return false;

    typename Contenitore<T>::Nodo *scorri = primo, *scorriM = l.primo;

    while(scorri && scorriM) {
        if(scorri->elemento != scorriM->elemento)
            return false;
        scorri = scorri->dx;
        scorriM = scorriM->dx;
    }

    return true;
}

/*
 * Ritorna il numero di elementi del contenitore con chiave k
 */
template <typename T>
unsigned int Contenitore<T>::count(const T& k) const {
    if(!primo)
        return 0;

    typename Contenitore<T>::Nodo *scorre = primo;
    unsigned int cont = 0;
    while(scorre) {
        if(scorre->elemento == k)
            ++cont;
        scorre = scorre->dx;
    }
    return cont;
}

/*
 * Distrugge ed elimina tutti gli elementi del contenitore
 */
template <typename T>
void Contenitore<T>::clear() {
    delete primo;
    primo = ultimo = 0;
    size = 0;
}



template <typename T>
std::list<T> Contenitore<T>::stdList() const {
    std::list<T> ret;
    typename Contenitore<T>::Nodo *scorre = primo;
    for (unsigned int i = 0; i < size ; ++i, scorre = scorre->dx) {
        ret.push_back(scorre->elemento);
    }
    return ret;
}

template <typename T>
std::vector<T> Contenitore<T>::stdVector() const {
    std::vector<T> ret;
    typename Contenitore<T>::Nodo *scorre = primo;
    for (unsigned int i = 0; i < size ; ++i, scorre = scorre->dx) {
        ret.push_back(scorre->elemento);
    }
    return ret;
}

//////////////////////////////////////////////////////////////////////////////
/// iterator
//////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Contenitore<T>::iterator::operator==(typename Contenitore<T>::iterator i) const {
    return punt == i.punt;
}

template <typename T>
bool Contenitore<T>::iterator::operator!=(typename Contenitore<T>::iterator i) const {
    return punt != i.punt;
}

//prefisso
template <typename T>
typename Contenitore<T>::iterator& Contenitore<T>::iterator::operator++() {
    if(punt)
        punt = punt->dx;
    return *this;
}

//postfisso
template <typename T>
typename Contenitore<T>::iterator Contenitore<T>::iterator::operator++(int) {
    iterator vecchio = *this;
    if(punt)
        punt = punt->dx;
    return vecchio;
}


//prefisso
template <typename T>
typename Contenitore<T>::iterator& Contenitore<T>::iterator::operator--() {
    if(punt)
        punt = punt->sx;
    return *this;
}

//postfisso
template <typename T>
typename Contenitore<T>::iterator Contenitore<T>::iterator::operator--(int) {
    iterator vecchio = *this;
    if(punt)
        punt = punt->sx;
    return vecchio;
}

template <typename T>
T* Contenitore<T>::iterator::operator->() const {
    return &(punt->elemento);
}

template <typename T>
T& Contenitore<T>::iterator::operator*() const {
    return punt->elemento;
}


//////////////////////////////////////////////////////////////////////////////
/// const_iterator
//////////////////////////////////////////////////////////////////////////////
template <typename T>
bool Contenitore<T>::const_iterator::operator==
                        (typename Contenitore<T>::const_iterator i) const
{
    return punt == i.punt;
}

template <typename T>
bool Contenitore<T>::const_iterator::operator!=(
        typename Contenitore<T>::const_iterator i) const
{
    return punt != i.punt;
}

//prefisso
template <typename T>
typename Contenitore<T>::const_iterator&
Contenitore<T>::const_iterator::operator++() const {
    if(punt)
        punt = punt->dx;
    return *this;
}

//postfisso
template <typename T>
typename Contenitore<T>::const_iterator
Contenitore<T>::const_iterator::operator++(int) const {
    const_iterator vecchio = *this;
    if(punt)
        punt = punt->dx;
    return vecchio;
}


//prefisso
template <typename T>
typename Contenitore<T>::const_iterator&
Contenitore<T>::const_iterator::operator--() const {
    if(punt)
        punt = punt->sx;
    return *this;
}

//postfisso
template <typename T>
typename Contenitore<T>::const_iterator
Contenitore<T>::const_iterator::operator--(int) const{
    const_iterator vecchio = *this;
    if(punt)
        punt = punt->sx;
    return vecchio;
}

template <typename T>
const T* Contenitore<T>::const_iterator::operator->() const {
    return &(punt->elemento);
}

template <typename T>
const T& Contenitore<T>::const_iterator::operator*() const {
    return punt->elemento;
}

//////////////////////////////////////////////////////////////////////////////
/// metodi di Contenitore che utilizzano iteratori
//////////////////////////////////////////////////////////////////////////////
template <typename T>
typename Contenitore<T>::iterator Contenitore<T>::begin() {
    typename Contenitore<T>::iterator appoggio;
    appoggio.punt = primo;
    return appoggio;
}

template <typename T>
typename Contenitore<T>::iterator Contenitore<T>::end() {
    typename Contenitore<T>::iterator appoggio;
    appoggio.punt = 0;
    return appoggio;
}

template<typename T>
typename Contenitore<T>::const_iterator Contenitore<T>::begin() const {
    typename Contenitore<T>::const_iterator appoggio;
    appoggio.punt = primo;
    return appoggio;
}

template <typename T>
typename Contenitore<T>::const_iterator Contenitore<T>::end() const {
    typename Contenitore<T>::const_iterator appoggio;
    appoggio.punt = 0;
    return appoggio;
}

template <typename T>
T& Contenitore<T>::operator[](iterator i) const {
    return i.punt->elemento;
}

template <typename T>
typename Contenitore<T>::iterator Contenitore<T>::erase(iterator i) {
    if(size == 0)
        return begin();
    if(i.punt) {
        iterator ret;
        ret.punt = i.punt->dx;
        try {
            eliminaNodo(primo, ultimo, i.punt);
        } catch (ErrContenitore) {throw;}
        size--;
        return ret;
    } else
        return end();
}

/*
 * Ritorna un iterator al primo elemento nella lista che corrisponde alla
 * chiave k. Altrimenti ritorna end().
 */
template <typename T>
typename Contenitore<T>::iterator Contenitore<T>::find(const T& k) const {
    typename Contenitore<T>::Nodo* scorre = primo;
    bool trovato = false;

    while(scorre && !trovato) {
        if(scorre->elemento == k)
            trovato = true;
        scorre = scorre->dx;
    }

    iterator ret;
    if(trovato)
        ret.punt = scorre;
    else
        return end();
}


#endif // CONTENITORE_H

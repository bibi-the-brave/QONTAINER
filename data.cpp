/*
 * Andrea Favero
 * 1125545
 * andrea.favero.8@studenti.unipd.it
 */
#include "data.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>

Data::Data(int y_, int m_, int d_) {
    if( controlloValidita(y_,m_,d_) ) {
        y = y_;
        m = m_;
        d = d_;
        valida = true;
    } else { //la data non è valida, setto il flag
        valida = false;
    }
}

//la stringa passata deve essere delle forma "d/m/y"
Data::Data(std::string data) {
    std::istringstream iss(data);
    std::string s;
    std::getline(iss, s, '/');
    d = std::stoi(s);
    std::getline(iss, s, '/');
    m = std::stoi(s);
    std::getline(iss, s, '/');
    y = std::stoi(s);

    if( controlloValidita(y,m,d) )
        valida = true;
    else
        valida = false;
}

bool Data::controlloValidita(int y, int m, int d) {
    if ( d < 1 || d > 31 || m < 1 || m > 12 ||
         y > MASSIMO_ANNO_VALIDO || y < MINIMO_ANNO_VALIDO)
    {
        return false;
    }

    // Anno bisestile
    if (m == 2) {
        if ( ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0) )
            return d <= 29;
        else
            return d <= 28;
    }

    // Aprile, Giugno, Settembre, Novembre hanno al massimo 30 d.
    if (m == 4 || m == 6 || m == 9 || m == 11)
        return d <= 30;

    return true;
}

bool Data::operator==(const Data& d_) const {
    if( !valida || !d_.valida )
        return false;
    return  d == d_.d && m == d_.m && y == d_.y;
}

bool Data::operator>=(const Data& d) const {
    if( !valida || !d.valida )
        return false;
    if(y >= d.y)
        return  true;
    if(y == d.y && m >= d.m)
        return true;
    if(y == d.y && m == d.m && d >= d)
        return true;
    return false;
}

bool Data::operator<=(const Data& d) const {
    if( !valida || !d.valida )
        return false;
    if(y <= d.y)
        return  true;
    if(y == d.y && m <= d.m)
        return true;
    if(y == d.y && m == d.m && d <= d)
        return true;
    return false;
}

std::string Data::toString() const {
    if(valida)
        return "" + std::to_string(d) + "/" + std::to_string(m) + "/" + std::to_string(y);
    return "indefinita";
}

void Data::setY(int y_) {
    if(valida) {
        valida = controlloValidita(y_,m,d);
        if(valida)
            y = y_;
    }
}

void Data::setM(int m_) {
    if(valida) {
        valida = controlloValidita(y,m_,d);
        if(valida)
            m = m_;
    }
}

void Data::setD(int d_) {
    if(valida) {
        valida = controlloValidita(y,m,d_);
        if(valida)
            d = d_;
    }
}

int Data::getY() const {
    if(valida)
        return y;
    return -1;
}

int Data::getM() const {
    if(valida)
        return m;
    return -1;
}

int Data::getD() const {
    if(valida)
        return d;
    return -1;
}

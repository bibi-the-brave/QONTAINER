#include "data.h"

Data::Data(int y_, int m_, int d_) {
    if( controlloValidita(y_,m_,d_) ) {
        y = y_; m = m_; d = d_;
    } else { //inizializzazione di default
        y = m = d = 0;
    }
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

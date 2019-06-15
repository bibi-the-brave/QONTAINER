#ifndef DATA_H
#define DATA_H


class Data {
public:
    static const int MASSIMO_ANNO_VALIDO = 9999;
    static const int MINIMO_ANNO_VALIDO = 1800;
    Data(int y, int m, int d);
    static bool controlloValidita(int, int, int);
private:
    int y, m, d; //anno, mese, giorno
};

#endif // DATA_H

#ifndef DATA_H
#define DATA_H

#include <string>

// classe che modella una data in modo simile a quanto
// fatto dalla classe QDate
class Data {
public:
    static const int MASSIMO_ANNO_VALIDO = 9999;
    static const int MINIMO_ANNO_VALIDO = 1800;
    Data(int y, int m, int d);
    Data(std::string);
    static bool controlloValidita(int, int, int);
    bool operator==(const Data&) const;
    bool operator>=(const Data&) const;
    bool operator<=(const Data&) const;
    std::string toString() const;
    void setY(int);
    void setM(int);
    void setD(int);
    int getY() const;
    int getM() const;
    int getD() const;
private:
    int y, m, d; //anno, mese, giorno
    bool valida;
};

#endif // DATA_H

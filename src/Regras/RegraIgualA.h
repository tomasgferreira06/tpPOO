#ifndef TPPOO_REGRAIGUALA_H
#define TPPOO_REGRAIGUALA_H

#include "regra.h"

class RegraIgualA : public Regra {
private:
    double valor; // valor para efetuar a comparação

public:
    RegraIgualA(double valor);
    bool aplicarRegra();
};

#endif //TPPOO_REGRAIGUALA_H

#ifndef TPPOO_REGRA_H
#define TPPOO_REGRA_H

#include <string>
using namespace std;

class Regra {

public:
    virtual ~Regra();
    virtual bool avaliar(double valor) const = 0;
};

#endif // TPPOO_REGRA_H

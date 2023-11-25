
#ifndef TPPOO_TEMPERATURA_H
#define TPPOO_TEMPERATURA_H


#include "propriedade.h"

class Temperatura : public Propriedade {
private:
    double valorTemp;

public:
    Temperatura();
    void setValor( double valor);
    double getValor() const;

};


#endif //TPPOO_TEMPERATURA_H

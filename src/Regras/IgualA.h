//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_IGUALA_H
#define TPPOO_IGUALA_H


#include "regra.h"

class IgualA : public Regra{
private:
    double valorComparacao;

public:
    IgualA(double valor);
    bool avaliar(double valor) const override;

};

#endif //TPPOO_IGUALA_H

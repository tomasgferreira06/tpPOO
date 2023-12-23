//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_ENTRE_H
#define TPPOO_ENTRE_H

#include "regra.h"

class Entre : public Regra{

private:
    double valorInferior;
    double valorSuperior;

public:
    Entre(double inferior, double superior);
    bool avaliar(double valor) const override;

};

#endif //TPPOO_ENTRE_H

//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_MENORQUE_H
#define TPPOO_MENORQUE_H

#include "regra.h"

class RegraMenorQue : public Regra{
private:
    double valorComparacao;

public:
    RegraMenorQue(Sensor *sensor, double valor);
    bool avaliar() const override;
    void setValorComparacao(double valorComparacao);
    double getValorComparacao() const;
};

#endif //TPPOO_MENORQUE_H

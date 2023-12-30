//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_MAIORQUE_H
#define TPPOO_MAIORQUE_H

#include "regra.h"

class RegraMaiorQue : public Regra {
private:
    double valorComparacao;

public:
    RegraMaiorQue(Sensor *sensor, double valor);

    bool avaliar() const override;
    Regra* duplica() const override;

    void setValorComparacao(double valorComparacao);

    double getValorComparacao() const;
    std::string getNomeRegra() const override;
};

#endif //TPPOO_MAIORQUE_H

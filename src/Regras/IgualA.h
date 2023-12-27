//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_IGUALA_H
#define TPPOO_IGUALA_H


#include "regra.h"

class RegraIgualA : public Regra {
private:
    double valorComparacao;

public:
    RegraIgualA(Sensor *sensor, double valor);

    bool avaliar() const override;

    void setValorComparacao(double valorComparacao);

    double getValorComparacao() const;
    std::string getNomeRegra() const override;
};

#endif //TPPOO_IGUALA_H

//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_FORA_H
#define TPPOO_FORA_H

#include "regra.h"

class RegraFora : public Regra {
private:
    double valorMin;
    double valorMax;

public:
    RegraFora(Sensor *sensor, double min,double max);

    bool avaliar() const override;

    double getValorMin() const;

    void setValorMin(double valorMin);

    double getValorMax() const;

    void setValorMax(double valorMax);
    std::string getNomeRegra() const override;
};

#endif //TPPOO_FORA_H

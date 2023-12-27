//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_ENTRE_H
#define TPPOO_ENTRE_H

#include "regra.h"

class RegraEntre : public Regra {
private:
    double valorMin;
    double valorMax;

public:
    RegraEntre(Sensor *sensor, double min,double max);

    bool avaliar() const override;

    double getValorMin() const;

    void setValorMin(double valorMin);

    double getValorMax() const;

    void setValorMax(double valorMax);
};

#endif //TPPOO_ENTRE_H

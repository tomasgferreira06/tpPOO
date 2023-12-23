//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_SENSORFUMO_H
#define TPPOO_SENSORFUMO_H

#include "sensor.h"
#include "../Propriedades/fumo.h"


class sensorFumo : public Sensor{

private:
    Fumo & propriedade;

public:
    sensorFumo(Fumo & fum);
    char getLetraVisualizacao() const override;
    double lerValor() const override;
};

#endif //TPPOO_SENSORFUMO_H

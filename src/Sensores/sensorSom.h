//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_SENSORSOM_H
#define TPPOO_SENSORSOM_H

#include "sensor.h"
#include "../Propriedades/som.h"

class sensorSom : public Sensor{

private:
    Som & propriedade;

public:
    sensorSom(Som & som);
    char getLetraVisualizacao() const override;
    double lerValor() const override;


};

#endif //TPPOO_SENSORSOM_H

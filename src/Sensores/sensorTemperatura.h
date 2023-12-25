//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_SENSORTEMPERATURA_H
#define TPPOO_SENSORTEMPERATURA_H

#include "sensor.h"
#include "../Propriedades/temperatura.h"

class SensorTemperatura : public Sensor{

private:
    Temperatura & propriedade;

public:
    SensorTemperatura(Temperatura& temp);
    char getLetraVisualizacao() const override;
    double lerValor() const override;


};

#endif //TPPOO_SENSORTEMPERATURA_H

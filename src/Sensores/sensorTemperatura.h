//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_SENSORTEMPERATURA_H
#define TPPOO_SENSORTEMPERATURA_H

#include "sensor.h"
#include "../Propriedades/temperatura.h"

class SensorTemperatura : public Sensor{

private:
    float temperatura;

public:
    SensorTemperatura();
    double getTemperatura() const;
    void setTemperatura(float temperatura);


};

#endif //TPPOO_SENSORTEMPERATURA_H

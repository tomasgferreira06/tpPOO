//
// Created by 35191 on 26/12/2023.
//

#ifndef TPPOO_SENSORHUMIDADE_H
#define TPPOO_SENSORHUMIDADE_H


#include "sensor.h"
#include "../Propriedades/temperatura.h"

class SensorHumidade : public Sensor{

private:
    float humidade;

public:
    SensorHumidade();
    double getHumidade() const;
    void setHumidade(float humidade);


};

#endif //TPPOO_SENSORHUMIDADE_H

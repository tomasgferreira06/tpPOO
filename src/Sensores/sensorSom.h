//
// Created by 35191 on 26/12/2023.
//

#ifndef TPPOO_SENSORSOM_H
#define TPPOO_SENSORSOM_H


#include "sensor.h"
#include "../Propriedades/temperatura.h"

class SensorSom : public Sensor{

private:
    float som;

public:
    SensorSom();
    double getSom() const;
    void setSom(float som);


};

#endif //TPPOO_SENSORSOM_H

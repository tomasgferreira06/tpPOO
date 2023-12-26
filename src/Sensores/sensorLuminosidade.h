//
// Created by 35191 on 26/12/2023.
//

#ifndef TPPOO_SENSORLUMINOSIDADE_H
#define TPPOO_SENSORLUMINOSIDADE_H

#include "sensor.h"
#include "../Propriedades/temperatura.h"

class SensorLuminosidade : public Sensor{

private:
    float luz;

public:
    SensorLuminosidade();
    double getLuz() const;
    void setLuz(float luz);
    std::string getInfo() const override;


};

#endif //TPPOO_SENSORLUMINOSIDADE_H

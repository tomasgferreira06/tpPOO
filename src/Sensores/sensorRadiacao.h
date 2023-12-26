//
// Created by 35191 on 26/12/2023.
//

#ifndef TPPOO_SENSORRADIACAO_H
#define TPPOO_SENSORRADIACAO_H

#include "sensor.h"
#include "../Propriedades/temperatura.h"

class SensorRadiacao : public Sensor{

private:
    float radiacao;

public:
    SensorRadiacao();
    double getRadiacao() const;
    void setRadiacao(float radiacao);
    std::string getInfo() const override;


};

#endif //TPPOO_SENSORRADIACAO_H

//
// Created by 35191 on 26/12/2023.
//

#ifndef TPPOO_SENSORMOVIMENTO_H
#define TPPOO_SENSORMOVIMENTO_H

#include "sensor.h"
#include "../Propriedades/temperatura.h"

class SensorMovimento : public Sensor{

private:
    float vibracao;

public:
    SensorMovimento();
    double getVibracao() const;
    void setVibracao(float vibracao);
    std::string getInfo() const override;


};

#endif //TPPOO_SENSORMOVIMENTO_H

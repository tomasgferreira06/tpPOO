//
// Created by 35191 on 26/12/2023.
//

#ifndef TPPOO_SENSORRADIACAO_H
#define TPPOO_SENSORRADIACAO_H

#include "sensor.h"
#include "../Propriedades/Radiacao.h"
#include "../Zonas/zona.h"

class SensorRadiacao : public Sensor{

private:
    float radiacao;

public:
    SensorRadiacao(Zona *a);
    double getRadiacao() const;
    std::string getInfo() const override;
    double getValor() const override;
    std::string getTipoSensor() const override;

};

#endif //TPPOO_SENSORRADIACAO_H

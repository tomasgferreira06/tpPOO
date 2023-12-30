//
// Created by 35191 on 26/12/2023.
//

#ifndef TPPOO_SENSORLUMINOSIDADE_H
#define TPPOO_SENSORLUMINOSIDADE_H

#include "sensor.h"
#include "../Propriedades/luz.h"
#include "../Zonas/zona.h"

class SensorLuminosidade : public Sensor{

private:
    float luz;

public:
    SensorLuminosidade(Zona *a);
    double getLuz() const;
    std::string getInfo() const override;
    double getValor() const override;
    std::string getTipoSensor() const override;


};

#endif //TPPOO_SENSORLUMINOSIDADE_H

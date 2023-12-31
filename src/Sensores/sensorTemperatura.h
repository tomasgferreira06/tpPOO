//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_SENSORTEMPERATURA_H
#define TPPOO_SENSORTEMPERATURA_H

#include "sensor.h"
#include "../Propriedades/temperatura.h"
#include "../Zonas/zona.h"

class SensorTemperatura : public Sensor{

private:
    float temperatura;

public:
    SensorTemperatura(Zona *a);
    double getTemperatura() const;
    std::string getInfo() const override;
    double getValor() const override; // função virtual para a medição do sensorTemperatura
    std::string getTipoSensor() const override;



};

#endif //TPPOO_SENSORTEMPERATURA_H

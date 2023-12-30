//
// Created by 35191 on 26/12/2023.
//

#ifndef TPPOO_SENSORSOM_H
#define TPPOO_SENSORSOM_H


#include "sensor.h"
#include "../Propriedades/som.h"
#include "../Zonas/zona.h"

class SensorSom : public Sensor{

private:
    float som;

public:
    SensorSom(Zona *a);
    double getSom() const;
    std::string getInfo() const override;
    double getValor() const override;
    std::string getTipoSensor() const override;


};

#endif //TPPOO_SENSORSOM_H

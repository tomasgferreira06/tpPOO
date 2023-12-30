//
// Created by 35191 on 26/12/2023.
//

#ifndef TPPOO_SENSORHUMIDADE_H
#define TPPOO_SENSORHUMIDADE_H


#include "sensor.h"
#include "../Propriedades/humidade.h"
#include "../Zonas/zona.h"

class SensorHumidade : public Sensor{

private:
    float humidade;


public:

    SensorHumidade(Zona *a);
    double getHumidade() const;
    std::string getInfo() const override;
    double getValor() const override;
    std::string getTipoSensor() const override;


};

#endif //TPPOO_SENSORHUMIDADE_H

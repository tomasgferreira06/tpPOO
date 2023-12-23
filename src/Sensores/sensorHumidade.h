//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_SENSORHUMIDADE_H
#define TPPOO_SENSORHUMIDADE_H

#include "sensor.h"
#include "../Propriedades/humidade.h"

class sensorHumidade : public Sensor{

private:
    Humidade & propriedade;

public:
    sensorHumidade(Humidade & hum);
    char getLetraVisualizacao() const override;
    double lerValor() const override;



};

#endif //TPPOO_SENSORHUMIDADE_H

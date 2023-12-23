//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_SENSORLUMINOSIDADE_H
#define TPPOO_SENSORLUMINOSIDADE_H


#include "sensor.h"
#include "../Propriedades/luz.h"

class SensorLuminosidade : public Sensor{

private:
   Luz & propriedade;

public:
    SensorLuminosidade(Luz& luz);
    char getLetraVisualizacao() const override;
    double lerValor() const override;

};

#endif //TPPOO_SENSORLUMINOSIDADE_H

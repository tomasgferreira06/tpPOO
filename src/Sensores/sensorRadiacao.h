//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_SENSORRADIACAO_H
#define TPPOO_SENSORRADIACAO_H

#include "sensor.h"
#include "../Propriedades/radiacao.h"

class sensorRadiacao : public Sensor{

private:
    Radiacao & propriedade;

public:
    sensorRadiacao(Radiacao & rad);
    char getLetraVisualizacao() const override;
    double lerValor() const override;


};


#endif //TPPOO_SENSORRADIACAO_H

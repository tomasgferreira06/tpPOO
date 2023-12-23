//
// Created by 35191 on 23/12/2023.
//

#ifndef TPPOO_SENSORMOVIMENTO_H
#define TPPOO_SENSORMOVIMENTO_H

#include "sensor.h"
#include "../Propriedades/Vibracao.h"

class SensorMovimento : public Sensor{

private:
    Vibracao & propriedade;

public:
    SensorMovimento(Vibracao& mov);
    char getLetraVisualizacao() const override;
    double lerValor() const override;

};



#endif //TPPOO_SENSORMOVIMENTO_H

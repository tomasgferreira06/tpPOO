//
// Created by 35191 on 26/12/2023.
//

#ifndef TPPOO_SENSORFUMO_H
#define TPPOO_SENSORFUMO_H




#include "sensor.h"
#include "../Propriedades/temperatura.h"

class SensorFumo : public Sensor{

private:
    float fumo;

public:
    SensorFumo();
    double getFumo() const;
    void setFumo(float fumo);


};




#endif //TPPOO_SENSORFUMO_H

//
// Created by 35191 on 26/12/2023.
//

#ifndef TPPOO_SENSORFUMO_H
#define TPPOO_SENSORFUMO_H




#include "sensor.h"
#include "../Propriedades/som.h"
#include "../Zonas/zona.h"

class SensorFumo : public Sensor{

private:
    float fumo;

public:
    SensorFumo(Zona *a);
    double getFumo() const;
    std::string getInfo() const override;
    double getValor() const override;
    std::string getTipoSensor() const override;


};




#endif //TPPOO_SENSORFUMO_H

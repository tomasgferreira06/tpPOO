//
// Created by 35191 on 26/12/2023.
//

#include <sstream>
#include "sensorFumo.h"

SensorFumo::SensorFumo(Zona *a) : Sensor(a), fumo(0.0){}

double SensorFumo::getFumo() const {
    Zona* zonaAssociada = getZonaAssociada();
    if(zonaAssociada){
        Propriedade* fumoPropriedade = zonaAssociada->getPropriedade("Fumo");
        if(fumoPropriedade){
           return fumoPropriedade->getValor();
        }
    }
}


std::string SensorFumo::getInfo() const {
    std::ostringstream ss;
    ss << 's' << getIdSensor() << "Fumo" << getFumo();
    return ss.str();
}

double SensorFumo::getValor() const {
    return getFumo();
}

std::string SensorFumo::getTipoSensor() const {
    return "Fumo";
}

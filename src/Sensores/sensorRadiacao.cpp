//
// Created by 35191 on 26/12/2023.
//

#include <sstream>
#include "sensorRadiacao.h"

SensorRadiacao::SensorRadiacao(Zona *a) : Sensor(a), radiacao(0.0) {}

double SensorRadiacao::getRadiacao() const {
    Zona *zonaAssociada = getZonaAssociada();
    if(zonaAssociada){
        Propriedade* radPropriedade = zonaAssociada->getPropriedade("Radiacao");
        if(radPropriedade){
            return radPropriedade->getValor();
        }
    }

}


std::string SensorRadiacao::getInfo() const {
    std::ostringstream ss;
    ss << 's' << getIdSensor() << "Radiacao" << getRadiacao();
    return ss.str();
}

double SensorRadiacao::getValor() const {
    return getRadiacao();
}

std::string SensorRadiacao::getTipoSensor() const {
    return "Radiacao";
}

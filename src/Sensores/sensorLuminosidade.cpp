//
// Created by 35191 on 26/12/2023.
//

#include <sstream>
#include "sensorLuminosidade.h"

SensorLuminosidade::SensorLuminosidade(Zona *a) : Sensor(a),luz() {

}

double SensorLuminosidade::getLuz() const {
    Zona* zonaAssociada = getZonaAssociada();
    if(zonaAssociada){
        Propriedade* luzPropriedade = zonaAssociada->getPropriedade("Luz");
        if(luzPropriedade){
            return luzPropriedade->getValor();
        }
    }
    return 0.0;
}


std::string SensorLuminosidade::getInfo() const {
    std::ostringstream ss;
    ss << 's' << getIdSensor() << " Luz " << getLuz();
    return ss.str();
}

double SensorLuminosidade::getValor() const {
   return getLuz();
}

std::string SensorLuminosidade::getTipoSensor() const {
    return "Luminosidade";
}

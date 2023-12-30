//
// Created by 35191 on 26/12/2023.
//

#include <sstream>
#include "sensorSom.h"

SensorSom::SensorSom(Zona *a) : Sensor(a), som(0.0) {

}

double SensorSom::getSom() const {
    Zona* zonaAssociada = getZonaAssociada();
    if (zonaAssociada) {
        Propriedade* somPropriedade = zonaAssociada->getPropriedade("Som");
        if (somPropriedade) {
            return somPropriedade->getValor();
        }
    }
}


std::string SensorSom::getInfo() const {
        std::ostringstream ss;
        ss << 's' << getIdSensor() << "Som" << getSom();
        return ss.str();
}

double SensorSom::getValor() const {
    return getSom();
}

std::string SensorSom::getTipoSensor() const {
    return "Som";
}

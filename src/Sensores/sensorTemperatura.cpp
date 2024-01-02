//
// Created by 35191 on 23/12/2023.
//

#include <sstream>
#include "sensorTemperatura.h"

SensorTemperatura::SensorTemperatura(Zona *a) : Sensor(a), temperatura(){
}

double SensorTemperatura::getTemperatura() const {
    Zona* zonaAssociada = getZonaAssociada();
    if (zonaAssociada) {
        Propriedade* tempPropriedade = zonaAssociada->getPropriedade("Temperatura");
        if (tempPropriedade) {
            return tempPropriedade->getValor();
        }
    }
    return 0.0; // Retorno padrão se a zona associada ou a propriedade não for encontrada
}

std::string SensorTemperatura::getInfo() const {
    std::ostringstream ss;
    ss << 's' << getIdSensor() << " Temperatura " << getTemperatura();
    return ss.str();
}

double SensorTemperatura::getValor() const {
    return getTemperatura();
}

std::string SensorTemperatura::getTipoSensor() const {
    return "Temperatura";
}



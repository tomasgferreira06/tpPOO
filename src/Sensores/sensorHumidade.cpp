

#include <sstream>
#include "sensorHumidade.h"

SensorHumidade::SensorHumidade(Zona *a) : Sensor(a), humidade(0.0) {}

double SensorHumidade::getHumidade() const {
    Zona *zonaAssociada = getZonaAssociada();
    if(getZonaAssociada()){
        Propriedade* humPropriedade = zonaAssociada->getPropriedade("Humidade");
        if(humPropriedade){
            return humPropriedade->getValor();
        }
    }
    return 0.0;
}



std::string SensorHumidade::getInfo() const {
    std::ostringstream ss;
    ss << 's' << getIdSensor() << "Humidade" << getHumidade();
    return ss.str();
}

double SensorHumidade::getValor() const {
    return getHumidade();
}

std::string SensorHumidade::getTipoSensor() const {
    return "Humidade";
}

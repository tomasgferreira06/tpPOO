
#include <sstream>
#include "sensorMovimento.h"

SensorMovimento::SensorMovimento(Zona *a) : Sensor(a), vibracao(0.0){}


double SensorMovimento::getVibracao() const {
    Zona* zonaAssociada = getZonaAssociada();
    if(zonaAssociada){
        Propriedade *movPropriedade = zonaAssociada->getPropriedade("Movimento");
        if(movPropriedade){
            return movPropriedade->getValor();
        }
    }
    return 0.0;
}



std::string SensorMovimento::getInfo() const {
    std::ostringstream ss;
    ss << 's' << getIdSensor() << "Movimento" << getVibracao();
    return ss.str();
}

double SensorMovimento::getValor() const {
    return getVibracao();
}

std::string SensorMovimento::getTipoSensor() const {
    return "Movimento";
}

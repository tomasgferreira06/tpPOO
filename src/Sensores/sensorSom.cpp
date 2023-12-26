//
// Created by 35191 on 26/12/2023.
//

#include <sstream>
#include "sensorSom.h"

SensorSom::SensorSom() : Sensor(), som(0.0) {

}

double SensorSom::getSom() const {
    return som;
}

void SensorSom::setSom(float som) {
    SensorSom::som = som;
}

std::string SensorSom::getInfo() const {

        std::ostringstream ss;
        ss << 's' << getIdSensor() << "Som" << getSom();
        return ss.str();


}

//
// Created by 35191 on 26/12/2023.
//

#include "sensorLuminosidade.h"

SensorLuminosidade::SensorLuminosidade() : Sensor(),luz(0.0) {

}

double SensorLuminosidade::getLuz() const {
    return luz;
}

void SensorLuminosidade::setLuz(float luz) {
    SensorLuminosidade::luz = luz;
}

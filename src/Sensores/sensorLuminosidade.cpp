//
// Created by 35191 on 23/12/2023.
//

#include "sensorLuminosidade.h"

SensorLuminosidade::SensorLuminosidade(Luz &luz) : propriedade(luz){}

char SensorLuminosidade::getLetraVisualizacao() const {
    return 'm';
}

double SensorLuminosidade::lerValor() const {
    return propriedade.getValor();
}

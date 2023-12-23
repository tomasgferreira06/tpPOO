//
// Created by 35191 on 23/12/2023.
//

#include "sensorHumidade.h"

sensorHumidade::sensorHumidade(Humidade &hum) : propriedade(hum){}

char sensorHumidade::getLetraVisualizacao() const {
    return 'h';
}

double sensorHumidade::lerValor() const {
    return propriedade.getValor();
}

//
// Created by User on 28/12/2023.
//

#include <sstream>
#include "aspersor.h"
#include "aparelho.h"
#include "../Propriedades/propriedade.h"

Aspersor::Aspersor(Zona *pZona) : Aparelho(pZona) , contador(0){}

void Aspersor::liga() {
    if(!estaLigado()){
        setLigado(true);
    }
}

void Aspersor::desliga() {
    if(estaLigado()){
        setLigado(false);
    }
}

void Aspersor::executar() {
    Zona* zona = getZonaAssociada();
    if (zona) {
        const std::vector<Sensor*>& sensores = zona->getSensores();
        double humidadeAtual = 0.0;
        double vibracaoAtual = 0.0;
        bool encontrouSensorHumidade = false;
        bool encontrouSensorVibracao = false;

        // Procurar pelos sensores de umidade e vibração
        for (Sensor* sensor : sensores) {
            if (sensor->getTipoSensor() == "Humidade") {
                humidadeAtual = sensor->getValor();
                encontrouSensorHumidade = true;
            } else if (sensor->getTipoSensor() == "Vibracao") {
                vibracaoAtual = sensor->getValor();
                encontrouSensorVibracao = true;
            }
        }

        // Se o aspersor está ligado ou em período de desligamento controlado (contador <= 5)
        if (estaLigado() || contador <= 5) {
            if (contador == 0 && encontrouSensorHumidade) {
                // Adiciona humidade no primeiro instante de ligado
                Propriedade* propHumidade = zona->getPropriedade("Humidade");
                if (propHumidade && humidadeAtual < 75) {
                    propHumidade->setValor(std::min(75.0, humidadeAtual + 50));
                }
            }

            if (contador == 0 && encontrouSensorVibracao) {
                // Adiciona vibração no primeiro instante de ligado
                Propriedade* propVibracao = zona->getPropriedade("Vibracao");
                if (propVibracao) {
                    propVibracao->setValor(vibracaoAtual + 100);
                }
            }

            if (contador == 1) {
                // No segundo instante, coloca o fumo a 0
                Propriedade* propFumo = zona->getPropriedade("Fumo");
                if (propFumo) {
                    propFumo->setValor(0);
                }
            }

            contador++;
        } else {
            // Reseta o contador depois do período de desligamento controlado
            if (contador > 5) {
                contador = 0;
            }
        }

        // Se o aspersor foi desligado e o contador foi reiniciado, remover a vibração
        if (!estaLigado() && contador == 0 && encontrouSensorVibracao) {
            Propriedade* propVibracao = zona->getPropriedade("Vibracao");
            if (propVibracao && vibracaoAtual >= 100) {
                propVibracao->setValor(vibracaoAtual - 100);
            }
        }
    }
}


std::string Aspersor::getNome() const{
    std::ostringstream ss;
    ss << "Aspersor" << getUltimoComando();
    return ss.str();
}

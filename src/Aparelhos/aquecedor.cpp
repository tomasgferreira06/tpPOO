//
// Created by 35191 on 24/12/2023.
//

#include <sstream>
#include "aquecedor.h"
#include "aparelho.h"
#include "../Propriedades/propriedade.h"


Aquecedor::Aquecedor(Zona *pZona) : Aparelho(pZona), contador(0), adicionouRuido(false) {}

void Aquecedor::liga() {
    if(!estaLigado()){ // se não está ligado, liga.
        setLigado(true);
        adicionouRuido = false; // resetar a flag
    }
}

void Aquecedor::desliga() {
    if(estaLigado()){ // se está ligado, desliga.
        setLigado(false);
    }
}

void Aquecedor::executar() {
    Zona* zona = getZonaAssociada();
    bool encontrouSensorSom = false;
    double somAtual = 0.0;
    double temperaturaAtual = 0.0;
    bool encontrouSensorTemperatura = false;

    // Mova a procura pelos sensores para fora do if do estado ligado
    if (zona) {
        const std::vector<Sensor*>& sensores = zona->getSensores();

        for (Sensor* sensor : sensores) {
            if (sensor->getTipoSensor() == "Temperatura") {
                temperaturaAtual = sensor->getValor();
                encontrouSensorTemperatura = true;
            } else if (sensor->getTipoSensor() == "Som") {
                somAtual = sensor->getValor();
                encontrouSensorSom = true;
            }
        }
    }

    if (estaLigado()) {
        // Adicionar ruído se ainda não foi adicionado
        if (!isAdicionouRuido() && encontrouSensorSom) {
            Propriedade* propSom = zona->getPropriedade("Som");
            if (propSom) {
                propSom->setValor(somAtual + 5);
                setAdicionouRuido(true);
            }
        }

        // Aumentar temperatura a cada 3 instantes até um máximo de 50 graus
        contador++;
        if (contador % 3 == 0 && encontrouSensorTemperatura && temperaturaAtual < 50) {
            Propriedade* propTemp = zona->getPropriedade("Temperatura");
            if (propTemp) {
                propTemp->setValor(temperaturaAtual + 1);
            }
        }
    } else if(!estaLigado()) { // se está desligado
        // Ao desligar o aquecedor, remova o ruído adicionado
        if (adicionouRuido && encontrouSensorSom) {
            Propriedade* propSom = zona->getPropriedade("Som");
            if (propSom) {
                propSom->setValor(std::max(0.0, somAtual - 5));
                adicionouRuido = false;
            }
        }
        contador = 0; // Resetar o contador quando o aquecedor é desligado
    }
}

// A variável 'contador' e 'adicionouRuido' devem ser membros da classe Aquecedor

std::string Aquecedor::getNome() const{
    std::ostringstream ss;
    ss << "Aquecedor" << getUltimoComando();
    return ss.str();
}

bool Aquecedor::isAdicionouRuido() const {
    return adicionouRuido;
}

void Aquecedor::setAdicionouRuido(bool adicionouRuido) {
    Aquecedor::adicionouRuido = adicionouRuido;
}

//
// Created by 35191 on 24/12/2023.
//

#include <sstream>
#include "aquecedor.h"
#include "aparelho.h"
#include "../Propriedades/propriedade.h"


Aquecedor::Aquecedor(Zona *pZona) : Aparelho(pZona), contador(0), adicionouRuido(false) {}

void Aquecedor::liga(term::Window & com_efetuadosWindow) {
    if(!estaLigado()){ // se não está ligado, liga.
        setLigado(true);
        setAdicionouRuido(false);
        com_efetuadosWindow << "O aquecedor foi ligado." << term::move_to(0,  com_efetuadosWindow.get_current_row() + 1);
    }
}

void Aquecedor::desliga(term::Window & com_efetuadosWindow) {
    if(estaLigado()){ // se está ligado, desliga.
        setLigado(false);
        com_efetuadosWindow << "O aquecedor foi desligado." << term::move_to(0,  com_efetuadosWindow.get_current_row() + 1);
    }
}

void Aquecedor::executar(term::Window & com_efetuadosWindow) {
    Zona* zona = getZonaAssociada();
    bool encontrouSensorSom = false;
    double somAtual = 0.0;
    double temperaturaAtual = 0.0;
    bool encontrouSensorTemperatura = false;


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
        setContador(getContador() + 1);
        if (getContador() % 3 == 0 && encontrouSensorTemperatura && temperaturaAtual < 50) {
            Propriedade* propTemp = zona->getPropriedade("Temperatura");
            if (propTemp) {
                propTemp->setValor(temperaturaAtual + 1);
            }
        }
    } else if(!estaLigado()) {
        // Ao desligar o aquecedor, remover o ruído adicionado
        if (isAdicionouRuido() && encontrouSensorSom) {
            Propriedade* propSom = zona->getPropriedade("Som");
            if (propSom) {
                propSom->setValor(std::max(0.0, somAtual - 5));
                setAdicionouRuido(false);
            }
        }
        setContador(0); // Resetar o contador quando o aquecedor é desligado
    }
}


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

int Aquecedor::getContador() const {
    return contador;
}

void Aquecedor::setContador(int contador) {
    Aquecedor::contador = contador;
}

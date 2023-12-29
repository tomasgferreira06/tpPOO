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
    if (estaLigado() && zona) {
        const std::vector<Sensor*>& sensores = zona->getSensores();

        // Procurar pelo sensor de temperatura
        double temperaturaAtual = 0.0;
        bool encontrouSensorTemperatura = false;
        for (Sensor* sensor : sensores) {
            if (sensor->getTipoSensor() == "Temperatura") {
                temperaturaAtual = sensor->getValor();
                encontrouSensorTemperatura = true;
                break;
            }
        }

        if (!adicionouRuido) {
            // Adicionar ruído lógico
            Propriedade *propSom = zona->getPropriedade("Som");
            if (propSom) {
                propSom->setValor(propSom->getValor() + 5);
            }
            adicionouRuido = true;
        }

        contador++;
        if (contador % 3 == 0 && encontrouSensorTemperatura && temperaturaAtual < 50) {
            Propriedade* propTemp = zona->getPropriedade("Temperatura");
            if (propTemp) {
                propTemp->setValor(temperaturaAtual + 1); // Aumenta a temperatura com base no sensor
            }
        }
    } else if (!estaLigado() && adicionouRuido) {
        // Remover ruído
        Propriedade* propSom = zona->getPropriedade("Som");
        if (propSom) {
            propSom->setValor(std::max(0, propSom->getValor() - 5)); // Remove 5 dB, garantindo que não fique negativo
        }
        adicionouRuido = false;
    }
}




std::string Aquecedor::getNome() const{
    std::ostringstream ss;
    ss << "Aquecedor" << getUltimoComando();
    return ss.str();
}

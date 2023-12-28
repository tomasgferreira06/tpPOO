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
        if (!adicionouRuido) {
            Propriedade *propSom = zona->getPropriedade("Som");
            if(propSom){
                propSom->setValor(propSom->getValor() + 5);
            }
            adicionouRuido = true;
        }

        contador++;
        if (contador % 3 == 0) {
            Propriedade* propTemp = zona->getPropriedade("Temperatura");
            if (propTemp && propTemp->getValor() < 50){
                propTemp->setValor(propTemp->getValor() + 1); // Aumenta 1ºC
            }
        }
    }else if(!estaLigado() && adicionouRuido){
        // Remover ruído
        Propriedade* propSom = zona->getPropriedade("Som");
        if (propSom) {
            propSom->setValor(max(0, propSom->getValor() - 5)); // Remove 5 dB, garantindo que não fique negativo
        }
        adicionouRuido = false;
    }
}



std::string Aquecedor::getNome() const{
    std::ostringstream ss;
    ss << "Aquecedor" << getUltimoComando();
    return ss.str();
}

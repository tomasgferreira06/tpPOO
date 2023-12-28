//
// Created by User on 28/12/2023.
//

#include <sstream>
#include "aspersor.h"

Aspersor::Aspersor() : Aparelho() {}

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
std::string Aspersor::getNome() const{
    std::ostringstream ss;
    ss << "Aspersor" << getUltimoComando();
    return ss.str();
}

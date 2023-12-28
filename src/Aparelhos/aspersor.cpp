//
// Created by User on 28/12/2023.
//

#include <sstream>
#include "aspersor.h"

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
    if (estaLigado()) {
        // A lógica de adicionar calor a cada 3 instantes até um máximo de 50 graus
        // e adicionar 5 dB de ruído uma única vez vai aqui
        // Você precisará de acesso à zona ou às propriedades para modificar a temperatura
        contador++;
        if (contador % 3 == 0) {
            // Aumentar a temperatura da zona
        }
    }
}
std::string Aspersor::getNome() const{
    std::ostringstream ss;
    ss << "Aspersor" << getUltimoComando();
    return ss.str();
}

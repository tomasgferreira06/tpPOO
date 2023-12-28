//
// Created by 35191 on 24/12/2023.
//

#include <sstream>
#include "aquecedor.h"
#include "aparelho.h"




Aquecedor::Aquecedor(Zona *pZona) : Aparelho(pZona), contador(0) {}

void Aquecedor::liga() {
    if(!estaLigado()){
        setLigado(true);
    }
}

void Aquecedor::desliga() {
    if(estaLigado()){
        setLigado(false);
    }
}

void Aquecedor::executar() {
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
std::string Aquecedor::getNome() const{
    std::ostringstream ss;
    ss << "Aquecedor" << getUltimoComando();
    return ss.str();
}

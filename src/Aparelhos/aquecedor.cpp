//
// Created by 35191 on 24/12/2023.
//

#include <sstream>
#include "aquecedor.h"
#include "aparelho.h"




Aquecedor::Aquecedor() : Aparelho() {}

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
/*std::string Aquecedor::getNome() const{
    std::ostringstream ss;
    ss << "Aquecedor" << ultimoComando;
    return ss.str();
}*/

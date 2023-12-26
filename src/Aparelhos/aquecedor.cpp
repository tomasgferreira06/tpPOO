//
// Created by 35191 on 24/12/2023.
//

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

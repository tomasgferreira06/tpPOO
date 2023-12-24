//
// Created by 35191 on 24/12/2023.
//

#include "aquecedor.h"
#include "aparelho.h"



void Aquecedor::liga() {
    if(!estaLigado()){
        //Liga o aquecedor
        setLigado(true);
        //Implementar outras operações para quando o aquecedor é ligado
    }
}

void Aquecedor::desliga() {
    if (estaLigado()) {
        // Desliga o aquecedor
        setLigado(false);
        //Implementar outras operações para quando o aquecedor é desligado
    }
}

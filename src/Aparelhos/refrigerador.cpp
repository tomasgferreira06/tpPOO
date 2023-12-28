
#include "refrigerador.h"

#include <sstream>


Refrigerador::Refrigerador() : Aparelho(),contador(0) {}

void Refrigerador::liga() {
    if(!estaLigado()){
        setLigado(true);
    }
}

void Refrigerador::desliga() {
    if(estaLigado()){
        setLigado(false);
    }
}

void Refrigerador::executar() {
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
std::string Refrigerador::getNome() const{
    std::ostringstream ss;
    ss << "Refrigerador" << getUltimoComando();
    return ss.str();
}

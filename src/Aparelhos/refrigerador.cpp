
#include "refrigerador.h"

#include <sstream>


Refrigerador::Refrigerador() : Aparelho() {}

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
std::string Refrigerador::getNome() const{
    std::ostringstream ss;
    ss << "Refrigerador" << getUltimoComando();
    return ss.str();
}

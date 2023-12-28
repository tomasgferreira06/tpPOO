
#include "lampada.h"
#include <sstream>


Lampada::Lampada() : Aparelho() {}

void Lampada::liga() {
    if(!estaLigado()){
        setLigado(true);
    }
}

void Lampada::desliga() {
    if(estaLigado()){
        setLigado(false);
    }
}
std::string Lampada::getNome() const{
    std::ostringstream ss;
    ss << "Lampada" << getUltimoComando();
    return ss.str();
}

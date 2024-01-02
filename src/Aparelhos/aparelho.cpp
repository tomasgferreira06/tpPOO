
#include "aparelho.h"

int Aparelho::nextIdAparelho = 0;

Aparelho::Aparelho(Zona* zona) : zonaAssociada(zona), idAparelho(nextIdAparelho),ligado(false),ultimoComando("desliga") {
    nextIdAparelho++;
}

bool Aparelho::estaLigado() const {
    return ligado;  // retorna true se o aparelho está ligado, retorna false se o aparelho está desligado
}
void Aparelho::receberComando(const std::string& comando, term::Window & com_efetuadosWindow) {
    if (comando == "liga") {
        setLigado(true); // atualiza o estado do aparelho e atualiza o último comando
        liga(com_efetuadosWindow);

    } else if (comando == "desliga") {
        setLigado(false);// atualiza o estado do aparelho e atualiza o último comando
        desliga(com_efetuadosWindow);
    }
}

void Aparelho::setLigado(bool estado) {
    ligado = estado;
    ultimoComando = estado ? "liga" : "desliga"; // Atualiza o último comando
}

int Aparelho::getIdAparelho() const {
    return idAparelho;
}

const std::string &Aparelho::getUltimoComando() const {
    return ultimoComando;
}

void Aparelho::setUltimoComando(const std::string &ultimoComando) {
    Aparelho::ultimoComando = ultimoComando;
}

Zona *Aparelho::getZonaAssociada() const {
    return zonaAssociada;
}




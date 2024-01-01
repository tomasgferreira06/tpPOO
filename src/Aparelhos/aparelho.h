#ifndef TPPOO_APARELHO_H
#define TPPOO_APARELHO_H

#include <string>
#include "../../lib/Terminal.h"

class Zona;  // Declaração de classe para frente

class Aparelho {
private:
    Zona* zonaAssociada;
    bool ligado;
    int idAparelho;
    static int nextIdAparelho;
    std::string ultimoComando;
public:
    Aparelho(Zona *zona);

    virtual void liga(term::Window & com_efetuadosWindow) = 0;
    virtual void desliga(term::Window & com_efetuadosWindow) = 0;
    virtual void executar(term::Window & com_efetuadosWindow) = 0; // Método para aplicar o efeito do aparelho a cada instante
    void receberComando(const std::string& comando, term::Window & com_efetuadosWindow); // Método para receber comandos

    bool estaLigado() const;
    void setLigado(bool estado);
    int getIdAparelho() const;
    virtual std::string getNome() const = 0;

    const std::string &getUltimoComando() const;
    Zona *getZonaAssociada() const;

    void setUltimoComando(const std::string &ultimoComando);
    virtual ~Aparelho() = default;

};

#endif //TPPOO_APARELHO_H

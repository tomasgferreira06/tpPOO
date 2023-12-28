#ifndef TPPOO_APARELHO_H
#define TPPOO_APARELHO_H

#include <string>
class Zona;  // Declaração de classe para frente

class Aparelho {
private:
   bool ligado;
   int idAparelho;
   static int nextIdAparelho;
   std::string ultimoComando;
public:
    Aparelho();
    virtual void liga() = 0;
    virtual void desliga() = 0;


    bool estaLigado() const;
    void setLigado(bool estado);
    int getIdAparelho() const;
    virtual std::string getNome() const = 0;

    const std::string &getUltimoComando() const;

    void setUltimoComando(const std::string &ultimoComando);
};

#endif //TPPOO_APARELHO_H

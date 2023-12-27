#ifndef TPPOO_PROCESSADOR_H
#define TPPOO_PROCESSADOR_H

#include <vector>
#include "../Regras/regra.h"
#include "../Aparelhos/aparelho.h"
#include <string>

using namespace std;


class Processador {
private:
    int idProcessador;
    static int nextIdProcessador;
    char comando;
    vector<Regra *> regras;
    vector<Aparelho*> aparelhosAssociados;


public:
    Processador(char _comando);
    ~Processador();

    void adicionarRegra(Regra* novaRegra);
    void removerRegra(int idRegra);
    void listarRegras() const;
    bool verificarRegras() const;
    void executarComando();

    void mudarComando(const char& novoComando);
    void associarAparelho(Aparelho* aparelho);
    void desassociarAparelho(int idAparelho);

    int getIdProcessador() const;
    char getComando() const;

    int getRegrasNum() const;
    const vector<Regra *> &getRegras() const;
};

#endif // TPPOO_PROCESSADOR_H
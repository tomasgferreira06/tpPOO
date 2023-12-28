#ifndef TPPOO_PROCESSADOR_H
#define TPPOO_PROCESSADOR_H

#include <vector>
#include "../Regras/regra.h"
#include "../Aparelhos/aparelho.h"
#include <string>

using namespace std;


class Processador {
private:
    Zona* zona;
    int idProcessador;
    static int nextIdProcessador;
    string comando;
    vector<Regra *> regras;
    vector<Aparelho*> aparelhosAssociados;


public:
    Processador(Zona *zona,string _comando);
    ~Processador();
    void adicionarRegra(Regra* novaRegra);
    void removerRegra(int idRegra);
    void avaliarRegras();
    void listarRegras() const;
    bool verificarRegras() const;
    void executarComando();

    void mudarComando(const string& novoComando);
    void associarAparelho(Aparelho* aparelho);
    void desassociarAparelho(int idAparelho);

    int getIdProcessador() const;
    string getComando() const;

    int getRegrasNum() const;
    const vector<Regra *> &getRegras() const;
};

#endif // TPPOO_PROCESSADOR_H
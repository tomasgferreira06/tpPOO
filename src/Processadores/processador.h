#ifndef TPPOO_PROCESSADOR_H
#define TPPOO_PROCESSADOR_H

#include <vector>
#include "../Regras/regra.h"
#include "../Aparelhos/aparelho.h"
#include "../../lib/Terminal.h"
#include <string>

using namespace std;


class Processador {



private:
    int idProcessador;
    static int nextIdProcessador;
    string comando;
    vector<Regra *> regras;
    vector<Aparelho*> aparelhosAssociados;
    Zona* zona;


public:
    Processador(Zona *zona,string _comando);
    ~Processador();
    void adicionarRegra(Regra* novaRegra);
    void removerRegra(int idRegra);
    Processador(const Processador& outro);
    Processador& operator=(const Processador& outro);

    void avaliarRegras(term::Window & com_efetuadosWindow);
    void listarRegras() const;
    bool verificarRegras() const;
    void executarComando();

    void mudarComando(const string& novoComando);
    void associarAparelho(Aparelho* aparelho);
    void desassociarAparelho(int idAparelho);
    void removerTodasRegras();
    int getIdProcessador() const;
    string getComando() const;

    int getRegrasNum() const;
    const vector<Regra *> &getRegras() const;

    Zona *getZona() const;
};

#endif // TPPOO_PROCESSADOR_H
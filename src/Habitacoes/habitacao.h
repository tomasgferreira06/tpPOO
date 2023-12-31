#ifndef TPPOO_HABITACAO_H
#define TPPOO_HABITACAO_H

#include <vector>
#include <memory>
#include "../Zonas/zona.h"
#include "../../lib/Terminal.h"

class Habitacao {

private:
    std::vector<std::vector<Zona*>> grelhaZonas;
    std::vector<term::Window*> windows;
    std::map<std::string, Processador*> processadoresSalvos;
    int contadorZona;
    int instanteAtual;






public:

    Habitacao(int linhas = 2, int colunas = 2);
    ~Habitacao();
    void criarHabitacao(int linhas, int colunas);
    void listarZonas(term::Window& com_efetuadosWindow);
    bool adicionarSensor(int idZona, char tipoSensor);
    bool adicionarAparelho(int idZona, char tipoAparelho);
    bool adicionarProcessador(int idZona, string comando);
    bool removerSensor(int idZona, int idSensor);
    bool removerAparelho(int idZona, int idAparelho);
    bool removerProcessador(int idZona, int idProcessador);
    Zona* encontrarZonaPorId(int idZona);
    void listarComponentesZona(int idZona, term::Window& com_efetuadosWindow);
    bool removerZona(int idZona);
    bool criarZona(int linha, int coluna);
    void removerHabitacao();
   void avancarInstante(term::Window & com_efetuadosWindow);
    int getInstanteAtual() const;
    bool nomeJaExiste(const std::string& nome) const;
    void listarProcessadoresGuardados(term::Window& com_efetuadosWindow) const;
    void guardarProcessador(const std::string& nome, Processador* processador);
    bool processadorGuardadoExiste(const std::string& nome) const;
    Processador* getProcessadorGuardado(const std::string& nome) const;
    Processador recuperarProcessador(const std::string& id) const;
    void removerProcessadorGuardado(const std::string& nome);
    bool zonaExiste(int idZona) const;


};

#endif //TPPOO_HABITACAO_H


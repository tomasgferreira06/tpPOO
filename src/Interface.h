

#ifndef TPPOO_INTERFACE_H
#define TPPOO_INTERFACE_H
#include "../lib/Terminal.h"


#include <string>

class Interface {
public:
    Interface();
   // ~Interface();
    void iniciar(); // Inicia o loop de interação com o usuário
private:
    term::Window mainWindow;
    void processarComando(const std::string& comando);
    void avancarTempo(int n);
    void criarHabitacao(int linhas, int colunas);
    void removerHabitacao();
    void criarZona(int linha, int coluna);
    void removerZona(int idZona);
    void listarZonas();
    void listarComponentes(int idZona);
    void listarPropriedades(int idZona);
    void modificarPropriedade(int idZona, const std::string& nome, double valor);
    void adicionarComponente(int idZona, char tipo, const std::string& especificacao);
    void removerComponente(int idZona, char tipo, int idComponente);
    void executarArquivoComandos(const std::string& nomeArquivo);

};


#endif //TPPOO_INTERFACE_H

#ifndef TPPOO_PROPRIEDADE_H
#define TPPOO_PROPRIEDADE_H

#include<string>
#include<limits>

using namespace std;

class Propriedade{

private:
    string nome;
    string unidade;
    int min;
    int max;
    int valor;


public:
    Propriedade(string nome, string unidade, int min, int max = std::numeric_limits<int>::max());

    const string &getNome() const;

    const string &getUnidade() const;

    int getMin() const;

    int getMax() const;

    int getValor() const;

    void setValor(int valor);


};

#endif //TPPOO_PROPRIEDADE_H


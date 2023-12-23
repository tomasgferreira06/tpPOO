#ifndef TPPOO_PROPRIEDADE_H
#define TPPOO_PROPRIEDADE_H



class Propriedade {
public:

   virtual ~Propriedade();
   virtual double getValor() const = 0;
   virtual void setValor(double valor) = 0;
   virtual bool isValorValido(double valor) const = 0;

};

#endif //TPPOO_PROPRIEDADE_H


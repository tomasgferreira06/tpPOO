//
// Created by User on 28/12/2023.
//

#include <sstream>
#include "aspersor.h"
#include "aparelho.h"
#include "../Propriedades/propriedade.h"

Aspersor::Aspersor(Zona *pZona) : Aparelho(pZona) , contador(0){}

void Aspersor::liga(term::Window & com_efetuadosWindow) {
    if(!estaLigado()){
        setLigado(true);
        com_efetuadosWindow << "O aspersor "<< getIdAparelho() <<" foi ligado." << term::move_to(0,  com_efetuadosWindow.get_current_row() + 1);
    }
}

void Aspersor::desliga(term::Window & com_efetuadosWindow) {
    if(estaLigado()){
        setLigado(false);
        com_efetuadosWindow << "O aspersor "<< getIdAparelho() <<" foi desligado." << term::move_to(0,  com_efetuadosWindow.get_current_row() + 1);
    }
}


void Aspersor::executar(term::Window & com_efetuadosWindow) {
    Zona* zona = getZonaAssociada();
    if (zona) {
        const std::vector<Sensor*>& sensores = zona->getSensores();
        double humidadeAtual = 0.0;
        double vibracaoAtual = 0.0;
        bool encontrouSensorHumidade = false;
        bool encontrouSensorVibracao = false;

        // Procurar pelos sensores de umidade e vibração
        for (Sensor* sensor : sensores) {
            if (sensor->getTipoSensor() == "Humidade") {
                humidadeAtual = sensor->getValor();
                encontrouSensorHumidade = true;
            } else if (sensor->getTipoSensor() == "Vibracao") {
                vibracaoAtual = sensor->getValor();
                encontrouSensorVibracao = true;
            }
        }

        // Se o aspersor está ligado ou enquanto se está a desligar (contador)
        com_efetuadosWindow << term::set_color(12)<< "O aspersor da zona "<< zona->getId() << " com o id: "<< getIdAparelho() <<" esta ligado." << term::set_color(0) << term::move_to(0,  com_efetuadosWindow.get_current_row() + 1);

        if (estaLigado() || getContador() <= 5) {
            if (getContador() == 0 && encontrouSensorHumidade) {
                // Adiciona humidade no primeiro instante de ligado
                Propriedade* propHumidade = zona->getPropriedade("Humidade");
                if (propHumidade && humidadeAtual < 75) {
                    propHumidade->setValor(std::min(75.0, humidadeAtual + 50));
                }
            }

            if (getContador() == 0 && encontrouSensorVibracao) {
                // Adiciona vibração no primeiro instante de ligado
                Propriedade* propVibracao = zona->getPropriedade("Vibracao");
                if (propVibracao) {
                    propVibracao->setValor(vibracaoAtual + 100);
                }
            }

            if (getContador() == 1) {
                // No segundo instante, coloca o fumo a 0
                Propriedade* propFumo = zona->getPropriedade("Fumo");
                if (propFumo) {
                    propFumo->setValor(0);
                }
            }

            setContador(getContador() + 1);
        } else {

            com_efetuadosWindow << term::set_color(12)<< "O aspersor da zona "<< zona->getId() << " com o id: "<< getIdAparelho() <<" esta desligado." << term::set_color(0) << term::move_to(0,  com_efetuadosWindow.get_current_row() + 1);

            if (getContador() > 5) {
                setContador(0);
            }
        }

        // Se o aspersor foi desligado e o contador foi reiniciado, remover a vibração
        if (!estaLigado() && getContador() == 0 && encontrouSensorVibracao) {
            Propriedade* propVibracao = zona->getPropriedade("Vibracao");
            if (propVibracao && vibracaoAtual >= 100) {
                propVibracao->setValor(vibracaoAtual - 100);
            }
        }
    }
}


std::string Aspersor::getNome() const{
    std::ostringstream ss;
    ss << "Aspersor" << getUltimoComando();
    return ss.str();
}

int Aspersor::getContador() const {
    return contador;
}

void Aspersor::setContador(int contador) {
    Aspersor::contador = contador;
}

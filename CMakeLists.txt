cmake_minimum_required(VERSION 3.23)
project(tpPOO)

set(CMAKE_CXX_STANDARD 20)

add_executable(tpPOO src/main.cpp
        src/Interface.cpp
        src/Interface.h
        src/Aparelhos/aparelho.h
        src/Aparelhos/aparelho.cpp
        src/Aparelhos/aquecedor.h
        src/Aparelhos/aquecedor.cpp
        src/Habitacoes/habitacao.h
        src/Habitacoes/habitacao.cpp
        src/Processadores/processador.h
        src/Processadores/processador.cpp
        src/Propriedades/propriedade.h
        src/Propriedades/propriedade.cpp
        src/Propriedades/temperatura.h
        src/Propriedades/temperatura.cpp
        src/Propriedades/luz.h
        src/Propriedades/luz.cpp
        src/Propriedades/Radiacao.h
        src/Propriedades/Radiacao.cpp
        src/Propriedades/Vibracao.h
        src/Propriedades/Vibracao.cpp
        src/Propriedades/Humidade.h
        src/Propriedades/Humidade.cpp
        src/Propriedades/Fumo.h
        src/Propriedades/Fumo.cpp
        src/Propriedades/som.h
        src/Propriedades/som.cpp
        src/Sensores/sensor.h
        src/Sensores/sensor.cpp
        src/Sensores/sensorTemperatura.h
        src/Sensores/sensorTemperatura.cpp
        src/Sensores/sensorMovimento.h
        src/Sensores/sensorMovimento.cpp
        src/Sensores/sensorLuminosidade.h
        src/Sensores/sensorLuminosidade.cpp
        src/Sensores/sensorRadiacao.h
        src/Sensores/sensorRadiacao.cpp
        src/Sensores/sensorHumidade.h
        src/Sensores/sensorHumidade.cpp
        src/Sensores/sensorSom.h
        src/Sensores/sensorSom.cpp
        src/Sensores/sensorFumo.h
        src/Sensores/sensorFumo.cpp
        src/Zonas/zona.h
        src/Zonas/zona.cpp
        src/Regras/regra.cpp
        src/Regras/regra.h
        src/Regras/IgualA.cpp
        src/Regras/IgualA.h
        src/Regras/MenorQue.h
        src/Regras/MenorQue.cpp
        src/Regras/MaiorQue.h
        src/Regras/MaiorQue.cpp
        src/Regras/Entre.h
        src/Regras/Entre.cpp
        src/Regras/Fora.h
        src/Regras/Fora.cpp
        lib/Terminal.cpp
        lib/Terminal.h
        )
target_link_libraries(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/lib/pdcurses.a)

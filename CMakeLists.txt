cmake_minimum_required(VERSION 3.23)
project(tpPOO)

set(CMAKE_CXX_STANDARD 20)

add_executable(tpPOO src/main.cpp
        src/Interface.cpp
        src/Interface.h
        src/Aparelhos/aparelho.h
        src/Aparelhos/aparelho.cpp
        src/Habitacoes/habitacao.h
        src/Habitacoes/habitacao.cpp
        src/Processadores/processador.h
        src/Processadores/processador.cpp
        src/Propriedades/propriedade.h
        src/Propriedades/propriedade.cpp
        src/Sensores/sensor.h
        src/Sensores/sensor.cpp
        src/Zonas/zona.h
        src/Zonas/zona.cpp
        src/Regras/regra.cpp
        src/Regras/regra.h
        lib/Terminal.cpp
        lib/Terminal.h
        )
target_link_libraries(${PROJECT_NAME} PUBLIC
        ${PROJECT_SOURCE_DIR}/lib/pdcurses.a)

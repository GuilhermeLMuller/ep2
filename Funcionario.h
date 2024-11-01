#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include "Usuario.h"
#include "Registro.h"
#include <string>
#include <vector>

class Funcionario : public Usuario
{
private:
    std::vector<Registro *> *registros;
    bool entrar_e_sair(Data *d, bool isEntrada, bool isManual);

public:
    Funcionario(int id, std::string nome);
    Funcionario(int id, std::string nome, std::vector<Registro *> *registros);
    virtual ~Funcionario();

    bool entrar(Data *d);
    bool sair(Data *d);
    bool registrarEntradaManual(Data *d);
    bool registrarSaidaManual(Data *d);

    int getHorasTrabalhadas(int mes, int ano);
    std::vector<Registro *> *getRegistros();
};

#endif
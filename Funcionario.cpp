#include "Funcionario.h"
#include "Entrada.h"
#include "Saida.h"
#include <string>
#include <vector>
#include <iostream>

Funcionario::Funcionario(int id, std::string nome) : Usuario(id, nome)
{
}

Funcionario::Funcionario(int id, std::string nome, std::vector<Registro *> *registros) : Usuario(id, nome)
{
    this->registros = registros;
}

Funcionario::~Funcionario()
{
    for (int i = 0; i < registros->size(); i++)
    {
        delete (*registros)[i];
    }
    delete registros;
}

bool Funcionario::entrar_e_sair(Data *d, bool isEntrada, bool isManual)
{
    // note que se o dynamic cast der certo, o ultimo é uma entrada (true), entao agora nao pode ser entrada (true). a reciproca vale
    if (registros->size() > 0 && (bool)dynamic_cast<Entrada *>((*registros)[registros->size() - 1]) == isEntrada)
    {
        return false;
    }

    Registro *registro = nullptr;
    if (isManual)
    {
        if (isEntrada)
        {
            registro = new Entrada(d, true);
        }
        else
        {
            registro = new Saida(d, true);
        }
    }
    else
    {
        if (isEntrada)
        {
            registro = new Entrada(d);
        }
        else
        {
            registro = new Saida(d);
        }
    }

    // se vazio
    if (registros->size() == 0)
    {
        (*registros)[0] = registro;
        return true;
    }

    if ((*registros)[registros->size() - 1]->getData()->diferenca(d) > 0) // checa se o novo registro vem depois do anterior (tempo)
    {
        delete registro;
        return false;
    }

    registros->push_back(registro);
    return true;
}

bool Funcionario::entrar(Data *d)
{
    return entrar_e_sair(d, true, false);
}

bool Funcionario::sair(Data *d)
{
    return entrar_e_sair(d, false, false);
}

bool Funcionario::registrarEntradaManual(Data *d)
{
    return entrar_e_sair(d, true, true);
}

bool Funcionario::registrarSaidaManual(Data *d)
{
    return entrar_e_sair(d, false, true);
}

int Funcionario::getHorasTrabalhadas(int mes, int ano)
{
    double soma = 0;

    for (int i = 0; i < registros->size(); i++)
    {
        Data *data = (*registros)[i]->getData();
        int mes_registros = data->getMes();
        int ano_registros = data->getAno();

        if (mes_registros == mes && ano_registros == ano && i + 1 < registros->size() && dynamic_cast<Entrada *>((*registros)[registros->size() - 1]))
        {
            Data *entrada = (*registros)[i]->getData();
            Data *saida = (*registros)[i + 1]->getData();
            soma -= entrada->diferenca(saida); // porque decidiram que diferenca(d) < 0 para atual > d?
        }
    }
    soma /= 3600; // segundos -> horas
    return (int)soma;
}

std::vector<Registro *> *Funcionario::getRegistros()
{
    return registros;
}
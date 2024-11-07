#include "Visitante.h"
#include "Entrada.h"
#include "Saida.h"
#include <string>
#include <stdexcept>

Visitante::Visitante(int id, std::string nome, Data *inicio, Data *fim) : Usuario(id, nome)
{
    this->inicio = inicio;
    this->fim = fim;

    if (inicio == nullptr || fim == nullptr || fim->diferenca(inicio) > 0)
    {
        throw new std::logic_error("Erro aqui");
    }
}

Visitante::~Visitante()
{
    delete inicio;
    delete fim;
}

bool Visitante::entrar(Data *d)
{
    if (d->getHora() < inicio->getHora() || d->getHora() > fim->getHora() || (d->getHora() == fim->getHora() && d->getMinuto() > fim->getMinuto()))
    {
        return false;
    }
    return true;
}

bool Visitante::sair(Data *d)
{
    if (d->getHora() < inicio->getHora() || d->getHora() > fim->getHora() || (d->getHora() == fim->getHora() && d->getMinuto() > fim->getMinuto()))
    {
        return false;
    }
    return true;
}

bool Visitante::registrarEntradaManual(Data *d)
{
    return false;
}

bool Visitante::registrarSaidaManual(Data *d)
{
    return false;
}

Data *Visitante::getDataInicio()
{
    return inicio;
}

Data *Visitante::getDataFim()
{
    return fim;
}
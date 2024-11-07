#include "Aluno.h"
#include <string>
#include <stdexcept>

Aluno::Aluno(int id, std::string nome) : Usuario(id, nome)
{
}

Aluno::~Aluno()
{
}

void Aluno::setHorarioFim(int hora, int minuto)
{
    if (hora <= 6 || hora > 23 || minuto < 0 || minuto > 59)
    {
        throw new std::logic_error("Erro aqui");
    }

    hora_fim = hora;
    minuto_fim = minuto;
}

bool Aluno::entrar(Data *d)
{
    if (d->getHora() < HORARIO_INICIO || d->getHora() > hora_fim || (d->getHora() == hora_fim && d->getMinuto() > minuto_fim))
    {
        return false;
    }
    return true;
}

bool Aluno::sair(Data *d)
{
    if (d->getHora() < HORARIO_INICIO || d->getHora() > hora_fim || (d->getHora() == hora_fim && d->getMinuto() > minuto_fim))
    {
        return false;
    }
    return true;
}

bool Aluno::registrarEntradaManual(Data *d)
{
    return false;
}

bool Aluno::registrarSaidaManual(Data *d)
{
    return true;
}

int Aluno::getHoraFim()
{
    return hora_fim;
}

int Aluno::getMinutoFim()
{
    return minuto_fim;
}

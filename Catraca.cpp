#include "Catraca.h"
#include <iostream>

Catraca::Catraca(GerenciadorDeUsuario *g)
{
    this->g = g;
}

Catraca::~Catraca()
{
}

bool Catraca::entrar(int id, Data *d)
{
    Usuario *usuario = g->getUsuario(id);
    if (usuario == nullptr)
    {
        return false;
    }
    return usuario->entrar(d);
}

bool Catraca::sair(int id, Data *d)
{
    Usuario *usuario = g->getUsuario(id);
    if (usuario == nullptr)
    {
        return false;
    }
    return usuario->sair(d);
}
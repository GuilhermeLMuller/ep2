#include "GerenciadorDeUsuario.h"

using namespace std;

GerenciadorDeUsuario::GerenciadorDeUsuario(int maximoUsuarios)
{
    this->maximoUsuarios = maximoUsuarios;
    usuarios = new Usuario *[maximoUsuarios];
}

GerenciadorDeUsuario::~GerenciadorDeUsuario()
{
    for (int i = 0; i < quantidade; i++)
    {
        delete usuarios[i];
    }
    delete[] usuarios;
}

bool GerenciadorDeUsuario::adicionar(Usuario *u)
{
    if (quantidade >= maximoUsuarios)
    {
        return false;
    }
    for (int i = 0; i < quantidade; i++)
    {
        if (usuarios[i]->getId() == u->getId())
        {
            return false;
        }
    }

    usuarios[quantidade] = u;
    quantidade++;

    return true;
}

Usuario *GerenciadorDeUsuario::getUsuario(int id)
{
    for (int i = 0; i < quantidade; i++)
    {
        if (usuarios[i]->getId() == id)
        {
            return usuarios[i];
        }
    }
    return nullptr;
}

Usuario **GerenciadorDeUsuario::getUsuarios()
{
    return usuarios;
}

int GerenciadorDeUsuario::getQuantidade()
{
    return quantidade;
}
#include "GerenciadorDeUsuario.h"
#include <stdexcept>

using namespace std;

GerenciadorDeUsuario::GerenciadorDeUsuario()
{
    this->usuarios = new vector<Usuario*>();
}

GerenciadorDeUsuario::GerenciadorDeUsuario(vector<Usuario*>* usuarios)
{
    this->usuarios = usuarios;
}

GerenciadorDeUsuario::~GerenciadorDeUsuario()
{
    for (int i = 0; i < usuarios->size(); i++)
    {
        delete usuarios->at(i);
    }
    delete[] usuarios;
}

void GerenciadorDeUsuario::adicionar(Usuario *u)
{
    for (int i = 0; i < usuarios->size(); i++) {
        if (usuarios->at(i)->getId() == u->getId()) throw new invalid_argument("id ja existe");
    }
    usuarios->push_back(u);
}

Usuario *GerenciadorDeUsuario::getUsuario(int id)
{
    for (int i = 0; i < usuarios->size(); i++)
    {
        if (usuarios->at(i)->getId() == id)
        {
            return usuarios->at(i);
        }
    }
    return nullptr;
}

vector<Usuario*>* GerenciadorDeUsuario::getUsuarios()
{
    return this->usuarios;
}
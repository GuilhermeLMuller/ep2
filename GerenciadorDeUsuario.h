#ifndef GERENCIADORDEUSUARIO_H
#define GERENCIADORDEUSUARIO_H
#include <vector>
#include "Usuario.h"
using namespace std;

class GerenciadorDeUsuario
{
private:
    vector<Usuario*>* usuarios;

public:
    GerenciadorDeUsuario();
    GerenciadorDeUsuario(vector<Usuario*>* usuarios);
    virtual ~GerenciadorDeUsuario();

    void adicionar(Usuario *u);
    Usuario *getUsuario(int id);
    vector<Usuario*>* getUsuarios();
};

#endif
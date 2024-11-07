#ifndef GERENCIADORDEUSUARIO_H
#define GERENCIADORDEUSUARIO_H
#include "Usuario.h"

class GerenciadorDeUsuario
{
private:
    int maximoUsuarios = 100;
    Usuario **usuarios;
    int quantidade = 0;

public:
    GerenciadorDeUsuario(int maximo);
    ~GerenciadorDeUsuario();

    bool adicionar(Usuario *u);
    Usuario *getUsuario(int id);
    Usuario **getUsuarios();
    int getQuantidade();
};

#endif
#include <ctime>
#include <iostream>
#include <string>
#include "Usuario.h"

using namespace std;

Usuario::Usuario(int id, string nome)
{
    this->id = id;
    this->nome = nome;
}

Usuario::~Usuario()
{
}

string Usuario::getNome()
{
    return nome;
}

int Usuario::getId()
{
    return id;
}

//linhas de codigo apagadas por guilherme:
//bool Usuario::entrar(Data* d){}
//bool Usuario::sair(Data* d){}
//bool Usuario::registrarEntradaManual(Data* d) {}
//bool Usuario::registrarSaidaManual(Data* d) {}
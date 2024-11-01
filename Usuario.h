#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "Data.h"
#include "Registro.h"

class Usuario 
{
    protected:
        int id = 0;
        std::string nome;

    public:
        Usuario(int id, std::string nome);
        virtual ~Usuario() = 0;

        std::string getNome();
        int getId();
        
        virtual bool entrar(Data *d) = 0;
        virtual bool sair(Data *d) = 0;
        virtual bool registrarEntradaManual(Data *d) = 0;
        virtual bool registrarSaidaManual(Data* d) = 0;
};

#endif
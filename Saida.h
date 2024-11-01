#ifndef SAIDA_H
#define SAIDA_H

#include "Data.h"
#include "Registro.h"

class Saida : public Registro
{
public:
    Saida(Data *d);
    Saida(Data *d, bool manual);
    virtual ~Saida();
};

#endif
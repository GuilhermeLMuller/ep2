#include <iostream>
#include "Registro.h"
#include "Data.h"

using namespace std;

Registro::Registro(Data *d)
{
    this->d = d;
    manual = false;

    if (d == nullptr)
    {
        throw new invalid_argument("Data errada");
    }
}

Registro::Registro(Data *d, bool manual)
{
    this->d = d;
    this->manual = manual;

    if (d == nullptr)
    {
        throw new invalid_argument("Data errada");
    }
}

Registro::~Registro()
{
}

Data *Registro::getData()
{
    return d;
}

bool Registro::isManual()
{
    return manual;
}
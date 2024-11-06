#ifndef PERSISTENCIADEUSUARIO_H
#define PERSISTENCIADEUSUARIO_H
#include <vector>
#include "Usuario.h"

using namespace std;

class PersistenciaDeUsuario
{
private:


public:
    void escreverData(Data *d, ofstream &arquivo);
    PersistenciaDeUsuario();
    virtual ~PersistenciaDeUsuario();
    Data *lerData(ifstream &input);

    vector<Usuario *> *carregar(string arquivo);
    void salvar(string arquivo, vector<Usuario *> *v);
};

#endif
#ifndef PERSISTENCIADEUSUARIO_H
#define PERSISTENCIADEUSUARIO_H
#include <vector>
#include "Usuario.h"

using namespace std;

class PersistenciaDeUsuario 
{
private:
    void escreverData(Data* d, ofstream& arquivo);

public:
    PersistenciaDeUsuario();
    virtual ~PersistenciaDeUsuario();

    vector<Usuario*>* carregar(string arquivo);
    void salvar(string arquivo, vector<Usuario*>* v);
};

#endif
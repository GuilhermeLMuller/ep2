#include <iostream>
#include <fstream>

#include "Catraca.h"
#include "Data.h"
#include "GerenciadorDeUsuario.h"
#include "Registro.h"
#include "Usuario.h"
#include "PersistenciaDeUsuario.h"
#include "Aluno.h"
#include "Visitante.h"
#include "Funcionario.h"
#include "Entrada.h"
#include "Saida.h"


using namespace std;

void testando(){
    vector<Registro*>* registros = new vector<Registro*>();
    Data* teste = new Data(9, 4, 30, 30, 9, 2024);
    Funcionario* guilherme = new Funcionario(123, "guilherme", registros);
    guilherme->registrarEntradaManual(teste);
    cout << guilherme->getRegistros()->size();

}
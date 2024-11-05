#include "PersistenciaDeUsuario.h"
#include <fstream>
#include "Funcionario.h"
#include "Visitante.h"
#include "Aluno.h"
#include "Entrada.h"
#include "Saida.h"

PersistenciaDeUsuario::PersistenciaDeUsuario() {}

PersistenciaDeUsuario::~PersistenciaDeUsuario() {}

void PersistenciaDeUsuario::escreverData(Data* d, ofstream& arquivo) {
    arquivo <<d->getHora() << " " << d->getMinuto() << " " << d->getSegundo() << " " << d->getDia() << " " << d->getMes() << d->getAno();
}

vector<Usuario *> *PersistenciaDeUsuario::carregar(string arquivo)
{
    // abrir o arquivo e inicializar as variaveis necessarias
    ifstream input;
    input.open(arquivo);

    // se o arquivo nao existir:
    if (input.fail()) {
        throw new logic_error("arquivo nao encontrado");
    }

    vector<Usuario *> *carregados = new vector<Usuario *>();
    char tipo, EntradaSaida, manual;
    int identificador, quantidadeDeRegistros, i = 0, hour, minute, second, day, month, year;
    string nome;
    Usuario *pessoa;
    Data *date, *dateInicio, *dateFim;

    // laco para ler os usuarios
    while (input)
    {
        input >> tipo;
        // se o usuario for do tipo funcionario:
        if (tipo == 'F')
        {
            input >> identificador;
            input >> nome;
            input >> quantidadeDeRegistros;
            pessoa = new Funcionario(identificador, nome);
            carregados->push_back(pessoa);
            // registrar as entradas e saidas do funcionario:
            for (int j = 0; j < quantidadeDeRegistros; j++)
            {
                input >> EntradaSaida;
                input >> hour;
                input >> minute;
                input >> second;
                input >> day;
                input >> month;
                input >> year;
                input >> manual;
                date = new Data(hour, minute, second, day, month, year);
                if (EntradaSaida == 'E')
                {
                    if (manual == 0) pessoa->entrar(date);
                    if (manual == 1) pessoa->registrarEntradaManual(date);
                }
                if (EntradaSaida == 'S')
                {
                    if (manual == 0) pessoa->sair(date);
                    if (manual == 1) pessoa->registrarSaidaManual(date);
                }
            }
        }

        //Se o usuario for um aluno:
        if (tipo == 'A') {
            input >> identificador;
            input >> nome;
            pessoa = new Aluno(identificador, nome);
            carregados->push_back(pessoa);
        }

        //Se o usuario for um visitante:
        if (tipo == 'V') {
            input >> identificador;
            input >> nome;
            input >> hour;
            input >> minute;
            input >> second;
            input >> day;
            input >> month;
            input >> year;
            dateInicio = new Data(hour, minute, second, day, month, year);
            input >> hour;
            input >> minute;
            input >> second;
            input >> day;
            input >> month;
            input >> year;
            dateInicio = new Data(hour, minute, second, day, month, year);
            pessoa = new Visitante(identificador, nome, dateInicio, dateFim);
            carregados->push_back(pessoa);
        }
    }

    //se nao tiver chegado no final do arquivo ou houver algum erro de leitura
    if (input.fail() || !input.eof()) {
        throw new logic_error("erro na leitura");
    }
    input.close();

    return carregados;
}

void PersistenciaDeUsuario::salvar(string arquivo, vector<Usuario*>* v){
    ofstream output;
    output.open(arquivo);
    for (int j = 0; j < v->size(); j++){
        if(dynamic_cast<Aluno*>(v->at(j))) {
            output << "A" << " " << v->at(j)->getId() << " " << v->at(j)->getNome() << "\n";
        }

        if(dynamic_cast<Funcionario*>(v->at(j))) {
            Funcionario* func = dynamic_cast<Funcionario*>(v->at(j));
            output << "F" << " " << func->getId() << func->getNome() << "\n";
            output << func->getRegistros()->size() << "\n";
            vector<Registro*>* listaRegistros = func->getRegistros(); 

            for (int k = 0; k < func->getRegistros()->size(); k++) {
                Data* data1 = func->getRegistros()->at(k)->getData();
                if (dynamic_cast<Entrada*>(listaRegistros->at(k))) {
                    output << "E" << " ";
                    this->escreverData(data1, output);
                    output << " ";
                    if (listaRegistros->at(k)->isManual()) output << 1;
                    else output << 0;
                }
                if (dynamic_cast<Saida*>(listaRegistros->at(k))) {
                    output << "S" << " ";
                    this->escreverData(data1, output);
                    output << " ";
                    if (listaRegistros->at(k)->isManual()) output << 1;
                    else output << 0;                    
                }
                output << "\n";
            }
        }

        if (dynamic_cast<Visitante*>(v->at(j))){
            Visitante* visit = dynamic_cast<Visitante*>(v->at(j));
            output << "V" << " " << visit->getId() << " " << visit->getNome() << " ";
            this->escreverData(visit->getDataInicio(), output);
            output << " ";
            this->escreverData(visit->getDataFim(), output);
            output << "\n";
        }
    }
    output.close();
}
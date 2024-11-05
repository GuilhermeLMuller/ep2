#include <iostream>
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

// entrada e saida de usuarios (opcoes 1, 2 e 3)
bool entrarSair(int opcao, int id, int catraca, Data *tempo, Catraca *zero, Catraca *um)
{
    bool resultado = false;
    if (opcao == 1)
    {
        if (catraca == 0)
        {
            resultado = zero->entrar(id, tempo);
        }
        if (catraca == 1)
        {
            resultado = um->entrar(id, tempo);
        }
    }
    if (opcao == 2)
    {
        if (catraca == 0)
        {
            resultado = zero->sair(id, tempo);
        }
        if (catraca == 1)
        {
            resultado = um->sair(id, tempo);
        }
    }
    return resultado;
}

void menu()
{
    PersistenciaDeUsuario *persistencia = new PersistenciaDeUsuario();
    GerenciadorDeUsuario *gerenciador;
    Catraca *zero = new Catraca(gerenciador);
    Catraca *um = new Catraca(gerenciador);
    int opcao = -1, id, hora, minuto, segundo, dia, mes, ano, catraca, horaFim, minutoFim;
    char opcaoInicio, opcaoFim;

    cout << "Deseja carregar usuarios (s/n): ";
    cin >> opcaoInicio;

    if (opcaoInicio == 's')
    {
        string txt;
        cout << "Arquivo: ";
        cin >> txt;
        gerenciador = new GerenciadorDeUsuario(persistencia->carregar(txt));
    }
    else
        gerenciador = new GerenciadorDeUsuario();

    while (opcao != 0)
    {
        cout << "Acesso ao predio" << endl;
        cout << "1) Entrada" << endl;
        cout << "2) Saida" << endl;
        cout << "3) Registro manual" << endl;
        cout << "4) Cadastro de usuario" << endl;
        cout << "5) Relatorio" << endl;
        cout << "6) Configuracao" << endl;
        cout << "0) Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        if (opcao != 0)
            cout << endl; // pular linha bonitinho :)

        if (opcao == 1 || opcao == 2)
        {
            cout << "Catraca: ";
            cin >> catraca;
            cout << "Id: ";
            cin >> id;
            cout << "Hora: ";
            cin >> hora;
            cout << "Minuto: ";
            cin >> minuto;
            cout << "Segundo: ";
            cin >> segundo;
            cout << "Dia: ";
            cin >> dia;
            cout << "Mes: ";
            cin >> mes;
            cout << "Ano: ";
            cin >> ano;

            Data *tempo = new Data(hora, minuto, segundo, dia, mes, ano);

            if (opcao == 1)
            {
                if (entrarSair(1, id, catraca, tempo, zero, um))
                {
                    cout << "[ENTRADA] Catraca " << catraca << " abriu: id " << id << endl
                         << endl;
                }
                else
                {
                    cout << "[ENTRADA] catraca " << catraca << " travada" << endl
                         << endl;
                }
            }
            else if (opcao == 2)
            {
                if (entrarSair(2, id, catraca, tempo, zero, um))
                {
                    cout << "[SAIDA] Catraca " << catraca << " abriu: id " << id << endl
                         << endl;
                }
                else
                {
                    cout << "[SAIDA] catraca " << catraca << " travada" << endl
                         << endl;
                }
            }
        }

        if (opcao == 3)
        {

            char escolha = 'e';
            cout << "Entrada (e) ou Saida (s)? ";
            cin >> escolha;
            cout << "Id: ";
            cin >> id;
            cout << "Hora: ";
            cin >> hora;
            cout << "Minuto: ";
            cin >> minuto;
            cout << "Segundo: ";
            cin >> segundo;
            cout << "Dia: ";
            cin >> dia;
            cout << "Mes: ";
            cin >> mes;
            cout << "Ano: ";
            cin >> ano;

            Data *tempo = new Data(hora, minuto, segundo, dia, mes, ano);
            Usuario *individuo = gerenciador->getUsuario(id);
            if (escolha == 'e')
            {
                if (individuo->registrarEntradaManual(tempo))
                    cout << "Entrada manual registrada: id " << id << endl
                         << endl;
                else
                    cout << "Erro ao registrar entrada manual" << endl
                         << endl;
            }
            else if (escolha == 's')
            {
                if (individuo->registrarSaidaManual(tempo))
                    cout << "Saida manual registrada: id " << id << endl
                         << endl;
                else
                    cout << "Erro ao registrar saida manual" << endl
                         << endl;
            }
        }

        if (opcao == 4)
        {
            int id;
            string nome;
            char tipo;
            cout << "Tipo (v, a ou f): ";
            cin >> tipo;

            if (tipo == 'a' || tipo == 'f')
            {
                cout << "Id: ";
                cin >> id;

                cout << "Nome: ";
                cin >> nome;
                Usuario *pessoa;

                if (tipo == 'a')
                    Aluno *pessoa = new Aluno(id, nome);
                else
                    Funcionario *pessoa = new Funcionario(id, nome);
                gerenciador->adicionar(pessoa);
                cout << "Usuario cadastrado com sucesso" << endl
                     << endl;
            }
        }
        if (opcao == 5)
        {
            int mes, ano;
            cout << "Mes ";
            cin >> mes;
            cout << "Ano: ";
            cin >> ano;

            cout << "Relatorio de horas trabalhadas" << endl;

            for (int i = 0; i < gerenciador->getUsuarios()->size(); i++)
            {
                if (dynamic_cast<Funcionario *>(gerenciador->getUsuarios()->at(i)))
                {
                    Funcionario *trabalhador = dynamic_cast<Funcionario *>(gerenciador->getUsuarios()->at(i));
                    cout << trabalhador->getNome() << ": " << trabalhador->getHorasTrabalhadas(mes, ano) << endl;
                }
            }
            cout << endl;
        }

        if (opcao == 6)
        {
            cout << "Horario de fim da janela dos Alunos" << endl
                 << "Hora: ";
            cin >> horaFim;
            cout << "Minuto: ";
            cin >> minutoFim;
            for (int i = 0; i < gerenciador->getUsuarios()->size(); i++)
            {
                if (dynamic_cast<Aluno *>(gerenciador->getUsuarios()->at(i)))
                {
                    Aluno *estudante = dynamic_cast<Aluno *>(gerenciador->getUsuarios()->at(i));
                    estudante->setHorarioFim(horaFim, minutoFim);
                }
            }
        }
    }

    cout << "Deseja salvar usuarios (s/n): ";
    cin >> opcaoFim;

    if (opcaoFim == 's')
    {
        string arquivoFim;
        cout << "Arquivo: ";
        cin >> arquivoFim;
        persistencia->salvar(arquivoFim, gerenciador->getUsuarios());
    }
}
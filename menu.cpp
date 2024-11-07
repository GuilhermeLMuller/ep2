#include <iostream>
#include "Catraca.h"
#include "Data.h"
#include "GerenciadorDeUsuario.h"
#include "Registro.h"
#include "Usuario.h"

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

// funcao para entrada ou saida de usuarios (opcoes 1 e 2)
void menu()
{
    GerenciadorDeUsuario *gerenciador = new GerenciadorDeUsuario(10);
    Catraca *zero = new Catraca(gerenciador);
    Catraca *um = new Catraca(gerenciador);
    int opcao = -1;
    int id, hora, minuto, segundo, dia, mes, ano, catraca;

    while (opcao != 0)
    {
        cout << "Acesso ao predio" << endl;
        cout << "1) Entrada" << endl;
        cout << "2) Saida" << endl;
        cout << "3) Registro manual" << endl;
        cout << "4) Cadastro de usuario" << endl;
        cout << "5) Relatorio" << endl;
        cout << "0) Sair" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;
        if(opcao != 0) cout << endl; // pular linha bonitinho :)

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
                    cout << "[ENTRADA] Catraca " << catraca << " abriu: id " << id << endl << endl;
                }
                else
                {
                    cout << "[ENTRADA] catraca " << catraca << " travada" << endl << endl;
                }
            }
            else if (opcao == 2)
            {
                if (entrarSair(2, id, catraca, tempo, zero, um))
                {
                    cout << "[SAIDA] Catraca " << catraca << " abriu: id " << id << endl << endl;
                }
                else
                {
                    cout << "[SAIDA] catraca " << catraca << " travada" << endl << endl;
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
            Usuario *visitante = gerenciador->getUsuario(id);
            if (escolha == 'e')
            {
                if (visitante->registrarEntradaManual(tempo))
                    cout << "Entrada manual registrada: id " << id << endl << endl;
                else
                    cout << "Erro ao registrar entrada manual" << endl << endl;
            }
            else if (escolha == 's')
            {
                if (visitante->registrarSaidaManual(tempo))
                    cout << "Saida manual registrada: id " << id << endl << endl;
                else
                    cout << "Erro ao registrar saida manual" << endl << endl;
            }
        }

        if (opcao == 4)
        {
            int id;
            string nome;
            cout << "Id: ";
            cin >> id;

            cout << "Nome: ";
            cin >> nome;

            Usuario *pessoa = new Usuario(id, nome, 10);
            if (gerenciador->adicionar(pessoa))
            {
                cout << "Usuario cadastrado com sucesso" << endl << endl;
            }
            else
            {
                cout << "Erro ao cadastrar o usuario" << endl << endl;
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

            for (int i = 0; i < gerenciador->getQuantidade(); i++)
            {
                cout << gerenciador->getUsuarios()[i]->getNome() << ": " << gerenciador->getUsuarios()[i]->getHorasTrabalhadas(mes, ano) << endl;
            }
            cout << endl;
        }
    }
}
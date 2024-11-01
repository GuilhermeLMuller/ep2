#include <string>
#include <vector>
#include "Usuario.h"

class Aluno : public Usuario
{
private:
    static int hora_fim;
    static int minuto_fim;

public:
    static const int HORARIO_INICIO = 6;

    Aluno(int id, std::string nome);
    virtual ~Aluno();

    static void setHorarioFim(int hora, int minuto);
    static int getHoraFim();
    static int getMinutoFim();

    bool entrar(Data *d);
    bool sair(Data *d);
    bool registrarEntradaManual(Data *d);
    bool registrarSaidaManual(Data *d);
};
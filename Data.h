#ifndef DATA_H
#define DATA_H

class Data
{
private:
    int hora = 0;
    int minuto = 0;
    int segundo = 0;
    int dia = 0;
    int mes = 0;
    int ano = 0;

public:
    Data(int hora, int minuto, int segundo, int dia, int mes, int ano);
    virtual ~Data();
    int getHora();
    int getMinuto();
    int getSegundo();
    int getDia();
    int getMes();
    int getAno();
    int diferenca(Data *d);
};
#endif
#include <iostream>
#include <ctime>
#include "Data.h"

using namespace std;

Data::Data(int hora, int minuto, int segundo, int dia, int mes, int ano)
{
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    //if (hora < 0 || hora > 23 || minuto < 0 || minuto > 59 || segundo < 0 || segundo > 59 || dia < 1 || dia > 31 || mes < 1 || mes > 12)
    //{
      //  throw new logic_error("Erro aqui");
    //}
}

Data::~Data()
{
}

int Data::getHora() { return hora; }

int Data::getMinuto() { return minuto; }

int Data::getSegundo() { return segundo; }

int Data::getDia() { return dia; }

int Data::getMes() { return mes; }

int Data::getAno() { return ano; }

int Data::diferenca(Data *d)
{
    tm *data1 = new tm;
    tm *data2 = new tm;

    data1->tm_hour = d->getHora();
    data1->tm_min = d->getMinuto();
    data1->tm_sec = d->getSegundo();
    data1->tm_isdst = 0;
    data1->tm_mday = d->getDia();
    data1->tm_mon = d->getMes() - 1;
    data1->tm_year = d->getAno() - 1900;

    data2->tm_hour = this->getHora();
    data2->tm_min = this->getMinuto();
    data2->tm_sec = this->getSegundo();
    data2->tm_isdst = 0;
    data2->tm_mday = this->getDia();
    data2->tm_mon = this->getMes() - 1;
    data2->tm_year = this->getAno() - 1900;

    time_t inicio = mktime(data1);
    time_t fim = mktime(data2);

    int diferenca = difftime(fim, inicio); // o cast é automatico ja que diferenca é int

    delete data1;
    delete data2;

    return diferenca;
}
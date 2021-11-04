#include "convertidornumerico.h"

convertidornumerico::convertidornumerico(QObject *parent)
{

}

void convertidornumerico::setDec(const QString &valor)
{
    bool ok;
    int num = valor.toInt(&ok);
    if(ok){
        emit hexChanged(QString::number(num,16));
        emit binChanged(QString::number(num,2));
    }
    else
    {
        emit hexChanged("");
        emit binChanged("");
    }
}

void convertidornumerico::setHex(const QString &cadena)
{
    bool ok;
    int num = cadena.toInt(&ok,16);
    if(ok)
    {
        emit decChanged(QString::number(num));
        emit binChanged(QString::number(num,2));
    }
    else
    {
        emit decChanged("");
        emit binChanged("");
    }
}

void convertidornumerico::setBin(const QString &cadena)
{
    bool ok;
    int num = cadena.toInt(&ok, 2);
    if(ok)
    {
        emit decChanged(QString::number(num));
        emit hexChanged(QString::number(num,16));
    }
    else
    {
        emit decChanged("");
        emit hexChanged("");
    }
}

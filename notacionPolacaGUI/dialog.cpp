#include "dialog.h"
#include "ui_dialog.h"
#include "notacionpolaca.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->comboBox->addItem("3*(5-2)^2");
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString expresionInfija = ui->comboBox->itemText(ui->comboBox->currentIndex());
    //Usar clase de notación polaca para convertir a posfija
    NotacionPolaca expresion;
    char *resul = new char[expresionInfija.length()];
    resul = expresion.ConvertirAPosFija(expresionInfija.toStdString());

    ui->lineEdit->setText(resul);
    delete []resul;
}

void Dialog::on_pushButton_4_clicked()
{
    string cadena = ui->lineEdit_2->text().toStdString();

    ui->label_3->setText(QString::fromStdString(cadena));
}

void Dialog::on_pushButton_5_clicked(){
    string cadena = ui->lineEdit_3->text().toStdString();
    QString cadQString = QString::fromStdString(cadena);
    QString numeros = "";

    for(int i=0; i < cadQString.length(); i++){
        if(cadQString.at(i).isDigit())
            numeros.append(cadQString.at(i));
    }

    ui->label_4->setText(numeros);

    string digitos = numeros.toStdString();
    int num = atoi(digitos.c_str());
}


#include "dialog.h"
#include "ui_dialog.h"
#include "QMessageBox"
#include "QString"

// mode = 0 - newton
// mode = 1 - secant
// mode = 2 - both
Dialog::Dialog(int mode, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    dialogMode = mode;
    updated = false;


    ui->setupUi(this);
    this->setModal(true);

    if(dialogMode == 0)
    {
        ui->groupBox_2->setEnabled(false);
    }

    if(dialogMode == 1)
    {
        ui->groupBox->setEnabled(false);
    }

    if(dialogMode == 2)
    {
        ui->groupBox->setEnabled(true);
        ui->groupBox->setEnabled(true);
    }

    connect(this->ui->buttonBox->buttons().at(1), SIGNAL(clicked()), this, SLOT(updateandAccept()));

    switch(model::activeFUNCTION)
    {
    case 'p':{
            this->ui->aditionalLabel->setText("You have chosen an polinomial function to work with");
        }
    case 'l':
        {
            this->ui->aditionalLabel->setText("You have chosen the natural logarithmic function to work with");
        }
    case 'e':
        {

            QString message = QString("You have chosen the exponential function (%1 ^ x) to work with").arg(model::expoBase);
           this->ui->aditionalLabel->setText(message);
        }
    case 's':
        {
            this->ui->aditionalLabel->setText("You have the sinus function to work with");
        }
    case 'c':
        {
           this->ui->aditionalLabel->setText("You have chosen the cosinus function to work with");
        }
    }

}

void Dialog::updateFromModel()
{

    if(updated == false)
    {

        if(dialogMode == 1 || dialogMode == 2)
        {
            this->ui->secantKMAX->setText(QString::number(this->secantKMAX));
            this->ui->secantEPS->setText(QString::number(this->secantEPS));
            this->ui->secantRAND->setChecked(this->secantRAND);
            this->ui->secantX0->setText(QString::number(this->secantX0));
            this->ui->secantX1->setText(QString::number(this->secantX1));
            this->ui->secantRETRYS->setText(QString::number(this->secantRETRYS));
            this->ui->secantRETRYRATIO->setText(QString::number(this->secantRETRYRATIO));
            this->ui->secantSOLUTION->setText(QString::number(this->secantSOLUTION));

        }

        if(dialogMode == 0 || dialogMode == 2)
        {
            this->ui->newtonKMAX->setText(QString::number(this->newtonKMAX));
            this->ui->newtonEPS->setText(QString::number(this->newtonEPS));
            this->ui->newtonRAND->setChecked(this->newtonRAND);
            this->ui->newtonX0->setText(QString::number(this->newtonX0));
            this->ui->newtonX1->setText(QString::number(this->newtonX1));
            this->ui->newtonRETRYS->setText(QString::number(this->newtonRETRYS));
            this->ui->newtonRETRYRATIO->setText(QString::number(this->newtonRETRYRATIO));
            this->ui->newtonSOLUTION->setText(QString::number(this->newtonSOLUTION));
        }

        updated = true;
    }
}

void Dialog::updateandAccept()
{
    if(updated == false){

        if(dialogMode == 1 || dialogMode == 2)
        {
            this->secantKMAX = this->ui->secantKMAX->text().toLong();
            this->secantEPS = this->ui->secantEPS->text().toDouble();
            this->secantRAND = this->ui->secantRAND->isChecked();
            this->secantX0 = this->ui->secantX0->text().toDouble();
            this->secantX1 = this->ui->secantX1->text().toDouble();
            this->secantRETRYS = this->ui->secantRETRYS->text().toInt();
            this->secantRETRYRATIO = this->ui->secantRETRYRATIO->text().toDouble();
            this->secantSOLUTION = this->ui->secantSOLUTION->text().toDouble();
        }

        if(dialogMode == 0 || dialogMode == 2)
        {
            this->newtonKMAX = this->ui->newtonKMAX->text().toLong();
            this->newtonEPS = this->ui->newtonEPS->text().toDouble();
            this->newtonRAND = this->ui->newtonRAND->isChecked();
            this->newtonX0 = this->ui->newtonX0->text().toDouble();
            this->newtonX1 = this->ui->newtonX1->text().toDouble();
            this->newtonRETRYS = this->ui->newtonRETRYS->text().toInt();
            this->newtonRETRYRATIO = this->ui->newtonRETRYRATIO->text().toDouble();
            this->newtonSOLUTION = this->ui->newtonSOLUTION->text().toDouble();
        }
    }

     // inchid dialogul pentru acceptarea datelor de intrare :)
     //emit hide();
     emit accept();
}

Dialog::~Dialog()
{
    delete ui;
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stdio.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0,0, 580, 490);

    // creez modelul
    theModel = model::getInstance();
    secantThread = 0;
    newtonThread = 0;

    // actualizez view-ul
    this->associateActionsToSlots();
    connect(ui->grad, SIGNAL(valueChanged(int)), this, SLOT(enableCoefPoli(int)));
    this->setWindowTitle("Approximation of class C2 continuous functions roots");
    this->center();

    // retin intr-o lista de objects lineediturile ca sa pot extrage ulterior info
    this->coeffs.append(this->ui->c0);
    this->coeffs.append(this->ui->c1);
    this->coeffs.append(this->ui->c2);
    this->coeffs.append(this->ui->c3);
    this->coeffs.append(this->ui->c4);
    this->coeffs.append(this->ui->c5);
    this->coeffs.append(this->ui->c6);

    this->coeffs.append(this->ui->c7);
    this->coeffs.append(this->ui->c8);
    this->coeffs.append(this->ui->c9);
    this->coeffs.append(this->ui->c10);
    this->coeffs.append(this->ui->c11);
    this->coeffs.append(this->ui->c12);
    this->coeffs.append(this->ui->c13);

}

void MainWindow::associateActionsToSlots(){

    connect(ui->actionImport_from_file, SIGNAL(triggered()), this, SLOT(actionImportFromFile()));

    connect(ui->Newton, SIGNAL(triggered()), this, SLOT(actionNewtonMethod()));
    connect(ui->Secant, SIGNAL(triggered()), this, SLOT(actionSecantMethod()));
    connect(ui->Both, SIGNAL(triggered()), this, SLOT(actionBothMethods()));
    connect(ui->stop, SIGNAL(triggered()), this, SLOT(actionstopAllMethods()));
    connect(ui->exit, SIGNAL(triggered()), this, SLOT(close()));

    connect(ui->Polinom, SIGNAL(triggered()), this, SLOT(activatePolinom()));
    connect(ui->Logarithm, SIGNAL(triggered()), this, SLOT(activateLogarithm()));
    connect(ui->Cosinus, SIGNAL(triggered()), this, SLOT(activateCosinus()));
    connect(ui->Sinus, SIGNAL(triggered()), this, SLOT(activateSinus()));
    connect(ui->Exponential, SIGNAL(triggered()), this, SLOT(activateExponential()));
}

void MainWindow::enableCoefPoli(int grad)
{

    // update the model as well
    theModel->coefNumber = grad + 1;

    for(int i = 0; i <= ui->coef->count(); i++)
    {
        QLayoutItem *c = ui->coef->itemAt(i);

        if(c != 0)
        {
            if(i > grad)
                c->widget()->setEnabled(false);
            else
                c->widget()->setEnabled(true);
        }
    }
}

void MainWindow::activatePolinom(){

    theModel->activeFUNCTION = 'p';

    this->setEnablePolinom(true);
    this->setEnableLogarithm(false);
    this->setEnableCosinus(false);
    this->setEnableSinus(false);
    this->setEnableExponential(false);
}

void MainWindow::activateLogarithm(){

    theModel->activeFUNCTION = 'l';

    this->setEnablePolinom(false);
    this->setEnableLogarithm(true);
    this->setEnableCosinus(false);
    this->setEnableSinus(false);
    this->setEnableExponential(false);
}

void MainWindow::activateCosinus(){

    theModel->activeFUNCTION = 'c';

    this->setEnablePolinom(false);
    this->setEnableLogarithm(false);
    this->setEnableCosinus(true);
    this->setEnableSinus(false);
    this->setEnableExponential(false);
}

void MainWindow::activateSinus(){

    theModel->activeFUNCTION = 's';

    this->setEnablePolinom(false);
    this->setEnableLogarithm(false);
    this->setEnableCosinus(false);
    this->setEnableSinus(true);
    this->setEnableExponential(false);
}

void MainWindow::activateExponential(){

    theModel->activeFUNCTION = 'e';

    this->setEnablePolinom(false);
    this->setEnableLogarithm(false);
    this->setEnableCosinus(false);
    this->setEnableSinus(false);
    this->setEnableExponential(true);

}

void MainWindow::setEnablePolinom(bool value){

    ui->polinomial->setEnabled(value);
    ui->grad->setEnabled(value);
    ui->c0->setEnabled(value);
    ui->c1->setEnabled(value);
}

void MainWindow::setEnableLogarithm(bool value){

    ui->logarithmicFunction->setChecked(value);
}

void MainWindow::setEnableCosinus(bool value){
    ui->cosinusFunction->setChecked(value);
}

void MainWindow::setEnableSinus(bool value){
    ui->sinusFunction->setChecked(value);
}

void MainWindow::setEnableExponential(bool value){
    ui->expoBase->setEnabled(value);
}

void MainWindow::actionImportFromFile(){

    // TO DO

    // browse action

    FILE *fin;

    fin = fopen("input.txt", "r");

    fscanf(fin, "%c", &theModel->activeFUNCTION);

    switch(model::activeFUNCTION)
    {
    case 'p':{

           int grade;

            fscanf(fin, "%d", &grade);

            theModel->coefNumber = grade + 1;

            for(int i = 0; i <= theModel->coefNumber; i++)
                fscanf(fin, "%lf", &theModel->coef[i]);
        }
    case 'l':
        {
            // nimic in plus
        }
    case 'e':
        {
            fscanf(fin, "%lf", &theModel->expoBase);
        }
    case 's':
        {
            // nimic in plus
        }
    case 'c':
        {
            // nimic in plus
        }
    }

    int mode;
    fscanf(fin, "%d", &mode);

    dialog = new Dialog(mode, this);

    switch(mode){
    case 0:
        {
            fscanf(fin, "%l", &dialog->newtonKMAX);
            fscanf(fin, "%lf", &dialog->newtonEPS);
            fscanf(fin, "%d", &dialog->newtonRAND);
            fscanf(fin, "%lf", &dialog->newtonX0);
            fscanf(fin, "%lf", &dialog->newtonX1);
            fscanf(fin, "%d", &dialog->newtonRETRYS);
            fscanf(fin, "%lf", &dialog->newtonRETRYRATIO);
            fscanf(fin, "%lf", &dialog->newtonSOLUTION);

            connect(dialog, SIGNAL(accepted()), this, SLOT(beginNewton()));

        }
    case 1:
        {
            fscanf(fin, "%l", &dialog->secantKMAX);
            fscanf(fin, "%lf", &dialog->secantEPS);
            fscanf(fin, "%d", &dialog->secantRAND);
            fscanf(fin, "%lf", &dialog->secantX0);
            fscanf(fin, "%lf", &dialog->secantX1);
            fscanf(fin, "%d", &dialog->secantRETRYS);
            fscanf(fin, "%lf", &dialog->secantRETRYRATIO);
            fscanf(fin, "%lf", &dialog->secantSOLUTION);

            connect(dialog, SIGNAL(accepted()), this, SLOT(beginSecant()));
        }

    case 2:
        {
            fscanf(fin, "%l", &dialog->newtonKMAX);
            fscanf(fin, "%lf", &dialog->newtonEPS);
            fscanf(fin, "%d", &dialog->newtonRAND);
            fscanf(fin, "%lf", &dialog->newtonX0);
            fscanf(fin, "%lf", &dialog->newtonX1);
            fscanf(fin, "%d", &dialog->newtonRETRYS);
            fscanf(fin, "%lf", &dialog->newtonRETRYRATIO);
            fscanf(fin, "%lf", &dialog->newtonSOLUTION);

            fscanf(fin, "%l", &dialog->secantKMAX);
            fscanf(fin, "%lf", &dialog->secantEPS);
            fscanf(fin, "%d", &dialog->secantRAND);
            fscanf(fin, "%lf", &dialog->secantX0);
            fscanf(fin, "%lf", &dialog->secantX1);
            fscanf(fin, "%d", &dialog->secantRETRYS);
            fscanf(fin, "%lf", &dialog->secantRETRYRATIO);
            fscanf(fin, "%lf", &dialog->secantSOLUTION);

            connect(dialog, SIGNAL(accepted()), this, SLOT(beginBothMethods()));
        }
    }
    fclose(fin);

    dialog->updateFromModel();
    dialog->show();

}

void MainWindow::actionNewtonMethod(){

  updateModelfromInterface();

  dialog0 = new Dialog(0, this);
  connect(dialog0, SIGNAL(accepted()), this, SLOT(beginNewton()));

  dialog0->show();
}

void MainWindow::beginNewton()
{
    // pornesc thread. cand el termina voi prelua datele.
    newtonThread = new newtonMethodThread(dialog0, this);
    newtonThread->start();

    connect(newtonThread, SIGNAL(done()), this, SLOT(inspectNewton()));
}


void MainWindow::inspectNewton()
{
    QMessageBox msgBox;
     msgBox.setText("newton result");
     msgBox.setInformativeText(QString::number(model::newtonSolutionFound));
     int ret = msgBox.exec();
}

void MainWindow::actionSecantMethod(){

  updateModelfromInterface();

  dialog1 = new Dialog(1, this);
  connect(dialog1, SIGNAL(accepted()), this, SLOT(beginSecant()));

  dialog1->show();

}

void MainWindow::beginSecant()
{
    secantThread = new secantMethodThread(dialog1, this);
    secantThread->start();

    connect(secantThread, SIGNAL(done()), this, SLOT(inspectSecant()));
}

void MainWindow::inspectSecant()
{
    QMessageBox msgBox;
      msgBox.setText("secant result");
      msgBox.setInformativeText(QString::number(theModel->secantSolutionFound));
      int ret = msgBox.exec();
}

void MainWindow::actionBothMethods(){

    updateModelfromInterface();

    this->ui->outputMessage->setEnabled(false);
    this->ui->outputMessage->clear();

    dialog2 = new Dialog(2, this);
    connect(dialog2, SIGNAL(accepted()), this, SLOT(beginBothMethods()));

    dialog2->show();

}

void MainWindow::beginBothMethods(){

    newtonThread = new newtonMethodThread(dialog2, this);
    connect(newtonThread, SIGNAL(done()), this, SLOT(inspectBothMethodsNewtonResultFirst()));

    secantThread = new secantMethodThread(dialog2, this);
    connect(secantThread, SIGNAL(done()), this, SLOT(inspectBothMethodsSecantResultFirst()));

    newtonThread->start();
    secantThread->start();
}

void MainWindow::inspectBothMethodsNewtonResultFirst(){

    // eu am terminat, eu uptadtez interfata cu informatiile necesare
    if(model::winnerMethod == 'n'){

        // opresc celalalt thread
        secantThread->terminate();
        newtonThread->terminate();

        QMessageBox msgBox;
        msgBox.setText("newton result");
        msgBox.setInformativeText(QString::number(model::newtonSolutionFound));
        int ret = msgBox.exec();

        QString message = QString("The Newton Method Terminated First.\n");

        message.append(QString::number(model::newtonSolutionFound, 'g', 10));

        this->ui->outputMessage->clear();
        this->ui->outputMessage->setEnabled(true);
        this->ui->outputMessage->setText(message);

    }
}

void MainWindow::inspectBothMethodsSecantResultFirst(){

    // eu am terminat, eu uptadtez interfata cu informatiile necesare
    if(model::winnerMethod == 's')
    {
        newtonThread->terminate();
        secantThread->terminate();

        QMessageBox msgBox;
        msgBox.setText("secant result");
        msgBox.setInformativeText(QString::number(theModel->secantSolutionFound));
        int ret = msgBox.exec();

        QString message = QString("The Secant Method Terminated First.\n");

        message.append(QString::number(model::secantSolutionFound, 'g', 10));

        this->ui->outputMessage->clear();
        this->ui->outputMessage->setEnabled(true);
        this->ui->outputMessage->setText(message);
    }
}

void MainWindow::actionstopAllMethods(){


    if(newtonThread)
        newtonThread->terminate();

    if(secantThread)
        secantThread->terminate();


    QMessageBox msgBox;
    msgBox.setText("All operations have stopped!");

    int ret = msgBox.exec();
}

void MainWindow::center()
{
  int x, y;
  int screenWidth;
  int screenHeight;
  int width, height;

  QDesktopWidget *desktop = QApplication::desktop();

  width = this->frameGeometry().width();
  height = this->frameGeometry().height();

  screenWidth = desktop->width();
  screenHeight = desktop->height();

  x = (screenWidth - width) / 2;
  y = (screenHeight - height) / 2;

  this->move(x, y);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::  updateModelfromInterface()
{

    // a0 = 42.0 , a1 = -55.0 , a2 = -42.0 , a3 = 49.0 , a4 = -6.0.
        /*theModel->coefNumber = 5;
        theModel->coef[0] = 42.0;
        theModel->coef[1] = -55.0;
        theModel->coef[2] = -42.0;
        theModel->coef[3] = -49.0;
        theModel->coef[3] = -6.0;
*/

        //double rez = theModel->findSquare(theModel->activeFUNCTION, 'p', 1000, 0.00001, false, 10, 5, 50, -1, 2.6);

    switch(model::activeFUNCTION)
        {
            case 'p':
            {
                for(int i = 0; i < theModel->coefNumber; i++)
                {
                    theModel->coef[i] = ((QLineEdit*)this->coeffs[i])->text().toDouble();
                }
            }

            case 'e':
            {
                theModel->expoBase = this->ui->expoBase->text().toDouble();
            }

            case 'l':
            {
                // nimic
            }

            case 'c':
            {
                // nimic
            }

            case 's':
            {
                // nimic
            }
        }
}


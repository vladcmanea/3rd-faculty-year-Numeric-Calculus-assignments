#include "newtonmethodthread.h"

newtonMethodThread::newtonMethodThread(const Dialog *dialog, QObject *parent) :
    QThread(parent)
{
       this->dialog = dialog;
       this->setObjectName("newtonThread");
}

void newtonMethodThread::run(){

    double solution = model::getInstance()->findSquare(model::activeFUNCTION, 'n', dialog->newtonKMAX, dialog->newtonEPS, dialog->newtonRAND, dialog->newtonX0, dialog->newtonX1, dialog->newtonRETRYS, dialog->newtonRETRYRATIO, dialog->newtonSOLUTION);

    model::mutex->lock();

    model::getInstance()->newtonSolutionFound = solution;

    if(model::gotMethodSolution == false)
    {
        model::gotMethodSolution = true;
        model::winnerMethod = 'n';
    }

    model::mutex->unlock();

    emit done();

}


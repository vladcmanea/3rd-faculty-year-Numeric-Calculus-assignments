#include "secantmethodthread.h"

secantMethodThread::secantMethodThread(const Dialog *dialog, QObject *parent) :
    QThread(parent)
{
    this->dialog = dialog;
    this->setObjectName("secantThread");
}

void secantMethodThread::run()
{
    double solution = model::getInstance()->findSquare(model::activeFUNCTION, 's', dialog->secantKMAX, dialog->secantEPS, dialog->secantRAND, dialog->secantX0, dialog->secantX1, dialog->secantRETRYS, dialog->secantRETRYRATIO, dialog->secantSOLUTION);

    model::mutex->lock();

    model::getInstance()->secantSolutionFound = solution;

    if(model::gotMethodSolution == false)
    {
        model::gotMethodSolution = true;
        model::winnerMethod = 's';
    }

    model::mutex->unlock();

    emit done();

}


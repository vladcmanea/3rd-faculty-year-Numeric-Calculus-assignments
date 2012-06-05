#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "model.h"

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(int mode, QWidget *parent = 0);
    ~Dialog();
    void updateFromModel();

    Ui::Dialog *ui;

    int dialogMode;

    long newtonKMAX;
    double newtonEPS;
    bool newtonRAND;
    double newtonX0, newtonX1;
    int newtonRETRYS;
    double newtonRETRYRATIO;
    double newtonSOLUTION;

    long secantKMAX;
    double secantEPS;
    bool secantRAND;
    double secantX0, secantX1;
    int secantRETRYS;
    double secantRETRYRATIO;
    double secantSOLUTION;

    bool updated;

public slots:
    void updateandAccept();




};

#endif // DIALOG_H

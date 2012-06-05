#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qapplication.h"
#include "dialog.h"
#include "model.h"
#include "qlist.h"
#include <QMetaObject>
#include "QObject"
#include "newtonmethodthread.h"
#include "secantmethodthread.h"
#include "QDesktopWidget.h"
#include <qDebug>
#include "QString"
#include "QAction.h"
#include <QMessageBox>
#include <QLayoutItem>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    // date de model
    model *theModel;
    newtonMethodThread *newtonThread;
    secantMethodThread *secantThread;

    // date & metode de interfata
    QList<QObject*> coeffs;
    Ui::MainWindow *ui;
    Dialog* dialog0, *dialog1, *dialog2, *dialog;

    void center();
    void associateActionsToSlots();

    void updateModelfromInterface();

    void setEnablePolinom(bool value);
    void setEnableLogarithm(bool value);
    void setEnableCosinus(bool value);
    void setEnableSinus(bool value);
    void setEnableExponential(bool value);

public slots:
    void activatePolinom();
    void activateLogarithm();
    void activateCosinus();
    void activateSinus();
    void activateExponential();

    void enableCoefPoli(int grade);

    void actionImportFromFile();

    void actionNewtonMethod();
    void beginNewton();
    void inspectNewton();

    void actionSecantMethod();
    void beginSecant();
    void inspectSecant();

    void actionBothMethods();
    void beginBothMethods();
    void actionstopAllMethods();
    void inspectBothMethodsNewtonResultFirst();
    void inspectBothMethodsSecantResultFirst();

signals:

};

#endif // MAINWINDOW_H

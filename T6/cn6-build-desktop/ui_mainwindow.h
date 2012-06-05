/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed May 4 13:03:48 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *stop;
    QAction *exit;
    QAction *newton;
    QAction *secant;
    QAction *both;
    QAction *polinom;
    QAction *logarithm;
    QAction *cosinus;
    QAction *sinus;
    QAction *exponential;
    QAction *actionImport_from_file;
    QAction *Polinom;
    QAction *Logarithm;
    QAction *Exponential;
    QAction *Sinus;
    QAction *Cosinus;
    QAction *Newton;
    QAction *Secant;
    QAction *Both;
    QWidget *centralWidget;
    QGroupBox *outputBox;
    QTextEdit *outputMessage;
    QGroupBox *inputBox;
    QGroupBox *polinomial;
    QLabel *label_3;
    QLabel *label_2;
    QSpinBox *grad;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *coef;
    QLineEdit *c0;
    QLineEdit *c1;
    QLineEdit *c2;
    QLineEdit *c3;
    QLineEdit *c4;
    QLineEdit *c5;
    QLineEdit *c6;
    QLineEdit *c7;
    QLineEdit *c8;
    QLineEdit *c9;
    QLineEdit *c10;
    QLineEdit *c11;
    QLineEdit *c12;
    QLineEdit *c13;
    QGroupBox *expoGroup;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLineEdit *expoBase;
    QGroupBox *groupBox;
    QCheckBox *logarithmicFunction;
    QCheckBox *cosinusFunction;
    QCheckBox *sinusFunction;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menuStep_one;
    QMenu *menuChoose_Function;
    QMenu *menuStep_Two;
    QMenu *menuStart;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(579, 462);
        stop = new QAction(MainWindow);
        stop->setObjectName(QString::fromUtf8("stop"));
        exit = new QAction(MainWindow);
        exit->setObjectName(QString::fromUtf8("exit"));
        newton = new QAction(MainWindow);
        newton->setObjectName(QString::fromUtf8("newton"));
        secant = new QAction(MainWindow);
        secant->setObjectName(QString::fromUtf8("secant"));
        both = new QAction(MainWindow);
        both->setObjectName(QString::fromUtf8("both"));
        polinom = new QAction(MainWindow);
        polinom->setObjectName(QString::fromUtf8("polinom"));
        logarithm = new QAction(MainWindow);
        logarithm->setObjectName(QString::fromUtf8("logarithm"));
        cosinus = new QAction(MainWindow);
        cosinus->setObjectName(QString::fromUtf8("cosinus"));
        sinus = new QAction(MainWindow);
        sinus->setObjectName(QString::fromUtf8("sinus"));
        exponential = new QAction(MainWindow);
        exponential->setObjectName(QString::fromUtf8("exponential"));
        actionImport_from_file = new QAction(MainWindow);
        actionImport_from_file->setObjectName(QString::fromUtf8("actionImport_from_file"));
        Polinom = new QAction(MainWindow);
        Polinom->setObjectName(QString::fromUtf8("Polinom"));
        Logarithm = new QAction(MainWindow);
        Logarithm->setObjectName(QString::fromUtf8("Logarithm"));
        Exponential = new QAction(MainWindow);
        Exponential->setObjectName(QString::fromUtf8("Exponential"));
        Sinus = new QAction(MainWindow);
        Sinus->setObjectName(QString::fromUtf8("Sinus"));
        Cosinus = new QAction(MainWindow);
        Cosinus->setObjectName(QString::fromUtf8("Cosinus"));
        Newton = new QAction(MainWindow);
        Newton->setObjectName(QString::fromUtf8("Newton"));
        Secant = new QAction(MainWindow);
        Secant->setObjectName(QString::fromUtf8("Secant"));
        Both = new QAction(MainWindow);
        Both->setObjectName(QString::fromUtf8("Both"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        outputBox = new QGroupBox(centralWidget);
        outputBox->setObjectName(QString::fromUtf8("outputBox"));
        outputBox->setGeometry(QRect(10, 250, 561, 151));
        outputMessage = new QTextEdit(outputBox);
        outputMessage->setObjectName(QString::fromUtf8("outputMessage"));
        outputMessage->setEnabled(true);
        outputMessage->setGeometry(QRect(10, 20, 531, 121));
        outputMessage->setReadOnly(true);
        inputBox = new QGroupBox(centralWidget);
        inputBox->setObjectName(QString::fromUtf8("inputBox"));
        inputBox->setGeometry(QRect(10, 10, 561, 231));
        polinomial = new QGroupBox(inputBox);
        polinomial->setObjectName(QString::fromUtf8("polinomial"));
        polinomial->setGeometry(QRect(20, 80, 521, 141));
        label_3 = new QLabel(polinomial);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(28, 115, 331, 16));
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(polinomial);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 56, 61, 16));
        grad = new QSpinBox(polinomial);
        grad->setObjectName(QString::fromUtf8("grad"));
        grad->setEnabled(false);
        grad->setGeometry(QRect(98, 21, 51, 22));
        grad->setMinimum(1);
        grad->setMaximum(13);
        label = new QLabel(polinomial);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 29, 46, 13));
        layoutWidget = new QWidget(polinomial);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(98, 50, 411, 48));
        coef = new QGridLayout(layoutWidget);
        coef->setSpacing(6);
        coef->setContentsMargins(11, 11, 11, 11);
        coef->setObjectName(QString::fromUtf8("coef"));
        coef->setContentsMargins(0, 0, 0, 0);
        c0 = new QLineEdit(layoutWidget);
        c0->setObjectName(QString::fromUtf8("c0"));
        c0->setEnabled(false);

        coef->addWidget(c0, 0, 0, 1, 1);

        c1 = new QLineEdit(layoutWidget);
        c1->setObjectName(QString::fromUtf8("c1"));
        c1->setEnabled(false);

        coef->addWidget(c1, 0, 1, 1, 1);

        c2 = new QLineEdit(layoutWidget);
        c2->setObjectName(QString::fromUtf8("c2"));
        c2->setEnabled(false);

        coef->addWidget(c2, 0, 2, 1, 1);

        c3 = new QLineEdit(layoutWidget);
        c3->setObjectName(QString::fromUtf8("c3"));
        c3->setEnabled(false);

        coef->addWidget(c3, 0, 3, 1, 1);

        c4 = new QLineEdit(layoutWidget);
        c4->setObjectName(QString::fromUtf8("c4"));
        c4->setEnabled(false);

        coef->addWidget(c4, 0, 4, 1, 1);

        c5 = new QLineEdit(layoutWidget);
        c5->setObjectName(QString::fromUtf8("c5"));
        c5->setEnabled(false);

        coef->addWidget(c5, 0, 5, 1, 1);

        c6 = new QLineEdit(layoutWidget);
        c6->setObjectName(QString::fromUtf8("c6"));
        c6->setEnabled(false);

        coef->addWidget(c6, 0, 6, 1, 1);

        c7 = new QLineEdit(layoutWidget);
        c7->setObjectName(QString::fromUtf8("c7"));
        c7->setEnabled(false);

        coef->addWidget(c7, 1, 0, 1, 1);

        c8 = new QLineEdit(layoutWidget);
        c8->setObjectName(QString::fromUtf8("c8"));
        c8->setEnabled(false);

        coef->addWidget(c8, 1, 1, 1, 1);

        c9 = new QLineEdit(layoutWidget);
        c9->setObjectName(QString::fromUtf8("c9"));
        c9->setEnabled(false);

        coef->addWidget(c9, 1, 2, 1, 1);

        c10 = new QLineEdit(layoutWidget);
        c10->setObjectName(QString::fromUtf8("c10"));
        c10->setEnabled(false);

        coef->addWidget(c10, 1, 3, 1, 1);

        c11 = new QLineEdit(layoutWidget);
        c11->setObjectName(QString::fromUtf8("c11"));
        c11->setEnabled(false);

        coef->addWidget(c11, 1, 4, 1, 1);

        c12 = new QLineEdit(layoutWidget);
        c12->setObjectName(QString::fromUtf8("c12"));
        c12->setEnabled(false);

        coef->addWidget(c12, 1, 5, 1, 1);

        c13 = new QLineEdit(layoutWidget);
        c13->setObjectName(QString::fromUtf8("c13"));
        c13->setEnabled(false);

        coef->addWidget(c13, 1, 6, 1, 1);

        expoGroup = new QGroupBox(inputBox);
        expoGroup->setObjectName(QString::fromUtf8("expoGroup"));
        expoGroup->setGeometry(QRect(20, 20, 171, 51));
        layoutWidget_2 = new QWidget(expoGroup);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 20, 151, 22));
        gridLayout_3 = new QGridLayout(layoutWidget_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 0, 0, 1, 1);

        expoBase = new QLineEdit(layoutWidget_2);
        expoBase->setObjectName(QString::fromUtf8("expoBase"));
        expoBase->setEnabled(false);

        gridLayout_3->addWidget(expoBase, 0, 1, 1, 1);

        groupBox = new QGroupBox(inputBox);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(200, 20, 341, 51));
        logarithmicFunction = new QCheckBox(groupBox);
        logarithmicFunction->setObjectName(QString::fromUtf8("logarithmicFunction"));
        logarithmicFunction->setEnabled(false);
        logarithmicFunction->setGeometry(QRect(220, 20, 111, 17));
        cosinusFunction = new QCheckBox(groupBox);
        cosinusFunction->setObjectName(QString::fromUtf8("cosinusFunction"));
        cosinusFunction->setEnabled(false);
        cosinusFunction->setGeometry(QRect(120, 20, 101, 17));
        sinusFunction = new QCheckBox(groupBox);
        sinusFunction->setObjectName(QString::fromUtf8("sinusFunction"));
        sinusFunction->setEnabled(false);
        sinusFunction->setGeometry(QRect(10, 20, 91, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 579, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuStep_one = new QMenu(menu);
        menuStep_one->setObjectName(QString::fromUtf8("menuStep_one"));
        menuChoose_Function = new QMenu(menuStep_one);
        menuChoose_Function->setObjectName(QString::fromUtf8("menuChoose_Function"));
        menuStep_Two = new QMenu(menu);
        menuStep_Two->setObjectName(QString::fromUtf8("menuStep_Two"));
        menuStart = new QMenu(menuStep_Two);
        menuStart->setObjectName(QString::fromUtf8("menuStart"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(menuStep_one->menuAction());
        menu->addSeparator();
        menu->addAction(menuStep_Two->menuAction());
        menu->addSeparator();
        menu->addAction(exit);
        menuStep_one->addAction(actionImport_from_file);
        menuStep_one->addAction(menuChoose_Function->menuAction());
        menuChoose_Function->addAction(Polinom);
        menuChoose_Function->addAction(Logarithm);
        menuChoose_Function->addAction(Exponential);
        menuChoose_Function->addAction(Sinus);
        menuChoose_Function->addAction(Cosinus);
        menuStep_Two->addAction(menuStart->menuAction());
        menuStep_Two->addAction(stop);
        menuStart->addAction(Newton);
        menuStart->addAction(Secant);
        menuStart->addSeparator();
        menuStart->addAction(Both);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        stop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        exit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        newton->setText(QApplication::translate("MainWindow", "Newton Rapson Method", 0, QApplication::UnicodeUTF8));
        secant->setText(QApplication::translate("MainWindow", "Secant Method", 0, QApplication::UnicodeUTF8));
        both->setText(QApplication::translate("MainWindow", "Both Metods", 0, QApplication::UnicodeUTF8));
        polinom->setText(QApplication::translate("MainWindow", "Polinomial", 0, QApplication::UnicodeUTF8));
        logarithm->setText(QApplication::translate("MainWindow", "Logaritm", 0, QApplication::UnicodeUTF8));
        cosinus->setText(QApplication::translate("MainWindow", "cosinus", 0, QApplication::UnicodeUTF8));
        sinus->setText(QApplication::translate("MainWindow", "sinus", 0, QApplication::UnicodeUTF8));
        exponential->setText(QApplication::translate("MainWindow", "exponential", 0, QApplication::UnicodeUTF8));
        actionImport_from_file->setText(QApplication::translate("MainWindow", "Import from file...", 0, QApplication::UnicodeUTF8));
        Polinom->setText(QApplication::translate("MainWindow", "Polinomial", 0, QApplication::UnicodeUTF8));
        Logarithm->setText(QApplication::translate("MainWindow", "Logaritmic", 0, QApplication::UnicodeUTF8));
        Exponential->setText(QApplication::translate("MainWindow", "Exponential", 0, QApplication::UnicodeUTF8));
        Sinus->setText(QApplication::translate("MainWindow", "Sinus", 0, QApplication::UnicodeUTF8));
        Cosinus->setText(QApplication::translate("MainWindow", "Cosinus", 0, QApplication::UnicodeUTF8));
        Newton->setText(QApplication::translate("MainWindow", "Newton Rapson Method", 0, QApplication::UnicodeUTF8));
        Secant->setText(QApplication::translate("MainWindow", "Secant Method", 0, QApplication::UnicodeUTF8));
        Both->setText(QApplication::translate("MainWindow", "Both Methods", 0, QApplication::UnicodeUTF8));
        outputBox->setTitle(QApplication::translate("MainWindow", "Output", 0, QApplication::UnicodeUTF8));
        inputBox->setTitle(QApplication::translate("MainWindow", "Input Function Used and its description", 0, QApplication::UnicodeUTF8));
        polinomial->setTitle(QApplication::translate("MainWindow", "Polinomial Function Arguments", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Note. The order in which coefficients are processed is: right to left!", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Coefficients", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Grade", 0, QApplication::UnicodeUTF8));
        expoGroup->setTitle(QApplication::translate("MainWindow", "Exponential Function", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "base", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Other Functions", 0, QApplication::UnicodeUTF8));
        logarithmicFunction->setText(QApplication::translate("MainWindow", "logarithmic function", 0, QApplication::UnicodeUTF8));
        cosinusFunction->setText(QApplication::translate("MainWindow", "cosinus function", 0, QApplication::UnicodeUTF8));
        sinusFunction->setText(QApplication::translate("MainWindow", "sinus function", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("MainWindow", "Menu", 0, QApplication::UnicodeUTF8));
        menuStep_one->setTitle(QApplication::translate("MainWindow", "Step one", 0, QApplication::UnicodeUTF8));
        menuChoose_Function->setTitle(QApplication::translate("MainWindow", "Choose Function", 0, QApplication::UnicodeUTF8));
        menuStep_Two->setTitle(QApplication::translate("MainWindow", "Step Two", 0, QApplication::UnicodeUTF8));
        menuStart->setTitle(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

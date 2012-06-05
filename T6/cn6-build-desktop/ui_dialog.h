/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created: Wed May 4 13:53:43 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *newtonKMAX;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_7;
    QLineEdit *newtonX1;
    QLabel *label_8;
    QLineEdit *newtonRETRYS;
    QLineEdit *newtonRETRYRATIO;
    QLineEdit *newtonSOLUTION;
    QLabel *label_6;
    QLineEdit *newtonX0;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *newtonEPS;
    QCheckBox *newtonRAND;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QLineEdit *secantKMAX;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *secantX1;
    QLabel *label_13;
    QLineEdit *secantRETRYS;
    QLineEdit *secantRETRYRATIO;
    QLineEdit *secantSOLUTION;
    QLabel *label_14;
    QLineEdit *secantX0;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *secantEPS;
    QCheckBox *secantRAND;
    QLabel *aditionalLabel;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(571, 376);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(380, 320, 161, 32));
        buttonBox->setMouseTracking(false);
        buttonBox->setLayoutDirection(Qt::RightToLeft);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel);
        buttonBox->setCenterButtons(true);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 20, 251, 271));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 237, 235));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        newtonKMAX = new QLineEdit(layoutWidget);
        newtonKMAX->setObjectName(QString::fromUtf8("newtonKMAX"));

        gridLayout->addWidget(newtonKMAX, 0, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 7, 0, 1, 1);

        newtonX1 = new QLineEdit(layoutWidget);
        newtonX1->setObjectName(QString::fromUtf8("newtonX1"));
        newtonX1->setEnabled(false);

        gridLayout->addWidget(newtonX1, 7, 2, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 8, 0, 1, 1);

        newtonRETRYS = new QLineEdit(layoutWidget);
        newtonRETRYS->setObjectName(QString::fromUtf8("newtonRETRYS"));

        gridLayout->addWidget(newtonRETRYS, 8, 2, 1, 1);

        newtonRETRYRATIO = new QLineEdit(layoutWidget);
        newtonRETRYRATIO->setObjectName(QString::fromUtf8("newtonRETRYRATIO"));

        gridLayout->addWidget(newtonRETRYRATIO, 9, 2, 1, 1);

        newtonSOLUTION = new QLineEdit(layoutWidget);
        newtonSOLUTION->setObjectName(QString::fromUtf8("newtonSOLUTION"));

        gridLayout->addWidget(newtonSOLUTION, 10, 2, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 9, 0, 1, 1);

        newtonX0 = new QLineEdit(layoutWidget);
        newtonX0->setObjectName(QString::fromUtf8("newtonX0"));

        gridLayout->addWidget(newtonX0, 4, 2, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 10, 0, 1, 1);

        newtonEPS = new QLineEdit(layoutWidget);
        newtonEPS->setObjectName(QString::fromUtf8("newtonEPS"));

        gridLayout->addWidget(newtonEPS, 1, 2, 1, 1);

        newtonRAND = new QCheckBox(layoutWidget);
        newtonRAND->setObjectName(QString::fromUtf8("newtonRAND"));

        gridLayout->addWidget(newtonRAND, 3, 2, 1, 1);

        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(290, 20, 251, 271));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 237, 235));
        gridLayout_2 = new QGridLayout(layoutWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        secantKMAX = new QLineEdit(layoutWidget1);
        secantKMAX->setObjectName(QString::fromUtf8("secantKMAX"));

        gridLayout_2->addWidget(secantKMAX, 0, 2, 1, 1);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);

        label_11 = new QLabel(layoutWidget1);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_2->addWidget(label_11, 4, 0, 1, 1);

        label_12 = new QLabel(layoutWidget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_2->addWidget(label_12, 8, 0, 1, 1);

        secantX1 = new QLineEdit(layoutWidget1);
        secantX1->setObjectName(QString::fromUtf8("secantX1"));

        gridLayout_2->addWidget(secantX1, 8, 2, 1, 1);

        label_13 = new QLabel(layoutWidget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_2->addWidget(label_13, 9, 0, 1, 1);

        secantRETRYS = new QLineEdit(layoutWidget1);
        secantRETRYS->setObjectName(QString::fromUtf8("secantRETRYS"));

        gridLayout_2->addWidget(secantRETRYS, 9, 2, 1, 1);

        secantRETRYRATIO = new QLineEdit(layoutWidget1);
        secantRETRYRATIO->setObjectName(QString::fromUtf8("secantRETRYRATIO"));

        gridLayout_2->addWidget(secantRETRYRATIO, 10, 2, 1, 1);

        secantSOLUTION = new QLineEdit(layoutWidget1);
        secantSOLUTION->setObjectName(QString::fromUtf8("secantSOLUTION"));

        gridLayout_2->addWidget(secantSOLUTION, 11, 2, 1, 1);

        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_2->addWidget(label_14, 10, 0, 1, 1);

        secantX0 = new QLineEdit(layoutWidget1);
        secantX0->setObjectName(QString::fromUtf8("secantX0"));

        gridLayout_2->addWidget(secantX0, 5, 2, 1, 1);

        label_15 = new QLabel(layoutWidget1);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_2->addWidget(label_15, 5, 0, 1, 1);

        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_2->addWidget(label_16, 11, 0, 1, 1);

        secantEPS = new QLineEdit(layoutWidget1);
        secantEPS->setObjectName(QString::fromUtf8("secantEPS"));

        gridLayout_2->addWidget(secantEPS, 1, 2, 1, 1);

        secantRAND = new QCheckBox(layoutWidget1);
        secantRAND->setObjectName(QString::fromUtf8("secantRAND"));

        gridLayout_2->addWidget(secantRAND, 4, 2, 1, 1);

        aditionalLabel = new QLabel(Dialog);
        aditionalLabel->setObjectName(QString::fromUtf8("aditionalLabel"));
        aditionalLabel->setGeometry(QRect(30, 310, 311, 51));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Dialog", "Newton - Rapson Method", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "Iteration Number", 0, QApplication::UnicodeUTF8));
        newtonKMAX->setText(QApplication::translate("Dialog", "100", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "Epsilon", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Dialog", "Random", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Dialog", "X1", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Dialog", "Nr. of Retry Attempts", 0, QApplication::UnicodeUTF8));
        newtonRETRYS->setText(QApplication::translate("Dialog", "100", 0, QApplication::UnicodeUTF8));
        newtonRETRYRATIO->setText(QApplication::translate("Dialog", "-1", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Dialog", "Retry Ratio", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Dialog", "X0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Dialog", "Searched Solution", 0, QApplication::UnicodeUTF8));
        newtonEPS->setText(QApplication::translate("Dialog", "0.00001", 0, QApplication::UnicodeUTF8));
        newtonRAND->setText(QApplication::translate("Dialog", "enabled", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("Dialog", "Secant Method", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Dialog", "Iteration Number", 0, QApplication::UnicodeUTF8));
        secantKMAX->setText(QApplication::translate("Dialog", "100", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Dialog", "Epsilon", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Dialog", "Random", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Dialog", "X1", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("Dialog", "Nr. of Retry Attempts", 0, QApplication::UnicodeUTF8));
        secantRETRYS->setText(QApplication::translate("Dialog", "100", 0, QApplication::UnicodeUTF8));
        secantRETRYRATIO->setText(QApplication::translate("Dialog", "-1", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("Dialog", "Retry Ratio", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("Dialog", "X0", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("Dialog", "Searched Solution", 0, QApplication::UnicodeUTF8));
        secantEPS->setText(QApplication::translate("Dialog", "0.0001", 0, QApplication::UnicodeUTF8));
        secantRAND->setText(QApplication::translate("Dialog", "enabled", 0, QApplication::UnicodeUTF8));
        aditionalLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

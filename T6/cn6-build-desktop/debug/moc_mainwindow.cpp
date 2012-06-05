/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Wed May 4 15:27:52 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../cn6/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      30,   11,   11,   11, 0x0a,
      50,   11,   11,   11, 0x0a,
      68,   11,   11,   11, 0x0a,
      84,   11,   11,   11, 0x0a,
     112,  106,   11,   11, 0x0a,
     132,   11,   11,   11, 0x0a,
     155,   11,   11,   11, 0x0a,
     176,   11,   11,   11, 0x0a,
     190,   11,   11,   11, 0x0a,
     206,   11,   11,   11, 0x0a,
     227,   11,   11,   11, 0x0a,
     241,   11,   11,   11, 0x0a,
     257,   11,   11,   11, 0x0a,
     277,   11,   11,   11, 0x0a,
     296,   11,   11,   11, 0x0a,
     319,   11,   11,   11, 0x0a,
     357,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0activatePolinom()\0"
    "activateLogarithm()\0activateCosinus()\0"
    "activateSinus()\0activateExponential()\0"
    "grade\0enableCoefPoli(int)\0"
    "actionImportFromFile()\0actionNewtonMethod()\0"
    "beginNewton()\0inspectNewton()\0"
    "actionSecantMethod()\0beginSecant()\0"
    "inspectSecant()\0actionBothMethods()\0"
    "beginBothMethods()\0actionstopAllMethods()\0"
    "inspectBothMethodsNewtonResultFirst()\0"
    "inspectBothMethodsSecantResultFirst()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: activatePolinom(); break;
        case 1: activateLogarithm(); break;
        case 2: activateCosinus(); break;
        case 3: activateSinus(); break;
        case 4: activateExponential(); break;
        case 5: enableCoefPoli((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: actionImportFromFile(); break;
        case 7: actionNewtonMethod(); break;
        case 8: beginNewton(); break;
        case 9: inspectNewton(); break;
        case 10: actionSecantMethod(); break;
        case 11: beginSecant(); break;
        case 12: inspectSecant(); break;
        case 13: actionBothMethods(); break;
        case 14: beginBothMethods(); break;
        case 15: actionstopAllMethods(); break;
        case 16: inspectBothMethodsNewtonResultFirst(); break;
        case 17: inspectBothMethodsSecantResultFirst(); break;
        default: ;
        }
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE

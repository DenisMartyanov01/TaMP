/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../TaMP_fall/GUI/mainwindow.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "send_task",
    "",
    "sort_request_main",
    "request_lookmystat_main",
    "request_lookallstat_main",
    "request_sort_main",
    "signal_stat_error",
    "signal_received_mystat",
    "signal_received_allstat",
    "on_pushButton_Exit_clicked",
    "on_pushButton_Task1_clicked",
    "on_pushButton_Task2_clicked",
    "on_pushButton_Task3_clicked",
    "on_pushButton_Stats_clicked",
    "on_return",
    "slot_send_task",
    "slot_request_sort",
    "slot_request_lookmystat",
    "slot_request_lookallstat",
    "slot_stat_error",
    "slot_received_mystat",
    "slot_received_allstat"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[46];
    char stringdata0[11];
    char stringdata1[10];
    char stringdata2[1];
    char stringdata3[18];
    char stringdata4[24];
    char stringdata5[25];
    char stringdata6[18];
    char stringdata7[18];
    char stringdata8[23];
    char stringdata9[24];
    char stringdata10[27];
    char stringdata11[28];
    char stringdata12[28];
    char stringdata13[28];
    char stringdata14[28];
    char stringdata15[10];
    char stringdata16[15];
    char stringdata17[18];
    char stringdata18[24];
    char stringdata19[25];
    char stringdata20[16];
    char stringdata21[21];
    char stringdata22[22];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 9),  // "send_task"
        QT_MOC_LITERAL(21, 0),  // ""
        QT_MOC_LITERAL(22, 17),  // "sort_request_main"
        QT_MOC_LITERAL(40, 23),  // "request_lookmystat_main"
        QT_MOC_LITERAL(64, 24),  // "request_lookallstat_main"
        QT_MOC_LITERAL(89, 17),  // "request_sort_main"
        QT_MOC_LITERAL(107, 17),  // "signal_stat_error"
        QT_MOC_LITERAL(125, 22),  // "signal_received_mystat"
        QT_MOC_LITERAL(148, 23),  // "signal_received_allstat"
        QT_MOC_LITERAL(172, 26),  // "on_pushButton_Exit_clicked"
        QT_MOC_LITERAL(199, 27),  // "on_pushButton_Task1_clicked"
        QT_MOC_LITERAL(227, 27),  // "on_pushButton_Task2_clicked"
        QT_MOC_LITERAL(255, 27),  // "on_pushButton_Task3_clicked"
        QT_MOC_LITERAL(283, 27),  // "on_pushButton_Stats_clicked"
        QT_MOC_LITERAL(311, 9),  // "on_return"
        QT_MOC_LITERAL(321, 14),  // "slot_send_task"
        QT_MOC_LITERAL(336, 17),  // "slot_request_sort"
        QT_MOC_LITERAL(354, 23),  // "slot_request_lookmystat"
        QT_MOC_LITERAL(378, 24),  // "slot_request_lookallstat"
        QT_MOC_LITERAL(403, 15),  // "slot_stat_error"
        QT_MOC_LITERAL(419, 20),  // "slot_received_mystat"
        QT_MOC_LITERAL(440, 21)   // "slot_received_allstat"
    },
    "MainWindow",
    "send_task",
    "",
    "sort_request_main",
    "request_lookmystat_main",
    "request_lookallstat_main",
    "request_sort_main",
    "signal_stat_error",
    "signal_received_mystat",
    "signal_received_allstat",
    "on_pushButton_Exit_clicked",
    "on_pushButton_Task1_clicked",
    "on_pushButton_Task2_clicked",
    "on_pushButton_Task3_clicked",
    "on_pushButton_Stats_clicked",
    "on_return",
    "slot_send_task",
    "slot_request_sort",
    "slot_request_lookmystat",
    "slot_request_lookallstat",
    "slot_stat_error",
    "slot_received_mystat",
    "slot_received_allstat"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  140,    2, 0x06,    1 /* Public */,
       3,    0,  145,    2, 0x06,    4 /* Public */,
       4,    0,  146,    2, 0x06,    5 /* Public */,
       5,    0,  147,    2, 0x06,    6 /* Public */,
       6,    1,  148,    2, 0x06,    7 /* Public */,
       7,    1,  151,    2, 0x06,    9 /* Public */,
       8,    3,  154,    2, 0x06,   11 /* Public */,
       9,    4,  161,    2, 0x06,   15 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  170,    2, 0x08,   20 /* Private */,
      11,    0,  171,    2, 0x08,   21 /* Private */,
      12,    0,  172,    2, 0x08,   22 /* Private */,
      13,    0,  173,    2, 0x08,   23 /* Private */,
      14,    0,  174,    2, 0x08,   24 /* Private */,
      15,    0,  175,    2, 0x0a,   25 /* Public */,
      16,    2,  176,    2, 0x0a,   26 /* Public */,
      17,    1,  181,    2, 0x0a,   29 /* Public */,
      18,    0,  184,    2, 0x0a,   31 /* Public */,
      19,    0,  185,    2, 0x0a,   32 /* Public */,
      20,    1,  186,    2, 0x0a,   33 /* Public */,
      21,    3,  189,    2, 0x0a,   35 /* Public */,
      22,    4,  196,    2, 0x0a,   39 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,    2,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'send_task'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'sort_request_main'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'request_lookmystat_main'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'request_lookallstat_main'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'request_sort_main'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signal_stat_error'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'signal_received_mystat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'signal_received_allstat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_pushButton_Exit_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Task1_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Task2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Task3_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Stats_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_return'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_send_task'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slot_request_sort'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slot_request_lookmystat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_request_lookallstat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'slot_stat_error'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'slot_received_mystat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'slot_received_allstat'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->send_task((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 1: _t->sort_request_main(); break;
        case 2: _t->request_lookmystat_main(); break;
        case 3: _t->request_lookallstat_main(); break;
        case 4: _t->request_sort_main((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->signal_stat_error((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->signal_received_mystat((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 7: _t->signal_received_allstat((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        case 8: _t->on_pushButton_Exit_clicked(); break;
        case 9: _t->on_pushButton_Task1_clicked(); break;
        case 10: _t->on_pushButton_Task2_clicked(); break;
        case 11: _t->on_pushButton_Task3_clicked(); break;
        case 12: _t->on_pushButton_Stats_clicked(); break;
        case 13: _t->on_return(); break;
        case 14: _t->slot_send_task((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 15: _t->slot_request_sort((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 16: _t->slot_request_lookmystat(); break;
        case 17: _t->slot_request_lookallstat(); break;
        case 18: _t->slot_stat_error((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 19: _t->slot_received_mystat((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3]))); break;
        case 20: _t->slot_received_allstat((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(int , QString );
            if (_t _q_method = &MainWindow::send_task; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::sort_request_main; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::request_lookmystat_main; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::request_lookallstat_main; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (_t _q_method = &MainWindow::request_sort_main; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (_t _q_method = &MainWindow::signal_stat_error; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(int , int , int );
            if (_t _q_method = &MainWindow::signal_received_mystat; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString , QString , QString , QString );
            if (_t _q_method = &MainWindow::signal_received_allstat; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::send_task(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::sort_request_main()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::request_lookmystat_main()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void MainWindow::request_lookallstat_main()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MainWindow::request_sort_main(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainWindow::signal_stat_error(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainWindow::signal_received_mystat(int _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainWindow::signal_received_allstat(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP

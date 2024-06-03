/****************************************************************************
** Meta object code from reading C++ file 'functions_for_client.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../functions_for_client.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'functions_for_client.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSfunctions_for_clientENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSfunctions_for_clientENDCLASS = QtMocHelpers::stringData(
    "functions_for_client",
    "on_auth_ok",
    "",
    "on_final_auth",
    "is_auth",
    "login",
    "password",
    "on_reg",
    "email",
    "task_send",
    "i",
    "text",
    "final_auth",
    "msg_resolve",
    "msg",
    "on_request_lookmystat_func",
    "on_request_lookallstat_func",
    "on_request_sort_func"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSfunctions_for_clientENDCLASS_t {
    uint offsetsAndSizes[36];
    char stringdata0[21];
    char stringdata1[11];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[8];
    char stringdata5[6];
    char stringdata6[9];
    char stringdata7[7];
    char stringdata8[6];
    char stringdata9[10];
    char stringdata10[2];
    char stringdata11[5];
    char stringdata12[11];
    char stringdata13[12];
    char stringdata14[4];
    char stringdata15[27];
    char stringdata16[28];
    char stringdata17[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSfunctions_for_clientENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSfunctions_for_clientENDCLASS_t qt_meta_stringdata_CLASSfunctions_for_clientENDCLASS = {
    {
        QT_MOC_LITERAL(0, 20),  // "functions_for_client"
        QT_MOC_LITERAL(21, 10),  // "on_auth_ok"
        QT_MOC_LITERAL(32, 0),  // ""
        QT_MOC_LITERAL(33, 13),  // "on_final_auth"
        QT_MOC_LITERAL(47, 7),  // "is_auth"
        QT_MOC_LITERAL(55, 5),  // "login"
        QT_MOC_LITERAL(61, 8),  // "password"
        QT_MOC_LITERAL(70, 6),  // "on_reg"
        QT_MOC_LITERAL(77, 5),  // "email"
        QT_MOC_LITERAL(83, 9),  // "task_send"
        QT_MOC_LITERAL(93, 1),  // "i"
        QT_MOC_LITERAL(95, 4),  // "text"
        QT_MOC_LITERAL(100, 10),  // "final_auth"
        QT_MOC_LITERAL(111, 11),  // "msg_resolve"
        QT_MOC_LITERAL(123, 3),  // "msg"
        QT_MOC_LITERAL(127, 26),  // "on_request_lookmystat_func"
        QT_MOC_LITERAL(154, 27),  // "on_request_lookallstat_func"
        QT_MOC_LITERAL(182, 20)   // "on_request_sort_func"
    },
    "functions_for_client",
    "on_auth_ok",
    "",
    "on_final_auth",
    "is_auth",
    "login",
    "password",
    "on_reg",
    "email",
    "task_send",
    "i",
    "text",
    "final_auth",
    "msg_resolve",
    "msg",
    "on_request_lookmystat_func",
    "on_request_lookallstat_func",
    "on_request_sort_func"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSfunctions_for_clientENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,
       3,    1,   75,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    2,   78,    2, 0x0a,    4 /* Public */,
       7,    3,   83,    2, 0x0a,    7 /* Public */,
       9,    2,   90,    2, 0x0a,   11 /* Public */,
      12,    0,   95,    2, 0x0a,   14 /* Public */,
      13,    1,   96,    2, 0x0a,   15 /* Public */,
      15,    0,   99,    2, 0x0a,   17 /* Public */,
      16,    0,  100,    2, 0x0a,   18 /* Public */,
      17,    1,  101,    2, 0x0a,   19 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

Q_CONSTINIT const QMetaObject functions_for_client::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSfunctions_for_clientENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSfunctions_for_clientENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSfunctions_for_clientENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<functions_for_client, std::true_type>,
        // method 'on_auth_ok'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_final_auth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'is_auth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_reg'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'task_send'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'final_auth'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'msg_resolve'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_request_lookmystat_func'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_request_lookallstat_func'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_request_sort_func'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void functions_for_client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<functions_for_client *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_auth_ok(); break;
        case 1: _t->on_final_auth((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->is_auth((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->on_reg((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[3]))); break;
        case 4: _t->task_send((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 5: _t->final_auth(); break;
        case 6: _t->msg_resolve((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 7: _t->on_request_lookmystat_func(); break;
        case 8: _t->on_request_lookallstat_func(); break;
        case 9: _t->on_request_sort_func((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (functions_for_client::*)();
            if (_t _q_method = &functions_for_client::on_auth_ok; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (functions_for_client::*)(QString );
            if (_t _q_method = &functions_for_client::on_final_auth; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *functions_for_client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *functions_for_client::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSfunctions_for_clientENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int functions_for_client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void functions_for_client::on_auth_ok()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void functions_for_client::on_final_auth(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP

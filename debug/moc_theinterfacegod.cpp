/****************************************************************************
** Meta object code from reading C++ file 'theinterfacegod.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../theinterfacegod.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'theinterfacegod.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_theInterfaceGod_t {
    QByteArrayData data[9];
    char stringdata0[116];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_theInterfaceGod_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_theInterfaceGod_t qt_meta_stringdata_theInterfaceGod = {
    {
QT_MOC_LITERAL(0, 0, 15), // "theInterfaceGod"
QT_MOC_LITERAL(1, 16, 23), // "SIG_regenerateFrameList"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 8), // "duration"
QT_MOC_LITERAL(4, 50, 13), // "frameDuration"
QT_MOC_LITERAL(5, 64, 13), // "SIG_playFrame"
QT_MOC_LITERAL(6, 78, 7), // "frameNo"
QT_MOC_LITERAL(7, 86, 19), // "regenerateFrameList"
QT_MOC_LITERAL(8, 106, 9) // "playFrame"

    },
    "theInterfaceGod\0SIG_regenerateFrameList\0"
    "\0duration\0frameDuration\0SIG_playFrame\0"
    "frameNo\0regenerateFrameList\0playFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_theInterfaceGod[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    1,   39,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       7,    2,   42,    2, 0x02 /* Public */,
       8,    1,   47,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // methods: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void theInterfaceGod::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        theInterfaceGod *_t = static_cast<theInterfaceGod *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_regenerateFrameList((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 1: _t->SIG_playFrame((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->regenerateFrameList((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        case 3: _t->playFrame((*reinterpret_cast< const int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (theInterfaceGod::*)(const int & , const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&theInterfaceGod::SIG_regenerateFrameList)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (theInterfaceGod::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&theInterfaceGod::SIG_playFrame)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject theInterfaceGod::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_theInterfaceGod.data,
      qt_meta_data_theInterfaceGod,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *theInterfaceGod::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *theInterfaceGod::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_theInterfaceGod.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int theInterfaceGod::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void theInterfaceGod::SIG_regenerateFrameList(const int & _t1, const int & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void theInterfaceGod::SIG_playFrame(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

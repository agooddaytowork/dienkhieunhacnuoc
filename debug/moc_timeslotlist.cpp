/****************************************************************************
** Meta object code from reading C++ file 'timeslotlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../timeslotlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timeslotlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_timeSlotList_t {
    QByteArrayData data[13];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_timeSlotList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_timeSlotList_t qt_meta_stringdata_timeSlotList = {
    {
QT_MOC_LITERAL(0, 0, 12), // "timeSlotList"
QT_MOC_LITERAL(1, 13, 15), // "preItemAppended"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 16), // "postItemAppended"
QT_MOC_LITERAL(4, 47, 14), // "preItemRemoved"
QT_MOC_LITERAL(5, 62, 5), // "index"
QT_MOC_LITERAL(6, 68, 15), // "postItemRemoved"
QT_MOC_LITERAL(7, 84, 10), // "appendItem"
QT_MOC_LITERAL(8, 95, 5), // "group"
QT_MOC_LITERAL(9, 101, 6), // "fromMs"
QT_MOC_LITERAL(10, 108, 4), // "toMs"
QT_MOC_LITERAL(11, 113, 11), // "removeItems"
QT_MOC_LITERAL(12, 125, 2) // "id"

    },
    "timeSlotList\0preItemAppended\0\0"
    "postItemAppended\0preItemRemoved\0index\0"
    "postItemRemoved\0appendItem\0group\0"
    "fromMs\0toMs\0removeItems\0id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_timeSlotList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    1,   46,    2, 0x06 /* Public */,
       6,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    3,   50,    2, 0x0a /* Public */,
      11,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UInt, QMetaType::UInt,    8,    9,   10,
    QMetaType::Void, QMetaType::UInt,   12,

       0        // eod
};

void timeSlotList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        timeSlotList *_t = static_cast<timeSlotList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->preItemAppended(); break;
        case 1: _t->postItemAppended(); break;
        case 2: _t->preItemRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->postItemRemoved(); break;
        case 4: _t->appendItem((*reinterpret_cast< const quint8(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const quint32(*)>(_a[3]))); break;
        case 5: _t->removeItems((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (timeSlotList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&timeSlotList::preItemAppended)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (timeSlotList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&timeSlotList::postItemAppended)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (timeSlotList::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&timeSlotList::preItemRemoved)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (timeSlotList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&timeSlotList::postItemRemoved)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject timeSlotList::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_timeSlotList.data,
      qt_meta_data_timeSlotList,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *timeSlotList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *timeSlotList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_timeSlotList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int timeSlotList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void timeSlotList::preItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void timeSlotList::postItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void timeSlotList::preItemRemoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void timeSlotList::postItemRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
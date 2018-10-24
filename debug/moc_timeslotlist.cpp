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
    QByteArrayData data[18];
    char stringdata0[209];
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
QT_MOC_LITERAL(7, 84, 19), // "timeSlotItemChanged"
QT_MOC_LITERAL(8, 104, 12), // "timeSlotItem"
QT_MOC_LITERAL(9, 117, 4), // "item"
QT_MOC_LITERAL(10, 122, 19), // "timeSlotItemRemoved"
QT_MOC_LITERAL(11, 142, 10), // "appendItem"
QT_MOC_LITERAL(12, 153, 5), // "group"
QT_MOC_LITERAL(13, 159, 6), // "fromMs"
QT_MOC_LITERAL(14, 166, 4), // "toMs"
QT_MOC_LITERAL(15, 171, 11), // "removeItems"
QT_MOC_LITERAL(16, 183, 2), // "id"
QT_MOC_LITERAL(17, 186, 22) // "timeSlotCollisionCheck"

    },
    "timeSlotList\0preItemAppended\0\0"
    "postItemAppended\0preItemRemoved\0index\0"
    "postItemRemoved\0timeSlotItemChanged\0"
    "timeSlotItem\0item\0timeSlotItemRemoved\0"
    "appendItem\0group\0fromMs\0toMs\0removeItems\0"
    "id\0timeSlotCollisionCheck"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_timeSlotList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    1,   61,    2, 0x06 /* Public */,
       6,    0,   64,    2, 0x06 /* Public */,
       7,    1,   65,    2, 0x06 /* Public */,
      10,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    3,   71,    2, 0x0a /* Public */,
      15,    1,   78,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      17,    1,   81,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::UInt, QMetaType::UInt,   12,   13,   14,
    QMetaType::Void, QMetaType::UInt,   16,

 // methods: parameters
    QMetaType::UInt, QMetaType::UInt,   16,

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
        case 4: _t->timeSlotItemChanged((*reinterpret_cast< const timeSlotItem(*)>(_a[1]))); break;
        case 5: _t->timeSlotItemRemoved((*reinterpret_cast< const timeSlotItem(*)>(_a[1]))); break;
        case 6: _t->appendItem((*reinterpret_cast< const quint8(*)>(_a[1])),(*reinterpret_cast< const quint32(*)>(_a[2])),(*reinterpret_cast< const quint32(*)>(_a[3]))); break;
        case 7: _t->removeItems((*reinterpret_cast< const quint32(*)>(_a[1]))); break;
        case 8: { quint32 _r = _t->timeSlotCollisionCheck((*reinterpret_cast< const quint32(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< quint32*>(_a[0]) = std::move(_r); }  break;
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
        {
            using _t = void (timeSlotList::*)(const timeSlotItem & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&timeSlotList::timeSlotItemChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (timeSlotList::*)(const timeSlotItem & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&timeSlotList::timeSlotItemRemoved)) {
                *result = 5;
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
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

// SIGNAL 4
void timeSlotList::timeSlotItemChanged(const timeSlotItem & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void timeSlotList::timeSlotItemRemoved(const timeSlotItem & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

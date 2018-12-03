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
#include <QtCore/QVector>
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
    QByteArrayData data[28];
    char stringdata0[384];
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
QT_MOC_LITERAL(11, 142, 23), // "gui_timeSLotItemChanged"
QT_MOC_LITERAL(12, 166, 22), // "SIG_returnTimeSlotList"
QT_MOC_LITERAL(13, 189, 5), // "group"
QT_MOC_LITERAL(14, 195, 21), // "QVector<timeSlotItem>"
QT_MOC_LITERAL(15, 217, 4), // "list"
QT_MOC_LITERAL(16, 222, 21), // "SIG_NotifyListChanged"
QT_MOC_LITERAL(17, 244, 10), // "appendItem"
QT_MOC_LITERAL(18, 255, 6), // "fromMs"
QT_MOC_LITERAL(19, 262, 4), // "toMs"
QT_MOC_LITERAL(20, 267, 11), // "removeItems"
QT_MOC_LITERAL(21, 279, 2), // "id"
QT_MOC_LITERAL(22, 282, 27), // "timeSlotListImportedHandler"
QT_MOC_LITERAL(23, 310, 17), // "clearTimeSlotList"
QT_MOC_LITERAL(24, 328, 22), // "timeSlotCollisionCheck"
QT_MOC_LITERAL(25, 351, 16), // "getCollisionSide"
QT_MOC_LITERAL(26, 368, 5), // "count"
QT_MOC_LITERAL(27, 374, 9) // "lastIndex"

    },
    "timeSlotList\0preItemAppended\0\0"
    "postItemAppended\0preItemRemoved\0index\0"
    "postItemRemoved\0timeSlotItemChanged\0"
    "timeSlotItem\0item\0timeSlotItemRemoved\0"
    "gui_timeSLotItemChanged\0SIG_returnTimeSlotList\0"
    "group\0QVector<timeSlotItem>\0list\0"
    "SIG_NotifyListChanged\0appendItem\0"
    "fromMs\0toMs\0removeItems\0id\0"
    "timeSlotListImportedHandler\0"
    "clearTimeSlotList\0timeSlotCollisionCheck\0"
    "getCollisionSide\0count\0lastIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_timeSlotList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    1,  101,    2, 0x06 /* Public */,
       6,    0,  104,    2, 0x06 /* Public */,
       7,    1,  105,    2, 0x06 /* Public */,
      10,    1,  108,    2, 0x06 /* Public */,
      11,    0,  111,    2, 0x06 /* Public */,
      12,    2,  112,    2, 0x06 /* Public */,
      16,    0,  117,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    3,  118,    2, 0x0a /* Public */,
      20,    1,  125,    2, 0x0a /* Public */,
      22,    2,  128,    2, 0x0a /* Public */,
      23,    0,  133,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      24,    1,  134,    2, 0x02 /* Public */,
      25,    0,  137,    2, 0x02 /* Public */,
      26,    0,  138,    2, 0x02 /* Public */,
      27,    0,  139,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 14,   13,   15,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::Int, QMetaType::Int,   13,   18,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 14,   13,   15,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int, QMetaType::Int,   21,
    QMetaType::Bool,
    QMetaType::Int,
    QMetaType::Int,

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
        case 6: _t->gui_timeSLotItemChanged(); break;
        case 7: _t->SIG_returnTimeSlotList((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QVector<timeSlotItem>(*)>(_a[2]))); break;
        case 8: _t->SIG_NotifyListChanged(); break;
        case 9: _t->appendItem((*reinterpret_cast< const quint8(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const int(*)>(_a[3]))); break;
        case 10: _t->removeItems((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 11: _t->timeSlotListImportedHandler((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QVector<timeSlotItem>(*)>(_a[2]))); break;
        case 12: _t->clearTimeSlotList(); break;
        case 13: { int _r = _t->timeSlotCollisionCheck((*reinterpret_cast< const int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 14: { bool _r = _t->getCollisionSide();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 15: { int _r = _t->count();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 16: { int _r = _t->lastIndex();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
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
        {
            using _t = void (timeSlotList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&timeSlotList::gui_timeSLotItemChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (timeSlotList::*)(const int & , const QVector<timeSlotItem> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&timeSlotList::SIG_returnTimeSlotList)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (timeSlotList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&timeSlotList::SIG_NotifyListChanged)) {
                *result = 8;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
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

// SIGNAL 6
void timeSlotList::gui_timeSLotItemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void timeSlotList::SIG_returnTimeSlotList(const int & _t1, const QVector<timeSlotItem> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void timeSlotList::SIG_NotifyListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

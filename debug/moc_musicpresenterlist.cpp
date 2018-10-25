/****************************************************************************
** Meta object code from reading C++ file 'musicpresenterlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../musicpresenterlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'musicpresenterlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MusicPresenterList_t {
    QByteArrayData data[20];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MusicPresenterList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MusicPresenterList_t qt_meta_stringdata_MusicPresenterList = {
    {
QT_MOC_LITERAL(0, 0, 18), // "MusicPresenterList"
QT_MOC_LITERAL(1, 19, 15), // "preItemAppended"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "postItemAppended"
QT_MOC_LITERAL(4, 53, 14), // "preItemRemoved"
QT_MOC_LITERAL(5, 68, 5), // "index"
QT_MOC_LITERAL(6, 74, 15), // "postItemRemoved"
QT_MOC_LITERAL(7, 90, 22), // "itemChangedFromBackend"
QT_MOC_LITERAL(8, 113, 10), // "appendItem"
QT_MOC_LITERAL(9, 124, 5), // "group"
QT_MOC_LITERAL(10, 130, 4), // "xPos"
QT_MOC_LITERAL(11, 135, 4), // "yPos"
QT_MOC_LITERAL(12, 140, 15), // "appenItemGroup6"
QT_MOC_LITERAL(13, 156, 3), // "odd"
QT_MOC_LITERAL(14, 160, 11), // "removeItems"
QT_MOC_LITERAL(15, 172, 2), // "id"
QT_MOC_LITERAL(16, 175, 5), // "clear"
QT_MOC_LITERAL(17, 181, 19), // "frameChangedHandler"
QT_MOC_LITERAL(18, 201, 14), // "PresenterFrame"
QT_MOC_LITERAL(19, 216, 5) // "frame"

    },
    "MusicPresenterList\0preItemAppended\0\0"
    "postItemAppended\0preItemRemoved\0index\0"
    "postItemRemoved\0itemChangedFromBackend\0"
    "appendItem\0group\0xPos\0yPos\0appenItemGroup6\0"
    "odd\0removeItems\0id\0clear\0frameChangedHandler\0"
    "PresenterFrame\0frame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MusicPresenterList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    1,   66,    2, 0x06 /* Public */,
       6,    0,   69,    2, 0x06 /* Public */,
       7,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    3,   73,    2, 0x0a /* Public */,
      12,    3,   80,    2, 0x0a /* Public */,
      14,    1,   87,    2, 0x0a /* Public */,
      16,    0,   90,    2, 0x0a /* Public */,
      17,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::UChar, QMetaType::Int, QMetaType::Int,    9,   10,   11,
    QMetaType::Void, QMetaType::Bool, QMetaType::Int, QMetaType::Int,   13,   10,   11,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 18,   19,

       0        // eod
};

void MusicPresenterList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MusicPresenterList *_t = static_cast<MusicPresenterList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->preItemAppended(); break;
        case 1: _t->postItemAppended(); break;
        case 2: _t->preItemRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->postItemRemoved(); break;
        case 4: _t->itemChangedFromBackend((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->appendItem((*reinterpret_cast< const quint8(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->appenItemGroup6((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->removeItems((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 8: _t->clear(); break;
        case 9: _t->frameChangedHandler((*reinterpret_cast< const PresenterFrame(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MusicPresenterList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicPresenterList::preItemAppended)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MusicPresenterList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicPresenterList::postItemAppended)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MusicPresenterList::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicPresenterList::preItemRemoved)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MusicPresenterList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicPresenterList::postItemRemoved)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MusicPresenterList::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MusicPresenterList::itemChangedFromBackend)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MusicPresenterList::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MusicPresenterList.data,
      qt_meta_data_MusicPresenterList,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MusicPresenterList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MusicPresenterList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MusicPresenterList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int MusicPresenterList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void MusicPresenterList::preItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void MusicPresenterList::postItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MusicPresenterList::preItemRemoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MusicPresenterList::postItemRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void MusicPresenterList::itemChangedFromBackend(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

/****************************************************************************
** Meta object code from reading C++ file 'presenterframelist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../presenterframelist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'presenterframelist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PresenterFrameList_t {
    QByteArrayData data[20];
    char stringdata0[311];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PresenterFrameList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PresenterFrameList_t qt_meta_stringdata_PresenterFrameList = {
    {
QT_MOC_LITERAL(0, 0, 18), // "PresenterFrameList"
QT_MOC_LITERAL(1, 19, 18), // "notifyFrameChanged"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 14), // "PresenterFrame"
QT_MOC_LITERAL(4, 54, 5), // "frame"
QT_MOC_LITERAL(5, 60, 41), // "SIG_SerialFrameBuffer_regener..."
QT_MOC_LITERAL(6, 102, 10), // "totalFrame"
QT_MOC_LITERAL(7, 113, 40), // "SIG_SerialFrameBuffer_notifyF..."
QT_MOC_LITERAL(8, 154, 5), // "group"
QT_MOC_LITERAL(9, 160, 7), // "frameNo"
QT_MOC_LITERAL(10, 168, 8), // "theFrame"
QT_MOC_LITERAL(11, 177, 26), // "SIG_frameListReconstructed"
QT_MOC_LITERAL(12, 204, 15), // "timeSlotChanged"
QT_MOC_LITERAL(13, 220, 12), // "timeSlotItem"
QT_MOC_LITERAL(14, 233, 8), // "timeSlot"
QT_MOC_LITERAL(15, 242, 15), // "timeSlotRemoved"
QT_MOC_LITERAL(16, 258, 9), // "playFrame"
QT_MOC_LITERAL(17, 268, 19), // "regenerateFrameList"
QT_MOC_LITERAL(18, 288, 8), // "Duration"
QT_MOC_LITERAL(19, 297, 13) // "FrameDuration"

    },
    "PresenterFrameList\0notifyFrameChanged\0"
    "\0PresenterFrame\0frame\0"
    "SIG_SerialFrameBuffer_regenerateFrameList\0"
    "totalFrame\0SIG_SerialFrameBuffer_notifyFrameChanged\0"
    "group\0frameNo\0theFrame\0"
    "SIG_frameListReconstructed\0timeSlotChanged\0"
    "timeSlotItem\0timeSlot\0timeSlotRemoved\0"
    "playFrame\0regenerateFrameList\0Duration\0"
    "FrameDuration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PresenterFrameList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       7,    3,   60,    2, 0x06 /* Public */,
      11,    0,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,   68,    2, 0x0a /* Public */,
      15,    1,   71,    2, 0x0a /* Public */,
      16,    1,   74,    2, 0x0a /* Public */,
      17,    2,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 3,    8,    9,   10,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   18,   19,

       0        // eod
};

void PresenterFrameList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PresenterFrameList *_t = static_cast<PresenterFrameList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->notifyFrameChanged((*reinterpret_cast< const PresenterFrame(*)>(_a[1]))); break;
        case 1: _t->SIG_SerialFrameBuffer_regenerateFrameList((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 2: _t->SIG_SerialFrameBuffer_notifyFrameChanged((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2])),(*reinterpret_cast< const PresenterFrame(*)>(_a[3]))); break;
        case 3: _t->SIG_frameListReconstructed(); break;
        case 4: _t->timeSlotChanged((*reinterpret_cast< const timeSlotItem(*)>(_a[1]))); break;
        case 5: _t->timeSlotRemoved((*reinterpret_cast< const timeSlotItem(*)>(_a[1]))); break;
        case 6: _t->playFrame((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 7: _t->regenerateFrameList((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PresenterFrameList::*)(const PresenterFrame & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresenterFrameList::notifyFrameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PresenterFrameList::*)(const int & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresenterFrameList::SIG_SerialFrameBuffer_regenerateFrameList)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PresenterFrameList::*)(const int & , const int & , const PresenterFrame & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresenterFrameList::SIG_SerialFrameBuffer_notifyFrameChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (PresenterFrameList::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PresenterFrameList::SIG_frameListReconstructed)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PresenterFrameList::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PresenterFrameList.data,
      qt_meta_data_PresenterFrameList,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PresenterFrameList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PresenterFrameList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PresenterFrameList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PresenterFrameList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void PresenterFrameList::notifyFrameChanged(const PresenterFrame & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PresenterFrameList::SIG_SerialFrameBuffer_regenerateFrameList(const int & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PresenterFrameList::SIG_SerialFrameBuffer_notifyFrameChanged(const int & _t1, const int & _t2, const PresenterFrame & _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PresenterFrameList::SIG_frameListReconstructed()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

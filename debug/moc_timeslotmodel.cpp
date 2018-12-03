/****************************************************************************
** Meta object code from reading C++ file 'timeslotmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../timeslotmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timeslotmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_timeSlotModel_t {
    QByteArrayData data[13];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_timeSlotModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_timeSlotModel_t qt_meta_stringdata_timeSlotModel = {
    {
QT_MOC_LITERAL(0, 0, 13), // "timeSlotModel"
QT_MOC_LITERAL(1, 14, 11), // "sizeChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "listChanged"
QT_MOC_LITERAL(4, 39, 23), // "gui_timeSlotItemChanged"
QT_MOC_LITERAL(5, 63, 15), // "getDataPerIndex"
QT_MOC_LITERAL(6, 79, 5), // "index"
QT_MOC_LITERAL(7, 85, 10), // "RoleString"
QT_MOC_LITERAL(8, 96, 15), // "setDataPerIndex"
QT_MOC_LITERAL(9, 112, 5), // "value"
QT_MOC_LITERAL(10, 118, 4), // "list"
QT_MOC_LITERAL(11, 123, 13), // "timeSlotList*"
QT_MOC_LITERAL(12, 137, 4) // "size"

    },
    "timeSlotModel\0sizeChanged\0\0listChanged\0"
    "gui_timeSlotItemChanged\0getDataPerIndex\0"
    "index\0RoleString\0setDataPerIndex\0value\0"
    "list\0timeSlotList*\0size"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_timeSlotModel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   54, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    2,   42,    2, 0x02 /* Public */,
       8,    3,   47,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::QVariant, QMetaType::Int, QMetaType::QByteArray,    6,    7,
    QMetaType::Bool, QMetaType::Int, QMetaType::QByteArray, QMetaType::QVariant,    6,    7,    9,

 // properties: name, type, flags
      10, 0x80000000 | 11, 0x0049510b,
      12, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       1,
       0,

       0        // eod
};

void timeSlotModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        timeSlotModel *_t = static_cast<timeSlotModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sizeChanged(); break;
        case 1: _t->listChanged(); break;
        case 2: _t->gui_timeSlotItemChanged(); break;
        case 3: { QVariant _r = _t->getDataPerIndex((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QVariant*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->setDataPerIndex((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2])),(*reinterpret_cast< const QVariant(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (timeSlotModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&timeSlotModel::sizeChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (timeSlotModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&timeSlotModel::listChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (timeSlotModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&timeSlotModel::gui_timeSlotItemChanged)) {
                *result = 2;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< timeSlotList* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        timeSlotModel *_t = static_cast<timeSlotModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< timeSlotList**>(_v) = _t->list(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->size(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        timeSlotModel *_t = static_cast<timeSlotModel *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setList(*reinterpret_cast< timeSlotList**>(_v)); break;
        case 1: _t->setSize(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject timeSlotModel::staticMetaObject = {
    { &QAbstractListModel::staticMetaObject, qt_meta_stringdata_timeSlotModel.data,
      qt_meta_data_timeSlotModel,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *timeSlotModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *timeSlotModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_timeSlotModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int timeSlotModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void timeSlotModel::sizeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void timeSlotModel::listChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void timeSlotModel::gui_timeSlotItemChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

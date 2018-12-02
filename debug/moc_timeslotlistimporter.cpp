/****************************************************************************
** Meta object code from reading C++ file 'timeslotlistimporter.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../timeslotlistimporter.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timeslotlistimporter.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TimeSlotListImporter_t {
    QByteArrayData data[6];
    char stringdata0[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TimeSlotListImporter_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TimeSlotListImporter_t qt_meta_stringdata_TimeSlotListImporter = {
    {
QT_MOC_LITERAL(0, 0, 20), // "TimeSlotListImporter"
QT_MOC_LITERAL(1, 21, 22), // "SIG_updateTimeSlotSlit"
QT_MOC_LITERAL(2, 44, 0), // ""
QT_MOC_LITERAL(3, 45, 5), // "group"
QT_MOC_LITERAL(4, 51, 21), // "QVector<timeSlotItem>"
QT_MOC_LITERAL(5, 73, 4) // "list"

    },
    "TimeSlotListImporter\0SIG_updateTimeSlotSlit\0"
    "\0group\0QVector<timeSlotItem>\0list"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TimeSlotListImporter[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,

       0        // eod
};

void TimeSlotListImporter::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TimeSlotListImporter *_t = static_cast<TimeSlotListImporter *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SIG_updateTimeSlotSlit((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const QVector<timeSlotItem>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TimeSlotListImporter::*)(const int & , const QVector<timeSlotItem> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TimeSlotListImporter::SIG_updateTimeSlotSlit)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TimeSlotListImporter::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TimeSlotListImporter.data,
      qt_meta_data_TimeSlotListImporter,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TimeSlotListImporter::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TimeSlotListImporter::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TimeSlotListImporter.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int TimeSlotListImporter::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void TimeSlotListImporter::SIG_updateTimeSlotSlit(const int & _t1, const QVector<timeSlotItem> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

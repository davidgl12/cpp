/****************************************************************************
** Meta object code from reading C++ file 'convertidornumerico.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../appConvertidorNumerico/convertidornumerico.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'convertidornumerico.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_convertidornumerico_t {
    const uint offsetsAndSize[16];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_convertidornumerico_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_convertidornumerico_t qt_meta_stringdata_convertidornumerico = {
    {
QT_MOC_LITERAL(0, 19), // "convertidornumerico"
QT_MOC_LITERAL(20, 10), // "decChanged"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 10), // "hexChanged"
QT_MOC_LITERAL(43, 10), // "binChanged"
QT_MOC_LITERAL(54, 6), // "setDec"
QT_MOC_LITERAL(61, 6), // "setHex"
QT_MOC_LITERAL(68, 6) // "setBin"

    },
    "convertidornumerico\0decChanged\0\0"
    "hexChanged\0binChanged\0setDec\0setHex\0"
    "setBin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_convertidornumerico[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x06,    1 /* Public */,
       3,    1,   53,    2, 0x06,    3 /* Public */,
       4,    1,   56,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   59,    2, 0x0a,    7 /* Public */,
       6,    1,   62,    2, 0x0a,    9 /* Public */,
       7,    1,   65,    2, 0x0a,   11 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void convertidornumerico::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<convertidornumerico *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->decChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->hexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->binChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setDec((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setHex((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->setBin((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (convertidornumerico::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convertidornumerico::decChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (convertidornumerico::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convertidornumerico::hexChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (convertidornumerico::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&convertidornumerico::binChanged)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject convertidornumerico::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_convertidornumerico.offsetsAndSize,
    qt_meta_data_convertidornumerico,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_convertidornumerico_t
, QtPrivate::TypeAndForceComplete<convertidornumerico, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>


>,
    nullptr
} };


const QMetaObject *convertidornumerico::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *convertidornumerico::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_convertidornumerico.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int convertidornumerico::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void convertidornumerico::decChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void convertidornumerico::hexChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void convertidornumerico::binChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

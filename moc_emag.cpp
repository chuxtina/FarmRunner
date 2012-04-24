/****************************************************************************
** Meta object code from reading C++ file 'emag.h'
**
** Created: Mon Apr 23 18:56:25 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "emag.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'emag.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Emag[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,    6,    5,    5, 0x05,
      36,   30,    5,    5, 0x05,
      60,   54,    5,    5, 0x05,

 // slots: signature, parameters, type, tag, flags
      78,    5,    5,    5, 0x0a,
      90,    5,    5,    5, 0x0a,
     102,    5,    5,    5, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Emag[] = {
    "Emag\0\0score\0scoreChanged(int)\0level\0"
    "levelChanged(int)\0lives\0livesChanged(int)\0"
    "startGame()\0pauseGame()\0stopGame()\0"
};

void Emag::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Emag *_t = static_cast<Emag *>(_o);
        switch (_id) {
        case 0: _t->scoreChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->levelChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->livesChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->startGame(); break;
        case 4: _t->pauseGame(); break;
        case 5: _t->stopGame(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Emag::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Emag::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Emag,
      qt_meta_data_Emag, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Emag::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Emag::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Emag::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Emag))
        return static_cast<void*>(const_cast< Emag*>(this));
    return QWidget::qt_metacast(_clname);
}

int Emag::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Emag::scoreChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Emag::levelChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Emag::livesChanged(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE

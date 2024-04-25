/****************************************************************************
** Meta object code from reading C++ file 'widgetvar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../widgetvar/widgetvar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetvar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__WidgetVar_t {
    QByteArrayData data[19];
    char stringdata0[304];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_s21__WidgetVar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_s21__WidgetVar_t qt_meta_stringdata_s21__WidgetVar = {
    {
QT_MOC_LITERAL(0, 0, 14), // "s21::WidgetVar"
QT_MOC_LITERAL(1, 15, 12), // "WidgetUnTerm"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "WidgetVar*"
QT_MOC_LITERAL(4, 40, 11), // "this_widget"
QT_MOC_LITERAL(5, 52, 12), // "WidgetDelete"
QT_MOC_LITERAL(6, 65, 13), // "FormulaUpdate"
QT_MOC_LITERAL(7, 79, 11), // "NameClicked"
QT_MOC_LITERAL(8, 91, 14), // "LineEditSelect"
QT_MOC_LITERAL(9, 106, 10), // "QLineEdit*"
QT_MOC_LITERAL(10, 117, 4), // "line"
QT_MOC_LITERAL(11, 122, 23), // "PushButtonDeletePressed"
QT_MOC_LITERAL(12, 146, 24), // "PushButtonDeleteReleased"
QT_MOC_LITERAL(13, 171, 23), // "PushButtonDeleteClicked"
QT_MOC_LITERAL(14, 195, 21), // "PushButtonTypePressed"
QT_MOC_LITERAL(15, 217, 22), // "PushButtonTypeReleased"
QT_MOC_LITERAL(16, 240, 21), // "PushButtonTypeClicked"
QT_MOC_LITERAL(17, 262, 21), // "PushButtonNameClicked"
QT_MOC_LITERAL(18, 284, 19) // "LineEditTextChanged"

    },
    "s21::WidgetVar\0WidgetUnTerm\0\0WidgetVar*\0"
    "this_widget\0WidgetDelete\0FormulaUpdate\0"
    "NameClicked\0LineEditSelect\0QLineEdit*\0"
    "line\0PushButtonDeletePressed\0"
    "PushButtonDeleteReleased\0"
    "PushButtonDeleteClicked\0PushButtonTypePressed\0"
    "PushButtonTypeReleased\0PushButtonTypeClicked\0"
    "PushButtonNameClicked\0LineEditTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__WidgetVar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       5,    1,   82,    2, 0x06 /* Public */,
       6,    0,   85,    2, 0x06 /* Public */,
       7,    1,   86,    2, 0x06 /* Public */,
       8,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   92,    2, 0x08 /* Private */,
      12,    0,   93,    2, 0x08 /* Private */,
      13,    0,   94,    2, 0x08 /* Private */,
      14,    0,   95,    2, 0x08 /* Private */,
      15,    0,   96,    2, 0x08 /* Private */,
      16,    0,   97,    2, 0x08 /* Private */,
      17,    0,   98,    2, 0x08 /* Private */,
      18,    0,   99,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 9,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void s21::WidgetVar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetVar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->WidgetUnTerm((*reinterpret_cast< WidgetVar*(*)>(_a[1]))); break;
        case 1: _t->WidgetDelete((*reinterpret_cast< WidgetVar*(*)>(_a[1]))); break;
        case 2: _t->FormulaUpdate(); break;
        case 3: _t->NameClicked((*reinterpret_cast< WidgetVar*(*)>(_a[1]))); break;
        case 4: _t->LineEditSelect((*reinterpret_cast< QLineEdit*(*)>(_a[1]))); break;
        case 5: _t->PushButtonDeletePressed(); break;
        case 6: _t->PushButtonDeleteReleased(); break;
        case 7: _t->PushButtonDeleteClicked(); break;
        case 8: _t->PushButtonTypePressed(); break;
        case 9: _t->PushButtonTypeReleased(); break;
        case 10: _t->PushButtonTypeClicked(); break;
        case 11: _t->PushButtonNameClicked(); break;
        case 12: _t->LineEditTextChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WidgetVar* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WidgetVar* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WidgetVar* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLineEdit* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetVar::*)(WidgetVar * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetVar::WidgetUnTerm)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WidgetVar::*)(WidgetVar * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetVar::WidgetDelete)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WidgetVar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetVar::FormulaUpdate)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WidgetVar::*)(WidgetVar * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetVar::NameClicked)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (WidgetVar::*)(QLineEdit * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetVar::LineEditSelect)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject s21::WidgetVar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_s21__WidgetVar.data,
    qt_meta_data_s21__WidgetVar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *s21::WidgetVar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::WidgetVar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__WidgetVar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int s21::WidgetVar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void s21::WidgetVar::WidgetUnTerm(WidgetVar * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void s21::WidgetVar::WidgetDelete(WidgetVar * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void s21::WidgetVar::FormulaUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void s21::WidgetVar::NameClicked(WidgetVar * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void s21::WidgetVar::LineEditSelect(QLineEdit * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

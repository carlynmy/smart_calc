/****************************************************************************
** Meta object code from reading C++ file 'widgetfunc.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../widgetfunc/widgetfunc.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetfunc.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__WidgetFunc_t {
    QByteArrayData data[20];
    char stringdata0[378];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_s21__WidgetFunc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_s21__WidgetFunc_t qt_meta_stringdata_s21__WidgetFunc = {
    {
QT_MOC_LITERAL(0, 0, 15), // "s21::WidgetFunc"
QT_MOC_LITERAL(1, 16, 12), // "WidgetUnTerm"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 11), // "WidgetFunc*"
QT_MOC_LITERAL(4, 42, 11), // "this_widget"
QT_MOC_LITERAL(5, 54, 12), // "WidgetDelete"
QT_MOC_LITERAL(6, 67, 13), // "FormulaUpdate"
QT_MOC_LITERAL(7, 81, 21), // "PushButtonHidePressed"
QT_MOC_LITERAL(8, 103, 22), // "PushButtonHideReleased"
QT_MOC_LITERAL(9, 126, 21), // "PushButtonHideClicked"
QT_MOC_LITERAL(10, 148, 23), // "PushButtonDeletePressed"
QT_MOC_LITERAL(11, 172, 24), // "PushButtonDeleteReleased"
QT_MOC_LITERAL(12, 197, 23), // "PushButtonDeleteClicked"
QT_MOC_LITERAL(13, 221, 22), // "PushButtonColorPressed"
QT_MOC_LITERAL(14, 244, 23), // "PushButtonColorReleased"
QT_MOC_LITERAL(15, 268, 22), // "PushButtonColorClicked"
QT_MOC_LITERAL(16, 291, 21), // "PushButtonTypePressed"
QT_MOC_LITERAL(17, 313, 22), // "PushButtonTypeReleased"
QT_MOC_LITERAL(18, 336, 21), // "PushButtonTypeClicked"
QT_MOC_LITERAL(19, 358, 19) // "LineEditTextChanged"

    },
    "s21::WidgetFunc\0WidgetUnTerm\0\0WidgetFunc*\0"
    "this_widget\0WidgetDelete\0FormulaUpdate\0"
    "PushButtonHidePressed\0PushButtonHideReleased\0"
    "PushButtonHideClicked\0PushButtonDeletePressed\0"
    "PushButtonDeleteReleased\0"
    "PushButtonDeleteClicked\0PushButtonColorPressed\0"
    "PushButtonColorReleased\0PushButtonColorClicked\0"
    "PushButtonTypePressed\0PushButtonTypeReleased\0"
    "PushButtonTypeClicked\0LineEditTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__WidgetFunc[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       5,    1,   97,    2, 0x06 /* Public */,
       6,    0,  100,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  101,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    0,  103,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    0,  107,    2, 0x08 /* Private */,
      14,    0,  108,    2, 0x08 /* Private */,
      15,    0,  109,    2, 0x08 /* Private */,
      16,    0,  110,    2, 0x08 /* Private */,
      17,    0,  111,    2, 0x08 /* Private */,
      18,    0,  112,    2, 0x08 /* Private */,
      19,    0,  113,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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

void s21::WidgetFunc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetFunc *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->WidgetUnTerm((*reinterpret_cast< WidgetFunc*(*)>(_a[1]))); break;
        case 1: _t->WidgetDelete((*reinterpret_cast< WidgetFunc*(*)>(_a[1]))); break;
        case 2: _t->FormulaUpdate(); break;
        case 3: _t->PushButtonHidePressed(); break;
        case 4: _t->PushButtonHideReleased(); break;
        case 5: _t->PushButtonHideClicked(); break;
        case 6: _t->PushButtonDeletePressed(); break;
        case 7: _t->PushButtonDeleteReleased(); break;
        case 8: _t->PushButtonDeleteClicked(); break;
        case 9: _t->PushButtonColorPressed(); break;
        case 10: _t->PushButtonColorReleased(); break;
        case 11: _t->PushButtonColorClicked(); break;
        case 12: _t->PushButtonTypePressed(); break;
        case 13: _t->PushButtonTypeReleased(); break;
        case 14: _t->PushButtonTypeClicked(); break;
        case 15: _t->LineEditTextChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WidgetFunc* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WidgetFunc* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetFunc::*)(WidgetFunc * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetFunc::WidgetUnTerm)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WidgetFunc::*)(WidgetFunc * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetFunc::WidgetDelete)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WidgetFunc::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetFunc::FormulaUpdate)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject s21::WidgetFunc::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_s21__WidgetFunc.data,
    qt_meta_data_s21__WidgetFunc,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *s21::WidgetFunc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::WidgetFunc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__WidgetFunc.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int s21::WidgetFunc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void s21::WidgetFunc::WidgetUnTerm(WidgetFunc * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void s21::WidgetFunc::WidgetDelete(WidgetFunc * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void s21::WidgetFunc::FormulaUpdate()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

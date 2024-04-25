/****************************************************************************
** Meta object code from reading C++ file 'widgetlistwidgetitem.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../widgetlistwidget/widgetlistwidgetitem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetlistwidgetitem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_s21__WidgetListWidgetItem_t {
    QByteArrayData data[11];
    char stringdata0[125];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_s21__WidgetListWidgetItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_s21__WidgetListWidgetItem_t qt_meta_stringdata_s21__WidgetListWidgetItem = {
    {
QT_MOC_LITERAL(0, 0, 25), // "s21::WidgetListWidgetItem"
QT_MOC_LITERAL(1, 26, 12), // "DropEventEnd"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 21), // "WidgetListWidgetItem*"
QT_MOC_LITERAL(4, 62, 11), // "this_widget"
QT_MOC_LITERAL(5, 74, 11), // "ExcpectDrag"
QT_MOC_LITERAL(6, 86, 6), // "answer"
QT_MOC_LITERAL(7, 93, 10), // "StartTimer"
QT_MOC_LITERAL(8, 104, 4), // "msec"
QT_MOC_LITERAL(9, 109, 8), // "EndTimer"
QT_MOC_LITERAL(10, 118, 6) // "DoDrag"

    },
    "s21::WidgetListWidgetItem\0DropEventEnd\0"
    "\0WidgetListWidgetItem*\0this_widget\0"
    "ExcpectDrag\0answer\0StartTimer\0msec\0"
    "EndTimer\0DoDrag"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_s21__WidgetListWidgetItem[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       7,    1,   45,    2, 0x06 /* Public */,
       9,    0,   48,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void s21::WidgetListWidgetItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgetListWidgetItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->DropEventEnd((*reinterpret_cast< WidgetListWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->ExcpectDrag((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->StartTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->EndTimer(); break;
        case 4: _t->DoDrag(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< WidgetListWidgetItem* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgetListWidgetItem::*)(WidgetListWidgetItem * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetListWidgetItem::DropEventEnd)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WidgetListWidgetItem::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetListWidgetItem::ExcpectDrag)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (WidgetListWidgetItem::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetListWidgetItem::StartTimer)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (WidgetListWidgetItem::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgetListWidgetItem::EndTimer)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject s21::WidgetListWidgetItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_s21__WidgetListWidgetItem.data,
    qt_meta_data_s21__WidgetListWidgetItem,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *s21::WidgetListWidgetItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *s21::WidgetListWidgetItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_s21__WidgetListWidgetItem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int s21::WidgetListWidgetItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void s21::WidgetListWidgetItem::DropEventEnd(WidgetListWidgetItem * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void s21::WidgetListWidgetItem::ExcpectDrag(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void s21::WidgetListWidgetItem::StartTimer(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void s21::WidgetListWidgetItem::EndTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE

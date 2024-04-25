TEMPLATE = app

DESTDIR = $$PWD/../../build

TARGET = smart_calc_v2

QMAKE_CC = gcc

HEADERS += mainwindow/mainwindow.h                      \
    widgetgraph/widgetgraph.h                           \
    widgetlistwidget/widgetlistwidget.h                 \
    widgetlistwidget/widgetlistwidgetitem.h             \
    widgetlistwidget/widgetlistwidgetdelimline.h        \
    widgetvar/widgetvar.h                               \
    widgetfunc/widgetfunc.h                             \
    widgetmoneyio/widgetmoneyio.h                       \
    ../controller/controller.h                          \
    ../model/sm_exceptions/calculation_error.h          \
    ../model/sm_exceptions/invalid_expression.h         \
    ../model/model.h                                    \
    ../model/variable/variable.h                        \
    ../model/user_function/user_function.h              \
    ../model/token_parser/token_parser.h                \
    ../model/token/token.h                              \
    ../model/special_token/special_token.h              \
    ../model/polish_notation/polish_notation.h          \
    ../model/operation/operation.h                      \
    ../model/list_variable/list_variable.h              \
    ../model/list_user_function/list_user_function.h    \
    ../model/list_graph/list_graph.h                    \
    ../model/graph/graph.h                              \
    ../model/graph/graph_const_y.h                      \
    ../model/graph/graph_const.h                        \
    ../model/graph/graph_func_1.h                       \
    ../model/graph/graph_func_1_y.h                     \
    ../model/graph/graph_point.h                        \
    ../model/credit/credit.h                            \
    ../model/deposit/deposit.h                          \
    ../model/date/date.h                                \
    
FORMS += mainwindow/mainwindow.ui   \
    widgetvar/widgetvar.ui          \
    widgetfunc/widgetfunc.ui        \
    widgetmoneyio/widgetmoneyio.ui  \

SOURCES += ../main.cc                                             \
    mainwindow/mainwindow.cc                                      \
    mainwindow/setup.cc                                           \
    mainwindow/widget_list.cc                                     \
    mainwindow/list_hide.cc                                       \
    mainwindow/calculator.cc                                      \
    mainwindow/credit.cc                                          \
    mainwindow/deposit.cc                                         \
    mainwindow/graph.cc                                           \
    mainwindow/calc_buttons.cc                                    \
    widgetgraph/widgetgraph.cc                                    \
    widgetgraph/paint.cc                                          \
    widgetlistwidget/widgetlistwidget.cc                          \
    widgetlistwidget/widgetlistwidgetitem.cc                      \
    widgetlistwidget/widgetlistwidgetiterator.cc                  \
    widgetlistwidget/widgetlistwidgetdelimline.cc                 \
    widgetvar/widgetvar.cc                                        \
    widgetvar/setup.cc                                            \
    widgetvar/buttons_work.cc                                     \
    widgetfunc/widgetfunc.cc                                      \
    widgetfunc/buttons_work.cc                                    \
    widgetfunc/setup.cc                                           \
    widgetmoneyio/widgetmoneyio.cc                                \
    widgetmoneyio/buttons_work.cc                                 \
    widgetmoneyio/setup.cc                                        \
    ../controller/controller.cc                                   \
    ../model/model.cc                                             \
    ../model/add_formula.cc                                       \
    ../model/define_formula.cc                                    \
    ../model/variable/variable.cc                                 \
    ../model/user_function/user_function.cc                       \
    ../model/token_parser/token_parser.cc                         \
    ../model/token/token.cc                                       \       
    ../model/special_token/special_token.cc                       \
    ../model/polish_notation/calculate.cc                         \
    ../model/polish_notation/construct_destruct.cc                \
    ../model/polish_notation/setters.cc                           \
    ../model/polish_notation/utils.cc                             \
    ../model/polish_notation/translator.cc                        \
    ../model/operation/operation.cc                               \
    ../model/list_variable/list_variable.cc                       \
    ../model/list_user_function/list_user_function.cc             \
    ../model/list_graph/list_graph.cc                             \
    ../model/graph/graph.cc                                       \
    ../model/graph/graph_const_y.cc                               \
    ../model/graph/graph_const.cc                                 \
    ../model/graph/graph_func_1.cc                                \
    ../model/graph/graph_func_1_y.cc                              \
    ../model/graph/graph_point.cc                                 \
    ../model/credit/credit.cc                                     \
    ../model/deposit/deposit.cc                                   \
    ../model/date/calculator.cc                                   \
    ../model/date/comparator.cc                                   \
    ../model/date/construct_destruct.cc                           \
    ../model/date/setters.cc                                      \
    ../model/date/utils.cc                                        \
    ../model/sm_exceptions/invalid_expression.cc                  \


QT += core gui
QT += widgets
CONFIG += object_parallel_to_source
CONFIG += debug
QMAKE_CXXFLAGS += -Wall -Werror -Wextra -Wno-deprecated-declarations

RESOURCES += $$PWD/resources.qrc
UI_DIR += $$PWD/tmp/headers
MOC_DIR = $$PWD/tmp
RCC_DIR = $$PWD/tmp
OBJECTS_DIR = $$PWD/../obj/view/

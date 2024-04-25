PROGRAMM_NAME=s21_containers

CXX=g++
CPPFLAGS = 
CXXFLAGS = -c -std=c++17 -Wall -Werror -Wextra -g
LDGLAGS = -L. -L/usr/lib/
LDLIBS = -lgtest -pthread -lsmart_calc

PATH_OBJ=obj
PATH_MODEL=model
PATH_VIEW=view
PATH_CONTROLLER=controller
PATH_TESTS=tests
PATH_REPORT=tests/report

HEADERS_MODEL = $(wildcard $(PATH_MODEL)/*.h) $(wildcard $(PATH_MODEL)/*/*.h)
CXXFILES_MODEL = $(wildcard $(PATH_MODEL)/*.cc) $(wildcard $(PATH_MODEL)/*/*.cc)
HEADERS_TEST = $(wildcard $(PATH_TESTS)/*.h) $(wildcard $(PATH_TESTS)/*/*.h) $(wildcard $(PATH_TESTS)/*/*/*.h)
CXXFILES_TEST = $(wildcard $(PATH_TESTS)/*.cc) $(wildcard $(PATH_TESTS)/*/*.cc) $(wildcard $(PATH_TESTS)/*/*/*.cc)

CXXFILES = $(CXXFILES_MODEL) $(CXXFILES_TEST)

CXXOBJECTS_MODEL = $(addprefix $(PATH_OBJ)/, $(patsubst %.cc,%.o,$(CXXFILES_MODEL)))
CXXOBJECTS_TEST = $(addprefix $(PATH_OBJ)/, $(patsubst %.cc,%.o,$(CXXFILES_TEST)))

CXXOBJECTS = $(CXXOBJECTS_MODEL) $(CXXOBJECTS_TEST)

.PHONY: all clean install uninstall test dvi dist 
all: test

install: libsmart_calc.a
	cd view;qmake;make

uninstall:
	rm -rf ../build

clean:
	rm -rf $(PATH_OBJ)/*.o $(PATH_OBJ)/*/*.o $(PATH_OBJ)/*/*/*.o
	rm -rf libsmart_calc.a
	rm -rf $(PATH_TESTS)/test $(PATH_TESTS)/testc
	rm -rf $(PATH_REPORT)/* $(PATH_TESTS)/report.info
	rm -rf $(PATH_VIEW)/tmp/moc_* $(PATH_VIEW)/tmp/qrc_* 
	rm -rf $(PATH_VIEW)/Makefile $(PATH_VIEW)/.qmake.stash 
	rm -rf $(PATH_VIEW)/tmp/headers/ui_*.h $(PATH_VIEW)/*.pro.user*
	rm -rf $(PATH_VIEW)/.qtc_clangd
	rm -rf arhive.tar
	rm -rf doxy/index/html doxy/index/latex

rebuild: clean all

test: libsmart_calc.a $(HEADERS_TEST) $(CXXOBJECTS_TEST)
	$(CXX) $(CXXOBJECTS_TEST) $(LDGLAGS) $(LDLIBS) -o $(PATH_TESTS)/test
	tests/test

dvi:
	doxygen doxy/doxyfile
	open doxy/index/html/index.html


dist:
	tar -cvf arhive.tar .

libsmart_calc.a: $(HEADERS_MODEL) $(CXXOBJECTS_MODEL)
	ar rc libsmart_calc.a $(CXXOBJECTS_MODEL)
	ranlib libsmart_calc.a

$(CXXOBJECTS): $(PATH_OBJ)/%.o: %.cc $(HEADERS_MODEL)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@

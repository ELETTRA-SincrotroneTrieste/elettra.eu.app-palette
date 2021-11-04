exists(../cumbia-qt.prf) {
    include(../cumbia-qt.prf)
}

# + ----------------------------------------------------------------- +
#
# Customization section:
#
# Customize the following paths according to your installation:
#
#
# Here qumbia-tango-controls will be installed
# INSTALL_ROOT can be specified from the command line running qmake "INSTALL_ROOT=/my/install/path"
#
isEmpty(INSTALL_ROOT) {
    INSTALL_ROOT = /usr/local/cumbia-libs
}

isEmpty(prefix) {
    prefix = $${INSTALL_ROOT}
}

exists($${INSTALL_ROOT}/include/cumbia-qtcontrols/cumbia-qtcontrols.pri) {
    DOCDIR=$${INSTALL_ROOT}/share/doc/elettra.eu.app-palette
	INC_DIR=$${INSTALL_ROOT}/include/cumbia-qtcontrols
	include($${INC_DIR}/cumbia-qtcontrols.pri)
	message("cumbia-qtcontrols found.")
	message("Project header file(s) will be installed under $${INC_DIR}")
}else{
error("file cumbia-qtcontrols.pri not found under $${INSTALL_ROOT}/include/cumbia-qtcontrols/")
}


VERSION_HEX = 0x010000
VERSION = 1.0.0

# for QPalette and QApplication
QT += gui widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/cuepalette.h

TARGET = bin/dummy

DISTFILES += README.md

doc.commands = \
doxygen \
Doxyfile;

doc.files = doc/*
doc.path = $${DOCDIR}
QMAKE_EXTRA_TARGETS += doc

target.path = /tmp

inc.path = $${CUMBIA_QTCONTROLS_INCLUDES}
inc.files = $${HEADERS}

INSTALLS += inc

TARGET = Examples
QT              += core
QT              += core
CONFIG          += console
CONFIG          -= app_bundle

TARGET          = Examples
TEMPLATE 		= app
SOURCES         += $$files(*.cpp)
HEADERS         += $$files(*.h)
CONFIG          += console

release: DESTDIR = release
debug:   DESTDIR = debug

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.qrc
UI_DIR = $$DESTDIR/.ui

win32 {
    INCLUDEPATH += "$$(PUREWEB_LIBS)/C++/VS2010/include"

    CONFIG(debug, debug|release) {
        LIBS += $$(PUREWEB_LIBS)/C++/VS2010/lib/CSI.PureWeb.ImageProcessing32d.lib
        LIBS += $$(PUREWEB_LIBS)/C++/VS2010/lib/CSI.PureWeb.StateManager32d.lib
        LIBS += $$(PUREWEB_LIBS)/C++/VS2010/lib/CSI.Standard32d.lib
        LIBS += $$(PUREWEB_LIBS)/C++/VS2010/lib/CSI.Typeless32d.lib  

        QMAKE_POST_LINK += ./CopyPrereqs.bat "." "debug" 32 d
    } 
    CONFIG(release, debug|release) {
        LIBS += $$(PUREWEB_LIBS)/C++/VS2010/lib/CSI.PureWeb.ImageProcessing32.lib
        LIBS += $$(PUREWEB_LIBS)/C++/VS2010/lib/CSI.PureWeb.StateManager32.lib
        LIBS += $$(PUREWEB_LIBS)/C++/VS2010/lib/CSI.Standard32.lib
        LIBS += $$(PUREWEB_LIBS)/C++/VS2010/lib/CSI.Typeless32.lib  

        QMAKE_POST_LINK += ./CopyPrereqs.bat "." "release" 32 ""
    }
}

unix {
    CONFIG(debug, debug|release) {  
    } 
    CONFIG(release, debug|release) {
    }
}


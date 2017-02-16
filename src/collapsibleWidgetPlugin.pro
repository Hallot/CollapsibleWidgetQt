QT          += widgets uiplugin
CONFIG      += plugin
CONFIG += C++11
TEMPLATE    = lib

TARGET = $$qtLibraryTarget($$TARGET)

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS += target

FORMS = \
			CollapsibleWidget.ui

HEADERS = \
			CollapsibleWidget.h \
			CollapsibleWidgetPlugin.h

SOURCES = \
			CollapsibleWidget.cpp \
			CollapsibleWidgetPlugin.cpp


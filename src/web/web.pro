TARGET       = QxtWeb
DEPENDPATH  += .
INCLUDEPATH += . ../core ../kit ../../deploy/include
DEFINES     += BUILD_QXT_WEB

unix : LIBS += -L../../deploy/libs/ -lQxtKit  -lQxtCore 
win32: LIBS += -L../../deploy/libs/ -lQxtKit0 -lQxtCore0

win32: CONFIG   += dll


CONFIG      += qxtbuild convenience
QT           = core network
TEMPLATE     = lib

QxtWebApplication.sources		= QxtWebApplication.cpp  QxtWebInternal.cpp
QxtWebApplication.headers		= QxtWebApplication_p.h QxtWebInternal.h

QxtWebController.sources		= QxtWebController.cpp
QxtHtmlTemplate.sources			= QxtHtmlTemplate.cpp

Parts=QxtWebApplication QxtHtmlTemplate QxtWebController

TARGET          =  QxtSql
DESTDIR         = .lib
DEPENDPATH      += .
INCLUDEPATH     += . ../core
DEFINES         += BUILD_QXT_SQL
win32: CONFIG   += dll
QT               = core sql
INCLUDEPATH     += .
VERSION          = 0.2.4
TEMPLATE         = lib
MOC_DIR          = .moc
OBJECTS_DIR      = .obj

HEADERS += QxtSqlPackage.h QxtSqlPackageModel.h QxtSqlQuery.h
SOURCES += QxtSqlPackage.cpp QxtSqlPackageModel.cpp

#include "qxtwebcontroller.h"
#include "qxtwebcore.h"
#include <QStringList>
#include <QDebug>
#include <QCoreApplication>
#include <QUrl>
static QTextStream  nullstream;

QString QxtWebController::WebRoot()
        {

        return QCoreApplication::applicationDirPath()+"/../";
        }

 
QxtWebController::QxtWebController(QString name):QObject(QCoreApplication::instance())
        {
        stream_m=0;
        setObjectName(name);
        }


QTextStream & QxtWebController::echo()
	{
	if(!stream_m)
                {
                qDebug("QxtWebController::echo() no stream open");
                return nullstream;
                }
	return *stream_m;
	}


QString QxtWebController::self()
	{
	return "/"+objectName();
	}


int QxtWebController::invoke(server_t & SERVER_i)
        {
        SERVER=SERVER_i;
	QList<QByteArray> args_d = SERVER["REQUEST_URI"].split('/');

        ///--------------find action ------------------
	QByteArray action="index";	
	if (args_d.count()>2)
		{
		action=args_d.at(2);
		if (action.trimmed().isEmpty())action="index";
		}
	else if (args_d.count()>1) 
		action="index";


	if (args_d.count()>3)
                {
                args_d.removeFirst();
                args_d.removeFirst();
                args_d.removeFirst();
                }
        else
                args_d.clear();

	QStringList args;
	foreach(QByteArray arg,args_d)
		args<<QUrl::fromPercentEncoding(arg);

        QByteArray buffer;
        QTextStream strm (&buffer);
        stream_m=  &strm;

        int retVal=666;
	if (args.count()>8)
		{
		if (!QMetaObject::invokeMethod(this, action,Q_RETURN_ARG(int, retVal) ,
		Q_ARG(QString, args.at(0)),Q_ARG(QString, args.at(1)),Q_ARG(QString, args.at(2)),Q_ARG(QString, args.at(3))
		,Q_ARG(QString, args.at(4)),Q_ARG(QString, args.at(5)),Q_ARG(QString, args.at(6)),Q_ARG(QString, args.at(8))))
			{
			retVal=4042; ///FIXME: the return value of the invoke has a meaning, handle it!
			}
		}
	else if (args.count()>7)
		{
		if (!QMetaObject::invokeMethod(this, (action),Q_RETURN_ARG(int, retVal) ,
		Q_ARG(QString, args.at(0)),Q_ARG(QString, args.at(1)),Q_ARG(QString, args.at(2)),Q_ARG(QString, args.at(3))
		,Q_ARG(QString, args.at(4)),Q_ARG(QString, args.at(5)),Q_ARG(QString, args.at(6)),Q_ARG(QString, args.at(7))
		))
			{
			retVal=4042;
			}

		}
	else if (args.count()>6)
		{
		if ( !QMetaObject::invokeMethod(this, (action),Q_RETURN_ARG(int, retVal) ,
		Q_ARG(QString, args.at(0)),Q_ARG(QString, args.at(1)),Q_ARG(QString, args.at(2)),Q_ARG(QString, args.at(3))
		,Q_ARG(QString, args.at(4)),Q_ARG(QString, args.at(5)),Q_ARG(QString, args.at(6))
		))
			{
			retVal=4042;
			}
		}
	else if (args.count()>5)
		{
		if (!QMetaObject::invokeMethod(this, (action),Q_RETURN_ARG(int, retVal) ,
		Q_ARG(QString, args.at(0)),Q_ARG(QString, args.at(1)),Q_ARG(QString, args.at(2)),Q_ARG(QString, args.at(3))
		,Q_ARG(QString, args.at(4)),Q_ARG(QString, args.at(5))
		))
			{
			retVal=4042;
			}
		} 
	else if ( args.count()>4)
		{
		if ( !QMetaObject::invokeMethod(this, (action),Q_RETURN_ARG(int, retVal) ,
		Q_ARG(QString, args.at(0)),Q_ARG(QString, args.at(1)),Q_ARG(QString, args.at(2)),Q_ARG(QString, args.at(3))
		,Q_ARG(QString, args.at(4))
		))
			{
			retVal=4042;
			}
		} 
	else if (args.count()>3)
		{
		if ( !QMetaObject::invokeMethod(this, (action),Q_RETURN_ARG(int, retVal) ,
		Q_ARG(QString, args.at(0)),Q_ARG(QString, args.at(1)),Q_ARG(QString, args.at(2)),Q_ARG(QString, args.at(3))
		))
			{
			retVal=4042;
			}
		} 
	else if (args.count()>2)
		{
		if ( !QMetaObject::invokeMethod(this, (action),Q_RETURN_ARG(int, retVal) ,
		Q_ARG(QString, args.at(0)),Q_ARG(QString, args.at(1)),Q_ARG(QString, args.at(2))
		))
			retVal=4042;
		} 
	else if (args.count()>1)
		{
		if ( !QMetaObject::invokeMethod(this, (action),Q_RETURN_ARG(int, retVal) ,
		Q_ARG(QString, args.at(0)),Q_ARG(QString, args.at(1))
		))
			retVal=4042;
		} 
	else if (args.count()>0)
		{
		if ( !QMetaObject::invokeMethod(this, (action),Q_RETURN_ARG(int, retVal) ,Q_ARG(QString, args.at(0))))
			retVal=4042;
		} 
	else
		{
		if ( !QMetaObject::invokeMethod(this, (action),Q_RETURN_ARG(int, retVal) ))
			{
			retVal=4042;
			}
		}

	stream_m->flush ();
        stream_m=0;
        QxtWebCore::send(buffer);
        return retVal;
        };





/****************************************************************************
**
** Copyright (C) Qxt Foundation. Some rights reserved.
**
** This file is part of the QxtCore module of the Qt eXTension library
**
** This library is free software; you can redistribute it and/or modify it
** under the terms of th Common Public License, version 1.0, as published by
** IBM.
**
** This file is provided "AS IS", without WARRANTIES OR CONDITIONS OF ANY
** KIND, EITHER EXPRESS OR IMPLIED INCLUDING, WITHOUT LIMITATION, ANY
** WARRANTIES OR CONDITIONS OF TITLE, NON-INFRINGEMENT, MERCHANTABILITY OR
** FITNESS FOR A PARTICULAR PURPOSE. 
**
** You should have received a copy of the CPL along with this file.
** See the LICENSE file and the cpl1.0.txt file included with the source
** distribution for more information. If you did not receive a copy of the
** license, contact the Qxt Foundation.
** 
** <http://libqxt.sourceforge.net>  <libqxt@gmail.com>
**
****************************************************************************/
#ifndef QXTPUSHBUTTON_H
#define QXTPUSHBUTTON_H

#include <QPushButton>
#include "qxtnamespace.h"
#include "qxtglobal.h"
#include "qxtpimpl.h"

class QxtPushButtonPrivate;

class QXT_GUI_EXPORT QxtPushButton : public QPushButton
{
	Q_OBJECT
	QXT_DECLARE_PRIVATE(QxtPushButton);
	Q_PROPERTY(Qxt::Rotation rotation READ rotation WRITE setRotation)
	Q_PROPERTY(Qt::TextFormat textFormat READ textFormat WRITE setTextFormat)
	
public:
	explicit QxtPushButton(QWidget* parent = 0);
	explicit QxtPushButton(const QString& text, QWidget* parent = 0);
	explicit QxtPushButton(const QIcon& icon, const QString& text, QWidget* parent = 0);
	explicit QxtPushButton(Qxt::Rotation rotation, const QString& text, QWidget* parent = 0);
	virtual ~QxtPushButton();
	
	Qxt::Rotation rotation() const;
	void setRotation(Qxt::Rotation rotation);
	
	Qt::TextFormat textFormat() const;
	void setTextFormat(Qt::TextFormat format);
	
#ifndef QXT_DOXYGEN_RUN
	virtual QSize sizeHint() const;
	virtual QSize minimumSizeHint() const;
	
protected:
	virtual void paintEvent(QPaintEvent* event);
#endif // QXT_DOXYGEN_RUN
};

#endif // QXTPUSHBUTTON_H
#pragma once

#include <QWidget>
#include <QMdiArea>
#include <QMap>
#include <QString>
#include <QMdiSubWindow>
#include "ui_ChipsRenderMdiArea.h"

class ChipsRenderMdiArea : public QMdiArea
{
	Q_OBJECT

public:
	ChipsRenderMdiArea(QWidget *parent = nullptr);
	~ChipsRenderMdiArea();

private:
	Ui::ChipsRenderMdiAreaClass ui;
};

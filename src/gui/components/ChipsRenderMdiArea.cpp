#include "ChipsRenderMdiArea.h"

ChipsRenderMdiArea::ChipsRenderMdiArea(QWidget *parent)
	: QMdiArea(parent)
{
	ui.setupUi(this);

	// 设置标签模式(类似现代IDE的标签页)
	setViewMode(QMdiArea::TabbedView);
	setTabsClosable(true);
	setTabsMovable(true);

	//QMdiSubWindow *activeSubWindow = mdiArea->activeSubWindow();
	//if (activeSubWindow) {
	//	// 对活动子窗口进行操作
	//}
}

ChipsRenderMdiArea::~ChipsRenderMdiArea()
{}

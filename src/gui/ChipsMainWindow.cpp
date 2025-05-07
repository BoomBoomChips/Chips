#include "ChipsMainWindow.h"
#include "./ui_ChipsMainWindow.h"
#include "components/ChipsRenderMdiArea.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QWindow>

ChipsMainWindow::ChipsMainWindow(QWidget* parent)
	: QMainWindow(parent)
	, ui(new Ui::ChipsMainWindow)
{
	ui->setupUi(this);

	initWindow();

	// 创建菜单栏和动作
	QMenu* windowMenu = menuBar()->addMenu("窗口");
	QAction* newWindowAct = windowMenu->addAction("新建窗口");
	connect(newWindowAct, &QAction::triggered, this, &ChipsMainWindow::createSubWindow);
}

ChipsMainWindow::~ChipsMainWindow()
{
	delete ui;
}

void ChipsMainWindow::initWindow()
{
	delete ui->m_mdiArea;
	ui->m_mdiArea = nullptr;

	ui->m_mdiArea = new ChipsRenderMdiArea(this->centralWidget());
	setCentralWidget(ui->m_mdiArea);

	QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget());
	mainLayout->setContentsMargins(0, 0, 0, 0); // 可选：去除边距

	createSubWindow();

	auto activeWindow = ui->m_mdiArea->activeSubWindow();
	auto qwindow = activeWindow->widget()->windowHandle();
	//qwindow->winId()
}

void ChipsMainWindow::createSubWindow()
{
	QMdiSubWindow* subWindow = new QMdiSubWindow(ui->m_mdiArea);
	QWidget* contents = new QWidget(subWindow);

	QVBoxLayout* layout = new QVBoxLayout(contents);
	layout->addWidget(new QLabel("MDI 子窗口内容", contents));
	layout->addWidget(new QPushButton("示例按钮", contents));

	subWindow->setWidget(contents);
	subWindow->setAttribute(Qt::WA_DeleteOnClose);
	subWindow->setWindowTitle("子窗口 " + QString::number(ui->m_mdiArea->subWindowList().count() + 1));

	subWindow->show();

	// 平铺所有子窗口
	ui->m_mdiArea->tileSubWindows();
}
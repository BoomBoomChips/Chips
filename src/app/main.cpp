// Chips.cpp: 定义应用程序的入口点。
//

//#include <QtWidgetsApplication.h>
#include <ChipsMainWindow.h>
#include <QtWidgets/QApplication>

#include <render/RenderArea.h>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    ChipsMainWindow w;
    w.show();

    //RenderArea r;
    //auto v=r.doView();
    //v.run();

    return a.exec();
}
 
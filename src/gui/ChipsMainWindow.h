#ifndef CHIPSMAINWINDOW_H
#define CHIPSMAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QtGlobal>  // 使用Qt的导出宏兼容方案（可选）

#include <osgViewer/Viewer>
#include <osgGA/TrackballManipulator>
#include <osgGA/StateSetManipulator>
#include <osgViewer/ViewerEventHandlers>
#include <osgDB/ReadFile>
#include <osgViewer/ViewerEventHandlers>
#include <osgAnimation/BasicAnimationManager>
#include <osg/MatrixTransform>
#include <osg/PolygonOffset>
#include <osg/Switch>
//#include <osgQt/GraphicsWindowQt>


QT_BEGIN_NAMESPACE
namespace Ui { class ChipsMainWindow; }
QT_END_NAMESPACE

#ifdef CHIPS_STATIC
#define CHIPS_API
#else
#ifdef _WIN32
#ifdef CHIPS_EXPORTS
#define CHIPS_API __declspec(dllexport)
#else
#define CHIPS_API __declspec(dllimport)
#endif
#else
#define CHIPS_API __attribute__((visibility("default")))
#endif
#endif

class CHIPS_API ChipsMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ChipsMainWindow(QWidget *parent = nullptr);
    ~ChipsMainWindow();

    /**
     * @brief 初始化窗体
     */
    void initWindow();

public slots:

    void createSubWindow();

private:
    Ui::ChipsMainWindow *ui;
};
#endif // CHIPSMAINWINDOW_H

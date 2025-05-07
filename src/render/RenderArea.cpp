#include "RenderArea.h"

RenderArea::RenderArea()
{
}

RenderArea::~RenderArea()
{
}

osgViewer::Viewer RenderArea::doView()
{
    const std::string file = "W://CodeNet//Chips//out//build//x64-debug//bin//cow.osg";
    osg::ref_ptr<osg::Node> root = osgDB::readRefNodeFile(file);
    
    if (root == NULL)
    {
        /*osg::notify(osg::FATAL) << "Unable to load model from command line." << std::endl;
        return(1);*/
        //root = osgDB::readRefNodeFile("cow.osg");
        if (!root)
        {
            return osgViewer::Viewer();
        }
    }

    osgUtil::Optimizer optimizer;
    optimizer.optimize(root.get(), osgUtil::Optimizer::ALL_OPTIMIZATIONS | osgUtil::Optimizer::TESSELLATE_GEOMETRY);

    configureShaders(root->getOrCreateStateSet());

    const int width(800), height(450);
    const std::string version("3.0");
    osg::ref_ptr< osg::GraphicsContext::Traits > traits = new osg::GraphicsContext::Traits();
    traits->x = 20; traits->y = 30;
    traits->width = width; traits->height = height;
    traits->windowDecoration = true;
    traits->doubleBuffer = true;
    traits->glContextVersion = version;
    traits->readDISPLAY();
    traits->setUndefinedScreenDetailsToDefaultScreen();
    osg::ref_ptr< osg::GraphicsContext > gc = osg::GraphicsContext::createGraphicsContext(traits.get());
    if (!gc.valid())
    {
        osg::notify(osg::FATAL) << "Unable to create OpenGL v" << version << " context." << std::endl;
        //return(1);
    }

    osgViewer::Viewer viewer;

    // Create a Camera that uses the above OpenGL context.
    osg::Camera* cam = viewer.getCamera();
    cam->setGraphicsContext(gc.get());
    // Must set perspective projection for fovy and aspect.
    cam->setProjectionMatrix(osg::Matrix::perspective(30., (double)width / (double)height, 1., 100.));
    // Unlike OpenGL, OSG viewport does *not* default to window dimensions.
    cam->setViewport(new osg::Viewport(0, 0, width, height));

    viewer.setSceneData(root);

    // for non GL3/GL4 and non GLES2 platforms we need enable the osg_ uniforms that the shaders will use,
    // you don't need thse two lines on GL3/GL4 and GLES2 specific builds as these will be enable by default.
    gc->getState()->setUseModelViewAndProjectionUniforms(true);
    gc->getState()->setUseVertexAttributeAliasing(true);
    viewer.run();
    return viewer;
}

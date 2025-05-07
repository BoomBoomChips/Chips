#pragma once

#include <osgViewer/Viewer>
#include <osgDB/ReadFile>
#include <osg/GraphicsContext>
#include <osg/Camera>
#include <osg/Viewport>
#include <osg/StateSet>
#include <osg/Program>
#include <osg/Shader>
#include <osgUtil/Optimizer>

#ifdef MYLIB_STATIC
#define MYLIB_API
#else
#ifdef _WIN32
#ifdef MYLIB_EXPORTS
#define MYLIB_API __declspec(dllexport)
#else
#define MYLIB_API __declspec(dllimport)
#endif
#else
#define MYLIB_API __attribute__((visibility("default")))
#endif
#endif

void configureShaders(osg::StateSet* stateSet)
{
    const std::string vertexSource =
        "#version 130 \n"
        " \n"
        "uniform mat4 osg_ModelViewProjectionMatrix; \n"
        "uniform mat3 osg_NormalMatrix; \n"
        "uniform vec3 ecLightDir; \n"
        " \n"
        "in vec4 osg_Vertex; \n"
        "in vec3 osg_Normal; \n"
        "out vec4 color; \n"
        " \n"
        "void main() \n"
        "{ \n"
        "    vec3 ecNormal = normalize( osg_NormalMatrix * osg_Normal ); \n"
        "    float diffuse = max( dot( ecLightDir, ecNormal ), 0. ); \n"
        "    color = vec4( vec3( diffuse ), 1. ); \n"
        " \n"
        "    gl_Position = osg_ModelViewProjectionMatrix * osg_Vertex; \n"
        "} \n";
    osg::Shader* vShader = new osg::Shader(osg::Shader::VERTEX, vertexSource);

    const std::string fragmentSource =
        "#version 130 \n"
        " \n"
        "in vec4 color; \n"
        "out vec4 fragData; \n"
        " \n"
        "void main() \n"
        "{ \n"
        "    fragData = color; \n"
        "} \n";
    osg::Shader* fShader = new osg::Shader(osg::Shader::FRAGMENT, fragmentSource);

    osg::Program* program = new osg::Program;
    program->addShader(vShader);
    program->addShader(fShader);
    stateSet->setAttribute(program);

    osg::Vec3f lightDir(0., 0.5, 1.);
    lightDir.normalize();
    stateSet->addUniform(new osg::Uniform("ecLightDir", lightDir));
}

//int main(int argc, char** argv)
//{
//    osg::ArgumentParser arguments(&argc, argv);
//
//
//    return(viewer.run());
//}



class MYLIB_API RenderArea
{
public:
	RenderArea();
	~RenderArea();

    osgViewer::Viewer doView();

private:

};


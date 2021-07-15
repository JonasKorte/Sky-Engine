#include <engine.h>

namespace SkyCore
{
    SVoid error_callback(SInt error, SCharArray description)
    {
        LOGERR(description << " Error Code: " << error);
    }

    Engine::Engine() 
    {

    }

    Engine::~Engine()
    {
        this->Cleanup();
    }

    SBool Engine::Initialize()
    {
        if (!glfwInit())
        {
            LOGFATAL("Unable to initialize GLFW!");
            return false;
        }

        glfwSetErrorCallback(error_callback);
    }

    SBool Engine::CreateWindow(SCharArray title, SInt width, SInt height, SBool fullscreen)
    {

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 8);
        glfwWindowHint(GLFW_DOUBLEBUFFER, 1);

        this->m_window = glfwCreateWindow(width, height, title, NULL, NULL);

        if (!this->m_window)
        {
            LOGFATAL("Unable to create window!");
            return false;
        }

        glfwMakeContextCurrent(this->m_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOGFATAL("Unable to load OpenGL!");
            return false;
        }
    }

    SBool Engine::Cleanup()
    {
        glfwDestroyWindow(this->m_window);

        glfwTerminate();
    }
}
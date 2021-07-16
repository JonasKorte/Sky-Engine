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

        return true;
    }

    SBool Engine::CreateWindow(SCharArray title, SInt width, SInt height, SBool fullscreen)
    {

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 8);
        glfwWindowHint(GLFW_DOUBLEBUFFER, 1);

        if (fullscreen)
        {
            this->m_window = glfwCreateWindow(width, height, title, glfwGetPrimaryMonitor(), NULL);
        }
        else
        {
            this->m_window = glfwCreateWindow(width, height, title, NULL, NULL);
        }


        if (!this->m_window)
        {
            LOGFATAL("Unable to create window!");
            return false;
        }

        glfwSetWindowUserPointer(this->m_window, this);

        glfwMakeContextCurrent(this->m_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            LOGFATAL("Unable to load OpenGL!");
            return false;
        }

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        this->SetViewport(0, 0, width, height);

        return true;
    }

    SVoid Engine::MainLoop()
    {
        while (!glfwWindowShouldClose(this->m_window))
        {
            glfwPollEvents();

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            glfwSwapBuffers(this->m_window);
        }

        return;
    }

    SVoid Engine::SetViewport(SInt x, SInt y, SInt width, SInt height)
    {
        glViewport(x, y, width, height);
    }

    SBool Engine::Cleanup()
    {
        glfwDestroyWindow(this->m_window);

        glfwTerminate();

        return true;
    }
}
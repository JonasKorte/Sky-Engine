#pragma once
#include <types.h>
#include <log.h>

#define GLFW_INCLUDE_NONE
#include <glfw3.h>

#include <glad.h>

namespace SkyCore
{
    SVoid error_callback(SInt error, SCharArray description);

    class Engine
    {
    public:
        Engine();
        ~Engine();
        SBool Initialize();
        SBool CreateWindow(SCharArray title, SInt width, SInt height, SBool fullscreen);
        SVoid MainLoop();

    private:
        SBool Cleanup();

        GLFWwindow* m_window;
    };
}
#include <engine.h>

int main()
{
    SkyCore::Engine* engine = new SkyCore::Engine();

    if (!engine->Initialize())
    {
        return -1;
    }

    if (!engine->CreateWindow("Sky Engine", 1920, 1080, false))
    {
        return -1;
    }

    engine->MainLoop();

    delete (engine);

    return 0;
}
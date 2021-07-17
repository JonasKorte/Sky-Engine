#pragma once
#include <types.h>

namespace SkyCore
{
    struct fQuaternion
    {
        SFloat x;
        SFloat y;
        SFloat z;
        SFloat w;
    };

    struct dQuaternion
    {
        SDouble x;
        SDouble y;
        SDouble z;
        SDouble w;
    };

    struct iQuaternion
    {
        SInt x;
        SInt y;
        SInt z;
        SInt w;
    };
}
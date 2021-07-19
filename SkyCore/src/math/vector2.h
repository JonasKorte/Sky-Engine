#pragma once
#include <types.h>

namespace SkyCore
{
    struct Vector2f
    {
        SFloat x;
        SFloat y;

        Vector2f operator +(Vector2f other)
        {
            Vector2f newVector;
            newVector.x = x + other.x;
            newVector.y = y + other.y;

            return newVector;
        }

        Vector2f operator -(Vector2f other)
        {
            Vector2f newVector;
            newVector.x = x - other.x;
            newVector.y = y - other.y;

            return newVector;
        }

        Vector2f operator *(Vector2f other)
        {
            Vector2f newVector;
            newVector.x = x * other.x;
            newVector.y = y * other.y;

            return newVector;
        }

        Vector2f operator /(Vector2f other)
        {
            Vector2f newVector;
            newVector.x = x / other.x;
            newVector.y = y / other.y;

            return newVector;
        }
    };

    struct Vector2d
    {
        SDouble x;
        SDouble y;

        Vector2d operator +(Vector2d other)
        {
            Vector2d newVector;
            newVector.x = x + other.x;
            newVector.y = y + other.y;

            return newVector;
        }

        Vector2d operator -(Vector2d other)
        {
            Vector2d newVector;
            newVector.x = x - other.x;
            newVector.y = y - other.y;

            return newVector;
        }

        Vector2d operator *(Vector2d other)
        {
            Vector2d newVector;
            newVector.x = x * other.x;
            newVector.y = y * other.y;

            return newVector;
        }

        Vector2d operator /(Vector2d other)
        {
            Vector2d newVector;
            newVector.x = x / other.x;
            newVector.y = y / other.y;

            return newVector;
        }
    };

    struct Vector2i
    {
        SInt x;
        SInt y;

        Vector2i operator +(Vector2i other)
        {
            Vector2i newVector;
            newVector.x = x + other.x;
            newVector.y = y + other.y;

            return newVector;
        }

        Vector2i operator -(Vector2i other)
        {
            Vector2i newVector;
            newVector.x = x - other.x;
            newVector.y = y - other.y;

            return newVector;
        }

        Vector2i operator *(Vector2i other)
        {
            Vector2i newVector;
            newVector.x = x * other.x;
            newVector.y = y * other.y;

            return newVector;
        }

        Vector2f operator /(Vector2i other)
        {
            Vector2f newVector;
            newVector.x = x / other.x;
            newVector.y = y / other.y;

            return newVector;
        }
    };
}
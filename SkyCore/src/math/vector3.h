#pragma once
#include <types.h>

namespace SkyCore
{
    struct Vector3f
    {
        SFloat x;
        SFloat y;
        SFloat z;

        Vector3f operator +(Vector3f other)
        {
            Vector3f newVector;
            newVector.x = x + other.x;
            newVector.y = y + other.y;
            newVector.z = z + other.z;

            return newVector;
        }

        Vector3f operator -(Vector3f other)
        {
            Vector3f newVector;
            newVector.x = x - other.x;
            newVector.y = y - other.y;
            newVector.z = z - other.z;

            return newVector;
        }

        Vector3f operator *(Vector3f other)
        {
            Vector3f newVector;
            newVector.x = x * other.x;
            newVector.y = y * other.y;
            newVector.z = z * other.z;

            return newVector;
        }

        Vector3f operator /(Vector3f other)
        {
            Vector3f newVector;
            newVector.x = x / other.x;
            newVector.y = y / other.y;
            newVector.z = z / other.z;

            return newVector;
        }
    };

    struct Vector3d
    {
        SDouble x;
        SDouble y;
        SDouble z;

        Vector3d operator +(Vector3d other)
        {
            Vector3d newVector;
            newVector.x = x + other.x;
            newVector.y = y + other.y;
            newVector.z = z + other.z;

            return newVector;
        }

        Vector3d operator -(Vector3d other)
        {
            Vector3d newVector;
            newVector.x = x - other.x;
            newVector.y = y - other.y;
            newVector.z = z - other.z;

            return newVector;
        }

        Vector3d operator *(Vector3d other)
        {
            Vector3d newVector;
            newVector.x = x * other.x;
            newVector.y = y * other.y;
            newVector.z = z * other.z;

            return newVector;
        }

        Vector3d operator /(Vector3d other)
        {
            Vector3d newVector;
            newVector.x = x / other.x;
            newVector.y = y / other.y;
            newVector.z = z / other.z;

            return newVector;
        }
    };

    struct Vector3i
    {
        SInt x;
        SInt y;
        SInt z;

        Vector3i operator +(Vector3i other)
        {
            Vector3i newVector;
            newVector.x = x + other.x;
            newVector.y = y + other.y;
            newVector.z = z + other.z;

            return newVector;
        }

        Vector3i operator -(Vector3i other)
        {
            Vector3i newVector;
            newVector.x = x - other.x;
            newVector.y = y - other.y;
            newVector.z = z - other.z;

            return newVector;
        }

        Vector3i operator *(Vector3i other)
        {
            Vector3i newVector;
            newVector.x = x * other.x;
            newVector.y = y * other.y;
            newVector.z = z * other.z;

            return newVector;
        }

        Vector3f operator /(Vector3i other)
        {
            Vector3f newVector;
            newVector.x = x / other.x;
            newVector.y = y / other.y;
            newVector.z = z / other.z;

            return newVector;
        }
    };
}
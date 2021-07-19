#pragma once

#include <vector2.h>
#include <vector3.h>
#include <quaternion.h>

namespace SkyCore
{
    class TransformBase3D
    {
    public:
        TransformBase3D();
        TransformBase3D(Vector3f position, Vector3f rotation, Vector3f scale);

        SVoid SetPosition(Vector3f position);
        Vector3f GetPosition();

        SVoid SetRotation(Vector3f rotation);
        Vector3f GetRotation();

        SVoid SetScale(Vector3f scale);
        Vector3f GetScale();

        static TransformBase3D* DefaultTransform();

    private:
        Vector3f m_position;
        Vector3f m_rotation;
        Vector3f m_scale;
    };
}
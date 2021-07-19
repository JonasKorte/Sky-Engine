#include <transform.h>

namespace SkyCore
{
    TransformBase3D::TransformBase3D()
    {
        Vector3f zero {};
        zero.x = 0.0f;
        zero.y = 0.0f;
        zero.z = 0.0f;

        this->m_position = zero;
        this->m_rotation = zero;

        Vector3f scale {};
        scale.x = 1.0f;
        scale.y = 1.0f;
        scale.z = 1.0f;

        this->m_scale = scale;
    }

    TransformBase3D::TransformBase3D(Vector3f position, Vector3f rotation, Vector3f scale)
    {
        this->m_position = position;
        this->m_rotation = rotation;
        this->m_scale = scale;
    }

    SVoid TransformBase3D::SetPosition(Vector3f position)
    {
        this->m_position = position;
    }

    Vector3f TransformBase3D::GetPosition()
    {
        return this->m_position;
    }

    SVoid TransformBase3D::SetRotation(Vector3f rotation)
    {
        this->m_rotation = rotation;
    }

    Vector3f TransformBase3D::GetRotation()
    {
        return this->m_rotation;
    }

    SVoid TransformBase3D::SetScale(Vector3f scale)
    {
        this->m_scale = scale;
    }

    Vector3f TransformBase3D::GetScale()
    {
        return this->m_scale;
    }

    TransformBase3D* TransformBase3D::DefaultTransform()
    {
        TransformBase3D* transform = new TransformBase3D();

        return transform;
    }
}
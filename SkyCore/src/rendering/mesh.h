#pragma once
#include <vector3.h>
#include <transform.h>
#include <math.h>

#include <vector>

#include <glad.h>

namespace SkyCore
{
    namespace SkyRender
    {
        struct Vertex
        {
            Vector3f position;
            Vector3f normal;
            Vector3f tangent;
            Vector3f bitangent;
            Vector3f uv;
        };

        struct Mesh
        {
            std::vector<Vertex> vertices;
            std::vector<SUInt> indices;
        };

        class MeshRendererBase
        {
        public:
            MeshRendererBase(Mesh mesh);
            MeshRendererBase(Mesh mesh, TransformBase3D* transform);
            ~MeshRendererBase();

            SBool Initialize();

            SVoid Draw();

            Mesh GetMesh();

            SVoid SetTransform(TransformBase3D* transform);
            TransformBase3D* GetTransform();
        private:
            SVoid Cleanup();
            
            Mesh m_mesh;

            TransformBase3D* m_transform;

            SUInt m_vbo;
            SUInt m_ibo;
        };
    }
}
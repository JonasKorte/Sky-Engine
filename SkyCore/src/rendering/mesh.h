#pragma once
#include <vector3.h>
#include <vector2.h>
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
            Vector2f uv;
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
            ~MeshRendererBase();

            SBool Initialize();

            SVoid Draw();

            Mesh GetMesh();
        private:
            SVoid Cleanup();

            Mesh m_mesh;

            SUInt m_vbo;
            SUInt m_ibo;
        };
    }
}
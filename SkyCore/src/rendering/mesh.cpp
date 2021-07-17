#include <mesh.h>

namespace SkyCore
{
    namespace SkyRender
    {
        MeshRendererBase::MeshRendererBase(Mesh mesh)
        {
            this->m_mesh = mesh;
        }

        MeshRendererBase::~MeshRendererBase()
        {
            this->Cleanup();
        }

        SBool MeshRendererBase::Initialize()
        {
            glGenBuffers(1, &this->m_vbo);
            glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo);

            glBufferData(GL_ARRAY_BUFFER, this->m_mesh.vertices.size() * sizeof(Vertex), &this->m_mesh.vertices, GL_DYNAMIC_DRAW);

            glGenBuffers(1, &this->m_ibo);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ibo);

            glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_mesh.indices.size() * sizeof(SUInt), &this->m_mesh.indices, GL_DYNAMIC_DRAW);



            return true;
        }

        SVoid MeshRendererBase::Draw()
        {

        }

        Mesh MeshRendererBase::GetMesh()
        {
            return this->m_mesh;
        }

        SVoid MeshRendererBase::Cleanup()
        {

        }
    }
}
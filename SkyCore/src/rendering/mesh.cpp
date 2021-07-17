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

            std::vector<Vector3f> vertices;

            for (SInt i = 0; i < this->m_mesh.vertices.size(); i++)
            {
                vertices.push_back(this->m_mesh.vertices[i].position);
                vertices.push_back(this->m_mesh.vertices[i].normal);
                vertices.push_back(this->m_mesh.vertices[i].tangent);
                vertices.push_back(this->m_mesh.vertices[i].bitangent);
                vertices.push_back(this->m_mesh.vertices[i].uv);
            }

            glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vector3f), &vertices, GL_DYNAMIC_DRAW);

            glBindBuffer(GL_ARRAY_BUFFER, 0);

            glGenBuffers(1, &this->m_ibo);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ibo);

            glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->m_mesh.indices.size() * sizeof(SUInt), &this->m_mesh.indices, GL_DYNAMIC_DRAW);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

            return true;
        }

        SVoid MeshRendererBase::Draw()
        {
            glBindBuffer(GL_ARRAY_BUFFER, this->m_vbo);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_ibo);

            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
            glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
            glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, 0);
            glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, 0);
            glVertexAttribPointer(4, 2, GL_FLOAT, GL_TRUE, 0, 0);

            glDrawElements(GL_TRIANGLES, this->m_mesh.indices.size(), GL_UNSIGNED_INT, 0);

            glDisableVertexAttribArray(0);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        Mesh MeshRendererBase::GetMesh()
        {
            return this->m_mesh;
        }

        SVoid MeshRendererBase::Cleanup()
        {
            glDeleteBuffers(1, &this->m_vbo);
            glDeleteBuffers(1, &this->m_ibo);
        }
    }
}
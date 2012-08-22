#ifndef GLMODEL_H
#define GLMODEL_H

#include "GLMath.h"
#include <GL/gl.h>
#include <vector>


struct BBox
{
    GLFloat3 A;
    GLFloat3 B;
};


struct GLMesh
{
    GLMesh()
    {
        vertices = 0;
        texcoords = 0;
        normals = 0;
        verticesCount = 0;
        indices = 0;
        indicesCount = 0;
    }

    ~GLMesh()
    {
        delete [] vertices;
        delete [] texcoords;
        delete [] normals;
        delete [] indices;
    }

	void render();

	GLFloat3*   vertices;
	GLFloat2*   texcoords;
	GLFloat3*   normals;
	int         verticesCount;
	GLushort*   indices;
	int         indicesCount;
	char      	name[256];
};


class GLModel
{
public:
	GLModel();
	virtual ~GLModel();

	//constructors
	static GLModel* createFromFile(const char* file_name, float scale, int flags);

	void render(bool use_model_material = true);
	void renderGroup(int group_index);
    void compile();
    void buildNormals(bool smooth);
	int getGroupByName(const char* group_name);
    BBox getBBox() const;

    inline const char* getFileName() { return m_FileName; }

    //
    // Flexible mesh
    //
    struct VERTEX
    {
        VERTEX() : V(0), T(0), N(0) {}
        VERTEX(int v, int t, int n) : V(v), T(t), N(n) {}
        int V,T,N;
    };
    struct FACE
    {
        FACE() {}
        FACE(VERTEX a, VERTEX b, VERTEX c) : A(a), B(b), C(c) {}
        VERTEX A,B,C;
    };
    struct GROUP
    {
        GROUP() { }
        GROUP(const char *s) { }
        std::vector<FACE> faces;
        char name[256];
    };

    void newModel();
    inline int pushVertex(const GLFloat3 &v) { FlexVertices.push_back(v); return FlexVertices.size()-1; }
    inline int pushTexCoord(const GLFloat2 &v) { FlexTexCoords.push_back(v); return FlexTexCoords.size()-1; }
    inline int pushNormal(const GLFloat3 &v) { FlexNormals.push_back(v); return FlexNormals.size()-1; }
    inline int pushFace(int g, const FACE &f) { FlexGroups[g].faces.push_back(f); return FlexGroups[g].faces.size()-1; }
    inline int pushGroup(const char *name) { FlexGroups.push_back(GROUP(name)); return FlexGroups.size()-1; };

    std::vector<GLFloat3> FlexVertices;
    std::vector<GLFloat2> FlexTexCoords;
    std::vector<GLFloat3> FlexNormals;
    std::vector<GROUP> FlexGroups;

private:
	char		m_FileName[256];
    float       m_Scale;
    int         m_GroupsCount;
	GLMesh*     m_Meshes;
	int         m_MeshesCount;
    bool        m_IsCompiled;
};


#endif // GLMODEL_H

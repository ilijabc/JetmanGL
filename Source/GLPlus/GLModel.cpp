/*
	by Ilija
*/


#include "GLModel.h"
#include <string.h>
#include <stdlib.h>


static GLFloat3 v3MakeFaceNormal(GLFloat3 v1, GLFloat3 v2, GLFloat3 v3)
{
	GLFloat3 norm;
	return norm;
}


GLModel::GLModel()
{
	strcpy(m_FileName, "");
    m_Scale = 1.0f;
    m_GroupsCount = 0;
	m_Meshes = NULL;
	m_MeshesCount = 0;
    m_IsCompiled = false;
}

GLModel::~GLModel()
{
    delete [] m_Meshes;
}


//
//constructors
//
GLModel* GLModel::createFromFile(const char* file_name, float scale, int flags)
{
    /*UTModel loader;
    GLModel* model = new GLModel();
    if (loader.loadFile(file_name, model))
    {
		model->m_Scale = scale;
		model->m_FileName = file_name;
		model->m_GroupsCount = model->FlexGroups.size();
        printf("NEW RESOURCE: Model '%s'\n", file_name);
        if (flags == 0)
            model->compile();
        return model;
    }
    else
    {
        delete model;
        printf("NOT FOUND: Model '%s'\n", file_name);
		return NULL;
    }*/
}


void GLModel::render(bool use_model_material)
{
    glPushMatrix();
    glScalef(m_Scale, m_Scale, m_Scale);

    for (int i = 0; i < m_GroupsCount; ++i)
    {
        renderGroup(i);
    }

    glPopMatrix();
}


void GLModel::renderGroup(int group_index)
{
    if (m_IsCompiled)
    {
        m_Meshes[group_index].render();
    }
    else
    {
        glBegin(GL_TRIANGLES);
        for (int i = 0; i < (int)FlexGroups[group_index].faces.size(); ++i)
        {
            const FACE &face = FlexGroups[group_index].faces[i];
            //A
            glNormal3fv(FlexNormals[face.A.N].getPtr());
            glTexCoord2fv(FlexTexCoords[face.A.T].getPtr());
            glVertex3fv(FlexVertices[face.A.V].getPtr());
            //B
            glNormal3fv(FlexNormals[face.B.N].getPtr());
            glTexCoord2fv(FlexTexCoords[face.B.T].getPtr());
            glVertex3fv(FlexVertices[face.B.V].getPtr());
            //C
            glNormal3fv(FlexNormals[face.C.N].getPtr());
            glTexCoord2fv(FlexTexCoords[face.C.T].getPtr());
            glVertex3fv(FlexVertices[face.C.V].getPtr());
        }
        glEnd();
    }
}

void GLModel::compile()
{
    if (FlexNormals.empty())
    {
        buildNormals(true);
    }
    m_MeshesCount = FlexGroups.size();
    m_Meshes = new GLMesh[m_MeshesCount];
    for (int g = 0; g < (int)FlexGroups.size(); ++g)
    {
        GLMesh &m = m_Meshes[g];
        strcpy(m.name, FlexGroups[g].name);
        int n = FlexGroups[g].faces.size();
        m.verticesCount = n*3;
        m.vertices = new GLFloat3 [m.verticesCount];
        if (!FlexTexCoords.empty())
            m.texcoords = new GLFloat2 [m.verticesCount];
        m.normals = new GLFloat3 [m.verticesCount];
        m.indicesCount = n*3;
        m.indices = new GLushort [m.indicesCount];
        for (int i = 0; i < n; ++i)
        {
            int a = i*3;
            int b = i*3+1;
            int c = i*3+2;
            //A
            m.vertices[a] = FlexVertices[FlexGroups[g].faces[i].A.V];
            if (m.texcoords)
                m.texcoords[a] = FlexTexCoords[FlexGroups[g].faces[i].A.T];
            m.normals[a] = FlexNormals[FlexGroups[g].faces[i].A.N];
            m.indices[a] = a;
            //B
            m.vertices[b] = FlexVertices[FlexGroups[g].faces[i].B.V];
            if (m.texcoords)
                m.texcoords[b] = FlexTexCoords[FlexGroups[g].faces[i].B.T];
            m.normals[b] = FlexNormals[FlexGroups[g].faces[i].B.N];
            m.indices[b] = b;
            //C
            m.vertices[c] = FlexVertices[FlexGroups[g].faces[i].C.V];
            if (m.texcoords)
                m.texcoords[c] = FlexTexCoords[FlexGroups[g].faces[i].C.T];
            m.normals[c] = FlexNormals[FlexGroups[g].faces[i].C.N];
            m.indices[c] = c;
        }
    }
    FlexVertices.clear();
    FlexTexCoords.clear();
    FlexNormals.clear();
    FlexGroups.clear();
    m_IsCompiled = true;
}

void GLModel::buildNormals(bool smooth)
{
    std::vector<GLFloat3> face_normals;
    FlexNormals.clear();
    int g_cnt = FlexGroups.size();
    for (int g = 0; g < g_cnt; ++g)
    {
        int f_cnt = FlexGroups[g].faces.size();
        for (int i = 0; i < f_cnt; ++i)
        {
        	GLFloat3 v1 = FlexVertices[FlexGroups[g].faces[i].A.V];
        	GLFloat3 v2 = FlexVertices[FlexGroups[g].faces[i].B.V];
        	GLFloat3 v3 = FlexVertices[FlexGroups[g].faces[i].C.V];
        	GLFloat3 vn = v3MakeFaceNormal(v1, v2, v3);
            if (smooth)
            {
                face_normals.push_back(vn);
            }
            else
            {
                int ind = pushNormal(vn);
                FlexGroups[g].faces[i].A.N = ind;
                FlexGroups[g].faces[i].B.N = ind;
                FlexGroups[g].faces[i].C.N = ind;
            }
        }
    }
    //printf("> %i\n", face_normals.size());
    if (!smooth)
        return;
    //smooth
    for (int g = 0; g < g_cnt; ++g)
    {
        int f_cnt = FlexGroups[g].faces.size();
        int f_cnt_prev = 0;
        if (g > 0)
            f_cnt_prev = FlexGroups[g - 1].faces.size();
        for (int i = 0; i < f_cnt; ++i)
        {
        	GLFloat3 va = face_normals[g * f_cnt_prev + i];
        	GLFloat3 vb = face_normals[g * f_cnt_prev + i];
        	GLFloat3 vc = face_normals[g * f_cnt_prev + i];
            int na = 1;
            int nb = 1;
            int nc = 1;
            for (int j = 0; j < f_cnt; ++j)
            {
                if (i != j)
                {
                    if (FlexGroups[g].faces[i].A.V == FlexGroups[g].faces[j].A.V ||
                        FlexGroups[g].faces[i].A.V == FlexGroups[g].faces[j].B.V ||
                        FlexGroups[g].faces[i].A.V == FlexGroups[g].faces[j].C.V)
                    {
                        va += face_normals[g * f_cnt_prev + j];
                        na++;
                    }
                    if (FlexGroups[g].faces[i].B.V == FlexGroups[g].faces[j].A.V ||
                        FlexGroups[g].faces[i].B.V == FlexGroups[g].faces[j].B.V ||
                        FlexGroups[g].faces[i].B.V == FlexGroups[g].faces[j].C.V)
                    {
                        vb += face_normals[g * f_cnt_prev + j];
                        nb++;
                    }
                    if (FlexGroups[g].faces[i].C.V == FlexGroups[g].faces[j].A.V ||
                        FlexGroups[g].faces[i].C.V == FlexGroups[g].faces[j].B.V ||
                        FlexGroups[g].faces[i].C.V == FlexGroups[g].faces[j].C.V)
                    {
                        vc += face_normals[g * f_cnt_prev + j];
                        nc++;
                    }
                }
            }
            //aprox
            va /= (float)na;
            va.normalize();
            vb /= (float)nb;
            vb.normalize();
            vc /= (float)nc;
            vc.normalize();
            //set
            FlexGroups[g].faces[i].A.N = pushNormal(va);
            FlexGroups[g].faces[i].B.N = pushNormal(vb);
            FlexGroups[g].faces[i].C.N = pushNormal(vc);
        }
    }
    //printf("< %i\n", FlexNormals.size());
}

int GLModel::getGroupByName(const char *group_name)
{
	for (int g = 0; g < m_GroupsCount; g++)
	{
		if (m_IsCompiled && FlexGroups[g].name == group_name)
            return g;
        else if (m_Meshes && m_Meshes[g].name == group_name)
            return g;
	}
	return -1;
}

BBox GLModel::getBBox() const
{
    BBox bbox;
	for (int g = 0; g < m_GroupsCount; g++)
	{
        for (int i = 0; i < m_Meshes[g].verticesCount; i++)
        {
        	GLFloat3 v = m_Meshes[g].vertices[i];
            //first vert
            if (i == 0 && g == 0)
            {
                bbox.A = v;
                bbox.B = v;
            }
            //min and max verts
            else
            {
                if (v.x < bbox.A.x) bbox.A.x = v.x;
                if (v.y < bbox.A.y) bbox.A.y = v.y;
                if (v.z < bbox.A.z) bbox.A.z = v.z;
                if (v.x > bbox.B.x) bbox.B.x = v.x;
                if (v.y > bbox.B.y) bbox.B.y = v.y;
                if (v.z > bbox.B.z) bbox.B.z = v.z;
            }
        }
	}
	return bbox;
}

void GLModel::newModel()
{
    FlexVertices.clear();
    FlexTexCoords.clear();
    FlexNormals.clear();
    FlexGroups.clear();
    delete [] m_Meshes;
    m_IsCompiled = false;
}
//
// GLMesh
//

void GLMesh::render()
{
    glPolygonMode(GL_FRONT_FACE, GL_LINE);

    glEnableClientState(GL_VERTEX_ARRAY);
    if (texcoords)
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    if (texcoords)
        glTexCoordPointer(2, GL_FLOAT, 0, texcoords);
    glNormalPointer(GL_FLOAT, 0, normals);
    glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_SHORT, indices);
    glDisableClientState(GL_NORMAL_ARRAY);
    if (texcoords)
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
}




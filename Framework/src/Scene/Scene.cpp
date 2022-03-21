#include "Scene.h"

Framework::Scene::Scene() {}
Framework::Scene::~Scene() {}

void Framework::Scene::InitScene()
{
	m_BaseVertex = Framework::Shader("res/shaders/vertex.vert", GL_VERTEX_SHADER);
	m_BaseFrag = Framework::Shader("res/shaders/fragment.frag", GL_FRAGMENT_SHADER);

	m_ShaderProgram.CreateShader(m_BaseVertex);
	m_ShaderProgram.CreateShader(m_BaseFrag);
	m_ShaderProgram.Link();

	m_FBO.InitialiseFramebuffer(1000, 700);
	m_Triangle.InitTriangle();
}

void Framework::Scene::ProcessInput()
{

}

void Framework::Scene::Update(double deltaTime)
{

}

void Framework::Scene::Render()
{
	m_FBO.Bind();
	m_Triangle.RenderTriangle(m_ShaderProgram);
	m_FBO.Unbind();
}
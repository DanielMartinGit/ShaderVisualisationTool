#include "Scene.h"

Framework::Scene::Scene() {}
Framework::Scene::~Scene() {}

void Framework::Scene::InitScene()
{
	Framework::Shader baseVertex = Framework::Shader("res/shaders/vertex.vert", GL_VERTEX_SHADER);
	Framework::Shader baseFrag = Framework::Shader("res/shaders/fragment.frag", GL_FRAGMENT_SHADER);

	m_ShaderProgram.CreateShader(baseVertex);
	m_ShaderProgram.CreateShader(baseFrag);
	m_ShaderProgram.Link();

	m_FBO.InitialiseFramebuffer(2000, 700);
	m_Triangle.Init();
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
	m_WireframeMode ? glPolygonMode(GL_FRONT_AND_BACK, GL_LINE) : glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	m_Triangle.Render(m_ShaderProgram);
	m_FBO.Unbind();
}
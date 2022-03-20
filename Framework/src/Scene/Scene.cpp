#include "Scene.h"

Framework::Scene::Scene() {}
Framework::Scene::~Scene() {}

void Framework::Scene::InitScene()
{

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

	m_FBO.Unbind();
}
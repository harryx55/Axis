#include "pch.h"
#include "Renderer.h"



namespace Axis
{
	Renderer::SceneData* Renderer::m_sceneData = (SceneData*)malloc(sizeof(m_sceneData));
	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		m_sceneData->viewProjectionMatrix = camera.viewProjection;
	}


	void Renderer::Submit(OpenGLShaders& shader, OpenGLBufferObject& buffer)
	{
		shader.bind();
		// shader.SetUnifromMatrix4("viewProjection", m_sceneData->viewProjectionMatrix);

		RenderCommand::DrawIndexed(buffer);
	}

	void Renderer::EndScene()
	{
	}
}
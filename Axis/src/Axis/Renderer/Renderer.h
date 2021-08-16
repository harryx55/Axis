#pragma once

#include "OpenGL/OpenGLShaders.h"
#include "RenderCommand.h"
#include "Cameras.h"


namespace Axis
{
	struct Renderer
	{
		static void BeginScene(OrthographicCamera& camera);
		static void Submit(OpenGLShaders& shader, OpenGLBufferObject& buffer);
		static void EndScene();

		struct SceneData
		{
			glm::mat4 viewProjectionMatrix;
		};

		static SceneData* m_sceneData;
	};
}
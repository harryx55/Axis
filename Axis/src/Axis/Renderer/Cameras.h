#pragma once
#include <glm/glm.hpp>

namespace Axis
{
	struct OrthographicCamera
	{
		void InitCamera(float left, float right, float bottom, float top);

		glm::mat4 viewProjection;
		glm::mat4 projection;
		glm::mat4 view;

		glm::vec3 position = { 0.0f, 0.0f, 0.0f };
	};
}
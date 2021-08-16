#include "pch.h"

#include "Cameras.h"
#include <glm/gtc/matrix_transform.hpp>


namespace Axis
{
	void OrthographicCamera::InitCamera(float left, float right, float bottom, float top)
	{
		projection = glm::ortho(left, right, bottom, top);
		view = glm::translate(glm::mat4(1.0f), glm::vec3(1.0f));

		viewProjection = projection * view;
	}
}
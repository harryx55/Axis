#pragma once
#include "Layer.h"


namespace Axis
{
	class AXIS_API ImguiLayer : public ILayer
	{
	public:
		ImguiLayer();
		~ImguiLayer();

		void OnUpdate();
		void OnAttach();
		void OnDetach();
	};
}
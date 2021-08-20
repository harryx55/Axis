#pragma once
#include "Layer.h"


namespace Axis
{
	class AXIS_API ImguiLayer : public ILayer
	{
	public:
		ImguiLayer();
		~ImguiLayer();

		virtual void OnUpdate(Timestep timestep) override;
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImguiRender() override;

		void Begin();
		void End();
	};
}
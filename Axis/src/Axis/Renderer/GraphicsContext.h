#pragma once


namespace Axis
{
	class GraphcsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};
}
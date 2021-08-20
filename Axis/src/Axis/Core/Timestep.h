#pragma once


namespace Axis
{
	struct Timestep
	{
		Timestep(float time = 0.0f)
			: m_Time(time)
		{

		}

		inline float GetSeconds() { return m_Time; }
		inline float GetMilliSeconds() { return m_Time * 1000.0f; }
		float m_Time;
	private:
	};
}
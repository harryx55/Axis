#pragma once

#include "Core.h"
#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"



namespace Axis {
	class AXIS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


#define AX_CORE_TRACE(...)	 ::Axis::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AX_CORE_ERROR(...)	 ::Axis::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AX_CORE_WARN(...)	 ::Axis::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AX_CORE_INFO(...)	 ::Axis::Log::GetCoreLogger()->info(__VA_ARGS__)

#define AX_TRACE(...)		 ::Axis::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AX_ERROR(...)		 ::Axis::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AX_WARN(...)		 ::Axis::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AX_INFO(...)		 ::Axis::Log::GetClientLogger()->info(__VA_ARGS__)

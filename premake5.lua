workspace "Axis"
	 architecture "x64"

	  configurations
	  {
		"Debug",
		"Released",
		"Dist"
	  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
-- IncludeDir ["GLFW"] = "Axis/vendor/GLFW/include"
-- IncludeDir ["Glad"] = "Axis/vendor/GLAD/include"
IncludeDir ["ImGui"] = "Axis/vendor/ImGui"

-- include "Axis/vendor/GLFW"
-- include "Axis/vendor/Glad"
include "Axis/vendor/ImGui"

project "Axis"
	location "Axis"
	kind "Staticlib"
	language "c++"
	cppdialect "c++20"
	staticruntime "On"

	pchheader "pch.h"
	pchsource "Axis/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp",

		"%{prj.name}/src/Axis/**.h",
		"%{prj.name}/src/Axis/**.hpp",
		"%{prj.name}/src/Axis/**.c",
		"%{prj.name}/src/Axis/**.cpp",

		"%{prj.name}/vendor/Glad/src/glad.c",

		-- GLFW
		"%{prj.name}/vendor/Glfw/src/context.c",
		"%{prj.name}/vendor/Glfw/src/egl_context.c",
		"%{prj.name}/vendor/Glfw/src/init.c",
		"%{prj.name}/vendor/Glfw/src/input.c",
		"%{prj.name}/vendor/Glfw/src/osmesa_context.c",
		"%{prj.name}/vendor/Glfw/src/vulkan.c",
		"%{prj.name}/vendor/Glfw/src/wgl_context.c",
		"%{prj.name}/vendor/Glfw/src/win32_init.c",
		"%{prj.name}/vendor/Glfw/src/win32_joystick.c",
		"%{prj.name}/vendor/Glfw/src/win32_monitor.c",
		"%{prj.name}/vendor/Glfw/src/win32_thread.c",
		"%{prj.name}/vendor/Glfw/src/win32_time.c",
		"%{prj.name}/vendor/Glfw/src/win32_window.c",
		"%{prj.name}/vendor/Glfw/src/window.c"
	}

	filter "%{prj.name}/vendor/Glad/src/**.c"
	flags
	{
	   "NoPCH"
	}

	filter "%{prj.name}/vendor/Glfw/src/**.c"
	flags
	{
	   "NoPCH"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/src/Axis",
		"%{prj.name}/src/Axis/Core",
		"%{prj.name}/vendor/spdlog/include",

		"%{prj.name}/vendor/Glad/include",
		"%{prj.name}/vendor/ImGui",
		"%{prj.name}/vendor/Glfw/include",

		"%{prj.name}/vendor/glm"

	}

	links 
	{
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"AXIS_BUILD_DLL",
			"AXIS_PLATFORM_WINDOWS",
			"AXIS_ENABLE_ASSERT",
			"_CRT_SECURE_NO_WARNINGS",
			"_WINDLL",
			"_GLFW_WIN32"
		}

		filter "configurations:Debug"
			defines "AX_DEBUG"
			symbols "On"
			targetdir ("Debug/bin-out/" .. outputdir .. "/%{prj.name}")
			objdir ("Debug/bin-int/" .. outputdir .. "/%{prj.name}")


		filter "configurations:Release"
			defines "AX_RELEASE"
			optimize "On"
			targetdir ("Release/bin-out/" .. outputdir .. "/%{prj.name}")
			objdir ("Release/bin-int/" .. outputdir .. "/%{prj.name}")


		filter "configurations:Dist"
			defines "AX_DIST"
			optimize "On"
			targetdir ("Dist/bin-out/" .. outputdir .. "/%{prj.name}")
			objdir ("Dist/bin-int/" .. outputdir .. "/%{prj.name}")


project "Sandbox"

	location "Sandbox"
	kind "ConsoleApp"
	language "c++"
	cppdialect "c++17"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Axis/src",
		"Axis/src/Axis",
		"Axis/vendor/spdlog/include",

		"Axis/vendor/glm",
		"Axis/vendor/GLFW/include",
		"Axis/vendor/Glad/include"
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AXIS_PLATFORM_WINDOWS",
			"AXIS_ENABLE_ASSERT",
			"GLFW_INCLUDE_NONE"
		}

		links
		{
			"Axis"
		}

		filter "configurations:Debug"
			defines "AX_DEBUG"
			symbols "On"
			targetdir ("Debug/bin-out/" .. outputdir .. "/%{prj.name}")
			objdir ("Debug/bin-int/" .. outputdir .. "/%{prj.name}")

		filter "configurations:Release"
			defines "AX_RELEASE"
			optimize "On"
			targetdir ("Release/bin-out/" .. outputdir .. "/%{prj.name}")
			objdir ("Release/bin-int/" .. outputdir .. "/%{prj.name}")

		filter "configurations:Dist"
			defines "AX_DIST"
			optimize "On"
			targetdir ("Dist/bin-out/" .. outputdir .. "/%{prj.name}")
			objdir ("Dist/bin-int/" .. outputdir .. "/%{prj.name}")

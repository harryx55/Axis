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
IncludeDir ["GLFW"] = "Axis/vendor/GLFW/include"
IncludeDir ["Glad"] = "Axis/vendor/GLAD/include"
IncludeDir ["ImGui"] = "Axis/vendor/ImGui"

include "Axis/vendor/GLFW"
include "Axis/vendor/Glad"
include "Axis/vendor/ImGui"

project "Axis"
	location "Axis"
	kind "Staticlib"
	language "c++"
	cppdialect "c++17"
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
		"%{prj.name}/src/Axis/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/src/Axis",
		"%{prj.name}/vendor/spdlog/include",

		"%{prj.name}/vendor/Glad/include",
		"%{prj.name}/vendor/ImGui",
		"%{prj.name}/vendor/GLFW/include",

		"%{prj.name}/vendor/glm"

	}

	links 
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"AXIS_BUILD_DLL",
			"AXIS_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE",
			"AXIS_ENABLE_ASSERT",
			"_CRT_SECURE_NO_WARNINGS",
			"_WINDLL"
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
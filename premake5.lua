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
IncludeDir ["IMGUI"] = "Axis/vendor/ImGui"

include "Axis/vendor/GLFW"
include "Axis/vendor/Glad"
include "Axis/vendor/ImGui"

project "Axis"
	location "Axis"
	kind "sharedlib"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediate/" .. outputdir .. "/%{prj.name}")

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

	buildoptions
	{
		"/MDd"
	}

	linkoptions
	{
		"/INCREMENTAL"
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
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AXIS_BUILD_DLL",
			"AXIS_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE",
			"AXIS_ENABLE_ASSERT",
			"_WINDLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "AX_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "AX_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "AX_DIST"
			optimize "On"

project "Sandbox"

	location "Sandbox"
	kind "ConsoleApp"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediate/" .. outputdir .. "/%{prj.name}")

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

		"Axis/vendor/GLFW/include",
		"Axis/vendor/glm"
	}


	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AXIS_PLATFORM_WINDOWS",
			"AXIS_ENABLE_ASSERT"
		}

		links
		{
			"Axis"
		}

		filter "configurations:Debug"
			defines "AX_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "AX_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "AX_DIST"
			optimize "On"
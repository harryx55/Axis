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
	kind "sharedlib"
	language "c++"

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

		filter "configurations:Debug"
			defines "AX_DEBUG"
			symbols "On"
			targetdir ("Debug/bin-out/" .. outputdir .. "/%{prj.name}")
			objdir ("Debug/bin-int/" .. outputdir .. "/%{prj.name}")
			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../Debug/bin-out/" .. outputdir .. "/Sandbox")
			}

		filter "configurations:Release"
			defines "AX_RELEASE"
			optimize "On"
			targetdir ("Release/bin-out/" .. outputdir .. "/%{prj.name}")
			objdir ("Release/bin-int/" .. outputdir .. "/%{prj.name}")
			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../Release/bin-out/" .. outputdir .. "/Sandbox")
			}

		filter "configurations:Dist"
			defines "AX_DIST"
			optimize "On"
			targetdir ("Dist/bin-out/" .. outputdir .. "/%{prj.name}")
			objdir ("Dist/bin-int/" .. outputdir .. "/%{prj.name}")
			postbuildcommands
			{
				("{COPY} %{cfg.buildtarget.relpath} ../Dist/bin-out/" .. outputdir .. "/Sandbox")
			}

project "Sandbox"

	location "Sandbox"
	kind "ConsoleApp"
	language "c++"

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
		"Axis/vendor/GLFW/include"
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
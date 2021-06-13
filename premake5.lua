workspace "Axis"
	 architecture "x64"

	  configurations
	  {
		"Debug",
		"Released",
		"Dist"
	  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir ["GLFW"] = "Axis/vendor/GLFW/include"

include "Axis/vendor/GLFW"

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
		"/MD"
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

		"{IncludeDir.GLFW}",
		"%{prj.name}/vendor/GLFW/include"
	}

	links 
	{
		"GLFW",
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

		"Axis/vendor/GLFW/include"
	}


	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"AXIS_PLATFORM_WINDOWS"
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
workspace "Axis"
	  architecture "x64"

	  configurations
	  {
		"Debug",
		"Released",
		"Dist"
	  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Axis"
	location "Axis"
	kind "sharedlib"
	language "c++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-intermediate/" .. outputdir .. "/%{prj.name}")

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
		"%{prj.name}/vendor/spdlog/include"
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
		"Axis/vendor/spdlog/include"
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
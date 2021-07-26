project "GLAD"
	kind "staticLib"
	language "c"
	cppdialect "c++17"
	staticruntime "On"

	files
	{
		"src/glad.c"
	}

	includedirs
	{
		"include"
	}

	filter "system:windows"
		systemversion "latest"

		filter "configurations:Debug"
				targetdir("Debug/bin/" .. outputdir .. "/%{prj.name}")
				targetdir("Debug/bin-int/" .. outputdir .. "/%{prj.name}")

		filter "configurations:Release"
				targetdir("Release/bin/" .. outputdir .. "/%{prj.name}")
				targetdir("Release/bin-int/" .. outputdir .. "/%{prj.name}")

		filter "configurations:Dist"
				targetdir("Dist/bin/" .. outputdir .. "/%{prj.name}")
				targetdir("Dist/bin-int/" .. outputdir .. "/%{prj.name}")

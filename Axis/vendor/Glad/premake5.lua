project "GLAD"
	kind "staticLib"
	language "c"

	files
	{
		"include/glad/glad.h",
		"include/glad/Khrplatform.h",
		"src/glad.c"
	}

	includedirs
	{
		"include"
	}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		filter { "system:windows", "configurations:release" }
		buildoptions "/MT"

		filter "configurations:Debug"
				targetdir("Debug/bin/" .. outputdir .. "/%{prj.name}")
				targetdir("Debug/bin-int/" .. outputdir .. "/%{prj.name}")

		filter "configurations:Release"
				targetdir("Release/bin/" .. outputdir .. "/%{prj.name}")
				targetdir("Release/bin-int/" .. outputdir .. "/%{prj.name}")

		filter "configurations:Dist"
				targetdir("Dist/bin/" .. outputdir .. "/%{prj.name}")
				targetdir("Dist/bin-int/" .. outputdir .. "/%{prj.name}")

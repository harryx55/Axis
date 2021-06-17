project "GLAD"
	kind "staticLib"
	language "c"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	targetdir("bin-intermediate/" .. outputdir .. "/%{prj.name}")

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
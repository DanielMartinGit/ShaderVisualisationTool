workspace("ShaderVisualisationTool")
  architecture "x64"

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

configurations
{
  "Debug",
  "Release"
}

project "Framework"
	location "Framework"
	kind "StaticLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.c",
		"%{prj.name}/**.cpp",
		"%{prj.name}/**.hpp",
		"%{prj.name}/**.inl",
		"%{prj.name}/**.dll",
		"%{prj.name}/**.lib",
	}

	includedirs
	{
		"%prj.name/Vendor/GLAD/",
		"%prj.name/Vendor/GLAD/KHR/",
		"%prj.name/Vendor/GLFW/",
		"%prj.name/Vendor/ImGui/",
		"%prj.name/Vendor/STB/",
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines {}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Editor"),
			("{COPY} %{cfg.buildtarget.relpath} ../Framework/Vendor/Libraries/Framework")
		}

	filter "configurations.Debug"
		symbols "On"

	filter "configurations.Release"
		optimize "On"

	filter { "system:windows", "configurations:Debug"}
		buildoptions "/MDd"
	filter { "system:windows", "configurations:Release"}
		buildoptions "/MD"

project "GUI"
	location "GUI"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/**.h",
		"%{prj.name}/**.cpp"
	}

	libdirs
	{
		"Framework/Vendor/Libraries/GLFW",
		"Frmework/Vendor/Libraries/Framework"
	}

	links
	{
		"Framework",
		"glfw3"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "10.0.19041.0"

	filter "configurations.Debug"
		symbols "On"

	filter "configurations.Release"
		optimize "On"

	filter { "system:windows", "configurations:Debug"}
		buildoptions "/MDd"
	filter { "system:windows", "configurations:Release"}
		buildoptions "/MD"

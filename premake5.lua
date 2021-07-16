workspace "SkyEngine"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SkyCore"
    location "SkyCore"
    kind "SharedLib"

    targetname "skycore"
    language "C++"
    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "%{prj.name}/**.cpp",
        "%{prj.name}/**.h",
        "%{prj.name}/**.c",
        "%{prj.name}/**.m",
    }

    removefiles {
        "%{prj.name}/vendor/glfw/**.c",
        "%{prj.name}/vendor/glfw/**.h",
        "%{prj.name}/vendor/glfw/**.m",
        "%{prj.name}/vendor/glfw/**.cpp",
    }
    includedirs {
        "%{prj.name}/src/**/",
        "%{prj.name}/src/",
        "%{prj.name}/vendor/glad/**/"
    }

    links {
        "glfw3"
    }
    
    filter "configurations:Debug"
        symbols "On"
        defines
        {
            "SKY_DEBUG"
        }
    
    filter "configurations:Release"
        optimize "On"

        defines
        {
            "SKY_RELEASE"
        }
    
    filter "configurations:Dist"
        optimize "On"

        defines
        {
            "SKY_DIST"
        }
    
    filter "system:Windows"
        defines
        {
            "SKY_WINDOWS"
        }
    
    filter "system:Linux"
        defines
        {
            "SKY_LINUX"
        }
        
    filter "system:Darwin"
        defines
        {
            "SKY_MAC"
        }
    filter { "configurations:Debug", "system:Windows" }
        buildoptions "/MTd"
    
    filter { "configurations:Release", "system:Windows" }
        buildoptions "/MT"

    filter { "configurations:Dist", "system:Windows" }
        buildoptions "/MT"

project "SkyEditor"
    location "SkyEditor"
    kind "ConsoleApp"
    
    targetname "skyeditor"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
    
    
    files {
        "%{prj.name}/**.cpp",
        "%{prj.name}/**.h",
        "%{prj.name}/**.c",
        "%{prj.name}/**.m",
    }
    includedirs {
        "%{prj.name}/**/"
    }

    filter "configurations:Debug"
        symbols "On"
        defines
        {
            "SKY_DEBUG"
        }
    
    filter "configurations:Release"
        optimize "On"

        defines
        {
            "SKY_RELEASE"
        }
    
    filter "configurations:Dist"
        optimize "On"

        defines
        {
            "SKY_DIST"
        }

    filter "system:Windows"
        defines
        {
            "SKY_WINDOWS"
        }
    
    filter "system:Linux"
        defines
        {
            "SKY_LINUX"
        }
        
    filter "system:Darwin"
        defines
        {
            "SKY_MAC"
        }
    filter { "configurations:Debug", "system:Windows" }
        buildoptions "/MTd"
    
    filter { "configurations:Release", "system:Windows" }
        buildoptions "/MT"

    filter { "configurations:Dist", "system:Windows" }
        buildoptions "/MT"
        
newaction {
    trigger = "clean",
    description = "Remove all binaries, intermediate binaries and project files.",
    execute = function()
        print("Removing binaries...")
        os.rmdir("./bin")
        print("Removing intermediate binaries...")
        os.rmdir("./bin-int")
        print("Removing project files...")
        os.rmdir("./.vs")
        os.remove("**.sln")
        os.remove("**.vcsproj")
        os.remove("**.vcxproj.filters")
        os.remove("**.vcxproj.user")
        os.remove("Makefile")
        os.remove("**/Makefile")
        print ("Done!")
    end
}
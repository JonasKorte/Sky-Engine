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
        "%{prj.name}/vendor/glad/**.c",
        "%{prj.name}/vendor/glad/**.h",
    }
    includedirs {
        "%{prj.name}/src/**/",
        "%{prj.name}/src/",
        "%{prj.name}/vendor/glad/**/"
    }

    links {
        "glfw3",
        "pthread",
        "dl"
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

        libdirs {
            "/vendor/libglfw"
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
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.c",
        "%{prj.name}/src/**.m",
    }

    includedirs {
        "%{prj.name}/src/**/",
        "%{prj.name}/src/",
        "SkyCore/vendor/glad/**/",
        "SkyCore/src/**",
        "SkyCore/src/",
    }

    links {
        "skycore",
        "glfw3",
        "pthread",
        "dl"
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

        libdirs {
            "/vendor/libglfw"
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
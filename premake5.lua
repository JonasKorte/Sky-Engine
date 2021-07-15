workspace "SkyEngine"
    configurations {
        "Debug",
        "Release",
        "Dist"
    }

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
        os.remove("MakeFile")
        print ("Done!")
}
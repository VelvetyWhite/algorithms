workspace "algorithms"
location("build/%{_ACTION}")
configurations { "Debug", "Release" }

filter "configurations:Debug"
    targetdir ( "build/%{_ACTION}/bin/debug" )
    defines { "DEBUG" }
    symbols "On"
filter "configurations:Release"
    targetdir ( "build/%{_ACTION}/bin/release" )
    defines { "NDEBUG" }
    optimize "On"

project "sortingAlg"
    kind "ConsoleApp"
    language "C++"
    files { "src/sortingAlg/**.h", "src/sortingAlg/**.cpp" }


project(newengine)
cmake_minimum_required(VERSION 3.0)

include_directories(src/engine extern src)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
add_compile_definitions(_CRT_SECURE_NO_WARNINGS)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	add_compile_options(-pipe)
endif()

add_subdirectory(extern/glfw)
add_subdirectory(extern/wxWidgets)
add_subdirectory(extern/glm)

FILE(GLOB_RECURSE engine_src CONFIGURE_DEPENDS "src/engine/*.cpp")
FILE(GLOB_RECURSE engine_hdr CONFIGURE_DEPENDS "src/engine/*.hpp")

# --- ENGINE
add_library(engine
	extern/glad/glad.c extern/glad/glad.h
	extern/stb/stb_image.c extern/stb/stb_image.h
	${engine_src} ${engine_hdr}
)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_compile_options(engine PRIVATE
		$<$<COMPILE_LANGUAGE:CXX>:-fpermissive -w>
	)
endif()

target_compile_definitions(engine PRIVATE BUILD_DLL)

target_link_libraries(engine glm)

target_include_directories(engine
	PRIVATE extern/glad
	PRIVATE extern/stb
)

# --- EDITOR
add_executable(editor src/editor/main.cpp src/engine/Engine.hpp)

if(WIN32)
	target_sources(editor PRIVATE extern/wxWidgets/include/wx/msw/wx.rc)
endif()

target_link_libraries(editor engine wx::core wx::base wx::gl)
set_target_properties(editor PROPERTIES WIN32_EXECUTABLE 1)

# --- PLAYER
add_executable(player src/player/main.cpp src/engine/Engine.hpp)
target_link_libraries(player engine glfw)
set_target_properties(player PROPERTIES WIN32_EXECUTABLE 1)
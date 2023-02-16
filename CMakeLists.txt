project(newengine)
cmake_minimum_required(VERSION 3.0)

include_directories(src/engine extern src)

add_subdirectory(extern/glfw)
add_subdirectory(extern/wxWidgets)

FILE(GLOB_RECURSE engine_src CONFIGURE_DEPENDS "src/engine/*.cpp")
FILE(GLOB_RECURSE engine_hdr CONFIGURE_DEPENDS "src/engine/*.hpp")

add_library(engine
	extern/glad/glad.c extern/glad/glad.h
	${engine_src} ${engine_hdr}
)
target_compile_options(engine PRIVATE
	$<$<COMPILE_LANGUAGE:CXX>:-fpermissive -std=gnu++2b -w>
)

add_executable(editor src/editor/main.cpp src/engine/Engine.hpp)
target_link_libraries(editor wx::core wx::base wx::gl engine)
set_target_properties(editor PROPERTIES WIN32_EXECUTABLE 1)

add_executable(player src/player/main.cpp src/engine/Engine.hpp)
target_link_libraries(player glfw engine)
set_target_properties(player PROPERTIES WIN32_EXECUTABLE 1)
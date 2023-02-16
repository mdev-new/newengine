project(newengine)
cmake_minimum_required(VERSION 3.0)

include_directories(src/engine extern src)

add_subdirectory(extern/glfw)
add_subdirectory(extern/wxWidgets)

add_library(engine
extern/glad/glad.c extern/glad/glad.h
src/engine/Engine.cpp src/engine/Engine.hpp
src/engine/assets/Asset.cpp src/engine/assets/Asset.hpp
src/engine/entities/Entity.cpp src/engine/entities/Entity.hpp
src/engine/input/InputManager.cpp src/engine/input/InputManager.hpp
src/engine/rendering/shaders/Shader.cpp src/engine/rendering/shaders/Shader.hpp
src/engine/rendering/textures/Texture.cpp src/engine/rendering/textures/Texture.hpp
src/engine/rendering/Renderer.cpp src/engine/rendering/Renderer.hpp
src/engine/rendering/VertexArray.cpp src/engine/rendering/VertexArray.hpp
src/engine/scenes/Scene.cpp src/engine/scenes/Scene.hpp
src/engine/scripting/lexer/Lexer.cpp src/engine/scripting/lexer/Lexer.hpp
src/engine/scripting/parser/Parser.cpp src/engine/scripting/parser/Parser.hpp
src/engine/scripting/Script.cpp src/engine/scripting/Script.hpp
src/engine/scripting/ScriptManager.cpp src/engine/scripting/ScriptManager.hpp
src/engine/utility/Files.cpp src/engine/utility/Files.hpp
src/engine/utility/Hashing.cpp src/engine/utility/Hashing.hpp
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
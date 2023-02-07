shopt -s globstar
g++ -shared -fPIC src/engine/**/*.cpp -Isrc/engine -Iextern -DMAKEDLL -o engine.so

g++ src/editor/*.cpp extern/glad/glad.c `wx-config --libs --cxxflags --gl-libs` -Iextern -Isrc -Isrc/engine -o editor.out -ggdb3 -Og ./engine.so
g++ src/player/*.cpp extern/glad/glad.c -Iextern -Isrc -Isrc/engine -o player.out -ggdb3 -Og -lglfw ./engine.so
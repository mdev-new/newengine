debugcflags="-pipe -Og -ggdb3"
release_sharedcflags="\
-static-libgcc -static-libstdc++ \
-pipe -Ofast -s -flto \
-march=native -mtune=native -msse -msse2 -msse4.2 -mavx -mavx2 -mmmx \
-fshort-enums -funsafe-math-optimizations -ftree-vectorize -ffast-math -ftree-slp-vectorize \
-fassociative-math -fcompare-debug-second -fno-stack-protector -fno-math-errno \
-fno-ident -fno-asynchronous-unwind-tables -fno-exceptions -ffunction-sections -fdata-sections \
-Wl,--gc-sections,--build-id=none \
"

release_exe_cflags="-fvisibility=hidden"

release_lib="$release_sharedcflags"
release_exe="$release_sharedcflags $release_exe_cflags"
debug_lib="$debugcflags"
debug_exe="$debugcflags"

config_lib="$debug_lib"
config_exe="$debug_exe"

shopt -s globstar
g++ -std=gnu++2b -shared -fPIC src/engine/**/*.cpp extern/glad/glad.c -Isrc/engine $config_lib -Iextern -DMAKEDLL -o libengine.so

#g++ src/editor/*.cpp extern/glad/glad.c `wx-config --libs --cxxflags --gl-libs` -Iextern -Isrc -Isrc/engine -o editor.out $config_exe ./engine.so
g++ -std=gnu++2b src/player/*.cpp -Iextern -Isrc -Isrc/engine -o player.out $config_exe -lglfw -L. -lengine
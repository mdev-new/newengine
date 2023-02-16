profile="release"

if [[ "$OSTYPE" == "msys" ]]; then
	so_pfx=""
	so_ext="dll"
	additional_editor_flags="-mwindows -Iwinlibs/wx/wx/include -Iwinlibs/wx/mswu -Lwinlibs/wx -lwxbase32u -lwxmsw32u_core -lwxmsw32u_gl -lopengl32"
	additional_player_flags="-mwindows -Iwinlibs -Iwinlibs/wx/include -Lwinlibs/wx -Lwinlibs -lglfw3 -lgdi32 -luser32 -lkernel32"
else
	so_pfx="lib"
	so_ext="so"
	additional_editor_flags="`wx-config --libs --cxxflags --gl-libs`"
	additional_player_flags="-lglfw"
fi

global="-std=gnu++2b -pipe -fpermissive -Iextern -Isrc/engine -Isrc -D_profile=$profile"

debugcflags="$global -Og -ggdb3"

release_sharedcflags="\
$global -DNDEBUG \
-static-libgcc -static-libstdc++ \
-Ofast -s -flto=auto -fuse-linker-plugin \
-march=native -mtune=native -msse -msse2 -msse4.2 -mavx -mavx2 -mmmx \
-fshort-enums -funsafe-math-optimizations -ftree-vectorize -ftree-slp-vectorize -ftree-loop-vectorize -ffast-math \
-fassociative-math -fcompare-debug-second -fno-stack-protector -fno-math-errno \
-fno-ident -fno-asynchronous-unwind-tables -fno-exceptions -ffunction-sections -fdata-sections \
-Wl,--gc-sections,--build-id=none \
"

release_exe_cflags="-fvisibility=hidden"

release_lib="$release_sharedcflags"
release_exe="$release_sharedcflags $release_exe_cflags"
debug_lib="$debugcflags"
debug_exe="$debugcflags"

eval config_lib="\$${profile}_lib"
eval config_exe="\$${profile}_exe"

if [[ "$OSTYPE" == "msys" ]]; then
	if [[ "$profile" == "release" ]]; then
		editorflags="$global -O2 -s -flto=auto -fuse-linker-plugin -static-libgcc -static-libstdc++"
	else
		editorflags="$config_exe"
	fi
else
	editorflags="$config_exe"
fi

shopt -s globstar
g++ -shared -fPIC src/engine/**/*.cpp extern/glad/glad.c $config_lib -o ${so_pfx}engine.$so_ext

g++ -o editor.exe src/editor/*.cpp $editorflags $additional_editor_flags -L. -lengine
g++ -o player.exe src/player/*.cpp $config_exe $additional_player_flags -L. -lengine
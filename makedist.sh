mkdir -p distribution
cd distribution
cp ../build/*.exe .
cp ../build/*.dll .
cp ../build/extern/glfw/src/glfw3.dll .
cp ../build/extern/wxWidgets/lib/gcc_x64_dll/{wxbase330u_gcc,wxmsw330u_gl_gcc,wxmsw330u_core_gcc}.dll .
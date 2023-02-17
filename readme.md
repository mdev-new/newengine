# newengine rewrite

## dependencies
- Cmake
- wxwidgets's dependencies for your os and gui platform


## building
```
mkdir build && cd build
cmake -DBUILD_SHARED_LIBS=ON -DCMAKE_BUILD_TYPE=Release -DGLFW_BUILD_DOCS=OFF -DGLFW_BUILD_EXAMPLES=OFF -DGLFW_BUILD_TESTS=OFF -DGLFW_USE_HYBRID_HPG=ON -DwxBUILD_BENCHMARKS=OFF -DwxBUILD_CXX_STANDARD=20 -DwxBUILD_INSTALL=OFF -DwxBUILD_MONOLITHIC=OFF -DwxBUILD_SAMPLES=OFF -DwxBUILD_SHARED=ON -DwxBUILD_TESTS=OFF -GNinja ..
cmake --build .
```
These flags are known to work
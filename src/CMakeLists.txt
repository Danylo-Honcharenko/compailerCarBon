set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/dist/compailerCarbon) 

add_executable(compailerCarbon "compailerCarbon.cpp" "compailerCarbon.h" "panelFu.cpp" "compilation.cpp" "checkerr.cpp" "error.cpp")


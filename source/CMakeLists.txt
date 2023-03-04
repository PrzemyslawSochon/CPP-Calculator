# source/CMakeLists.txt

cmake_minimum_required(VERSION 3.20)

# apparently, CMake doesn't always honor CMAKE_GENERATOR var
# to make sure that you're running ninja, use `cmake -GNinja`
set(CMAKE_GENERATOR "Ninja")

project(Calculator VERSION 0.7)

# project supports C++2017 and above
# to specify version run `-DCPP_VERSION_TEST_CXX_STANDARD=20`
set(CPP_VERSION_TEST_CXX_STANDARD "20" CACHE STRING "Language standard")
set(ALLOWED_CPP_VERSION STRING "17;20;23;2017;2020;2023")
set_property(CACHE CPP_VERSION_TEST_CXX_STANDARD PROPERTY STRINGS ${ALLOWED_CPP_VERSION})

if(NOT CPP_VERSION_TEST_CXX_STANDARD IN_LIST ALLOWED_CPP_VERSION)
    message(STATUS "Invalid value ${CPP_VERSION_TEST_CXX_STANDARD}. Allowed values are: ${ALLOWED_CPP_VERSION}")
    message(STATUS "Setting standard to C++2017...")
    set(CPP_VERSION_TEST_CXX_STANDARD "17")
endif()

set(CMAKE_CXX_STANDARD ${CPP_VERSION_TEST_CXX_STANDARD})
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set up the Clang compiler
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
set(CMAKE_CXX_CLANG_TIDY 
  clang-tidy;
  -header-filter=.;
  -checks=*;)


add_library(compiler_flags INTERFACE)
target_compile_features(compiler_flags INTERFACE cxx_std_17)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(compiler_flags INTERFACE
    "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
    "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

add_subdirectory(cpp-version-test)
add_subdirectory(equation-standard)
add_subdirectory(equation-solution)
add_subdirectory(gui)

add_executable(Calculator main.cpp shared.cpp)

target_link_libraries(Calculator PUBLIC compiler_flags EquationStandard EquationSolution CalculatorGui)

target_include_directories(Calculator PUBLIC
    "${PROJECT_BINARY_DIR}"
)

set_target_properties(Calculator PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../binary")

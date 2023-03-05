# source/CMakeLists.txt

cmake_minimum_required(VERSION 3.20)

# apparently, CMake doesn't always honor CMAKE_GENERATOR var
# to make sure that you're running ninja, use `cmake -GNinja`
set(CMAKE_GENERATOR "Ninja")

project(Calculator VERSION 0.7)

set(CMAKE_BUILD_TYPE Release)

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

# Set up the Clang compiler with clang-tidy
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang++)
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
 set(CMAKE_CXX_CLANG_TIDY
    clang-tidy
    -header-filter=.;
    -checks=boost-use-to-string,bugprone-argument-comment,bugprone-bool-pointer-implicit-conversion,bugprone-copy-constructor-init,bugprone-implicit-widening-of-multiplication-result,bugprone-inaccurate-erase,bugprone-misplaced-operator-in-strlen-in-alloc,bugprone-misplaced-pointer-arithmetic-in-alloc,bugprone-move-forwarding-reference,bugprone-not-null-terminated-result,bugprone-parent-virtual-call,bugprone-posix-return,bugprone-redundant-branch-condition,bugprone-reserved-identifier,bugprone-shared-ptr-array-mismatch,bugprone-standalone-empty,bugprone-string-constructor,bugprone-string-integer-assignment,bugprone-stringview-nullptr,bugprone-suspicious-memset-usage,bugprone-suspicious-semicolon,bugprone-suspicious-string-compare,bugprone-swapped-arguments,bugprone-terminating-continue,bugprone-unused-raii,bugprone-virtual-near-miss,cert-dcl21-cpp,misc-definitions-in-headers,misc-redundant-expression,misc-static-assert,misc-unused-alias-decls,misc-unused-parameters,misc-unused-using-decls,modernize-avoid-bind,modernize-concat-nested-namespaces,modernize-deprecated-headers,modernize-deprecated-ios-base-aliases,modernize-loop-convert,modernize-macro-to-enum,modernize-pass-by-value,modernize-raw-string-literal,modernize-redundant-void-arg,objc-assert-equals,objc-nsinvocation-argument-lifetime,objc-property-declaration,objc-super-self,performance-faster-string-find,performance-for-range-copy,performance-inefficient-algorithm,performance-inefficient-vector-operation,performance-move-const-arg,performance-noexcept-move-constructor,performance-trivially-destructible,performance-type-promotion-in-math-fn,performance-unnecessary-copy-initialization,performance-unnecessary-value-param,portability-restrict-system-includes;
 )
endif()

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

# set_target_properties(Calculator PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../binary")

# installation
# set library location via linker
add_link_options(-Wl,-rpath=/usr/local/lib)

set(installable_libs compiler_flags EquationStandard EquationSolution CalculatorGui)
install(TARGETS ${installable_libs} DESTINATION lib)

install(TARGETS Calculator DESTINATION bin/cpp-calculator)
install(FILES gui/config.json DESTINATION bin/cpp-calculator)

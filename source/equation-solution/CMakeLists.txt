add_library(EquationSolution solve-step-by-step.cpp)

target_include_directories(EquationSolution
                           INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>
                           )

target_link_libraries(EquationSolution PRIVATE compiler_flags)
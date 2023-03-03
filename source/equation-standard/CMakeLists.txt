add_library(EquationStandard equation-check.cpp equation-fix.cpp)

target_include_directories(EquationStandard
                           INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>
                           )

target_link_libraries(EquationStandard PRIVATE compiler_flags)

if(CMAKE_CXX_STANDARD GREATER_EQUAL 20)
    message("C++20 choosen, building test-cpp20")
    add_library(cpp-version-test OBJECT cpp2020/test-cpp20.cpp)
else()
    message("C++20 not choosen, building test-cpp17")
    add_library(cpp-version-test OBJECT cpp2017/test-cpp17.cpp)
endif()

target_include_directories(cpp-version-test
                           INTERFACE
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                            $<INSTALL_INTERFACE:include>
                           )
                           
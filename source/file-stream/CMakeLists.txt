find_package(nlohmann_json 3.11.2 REQUIRED)

add_library(FileStream utils.cpp)
target_link_libraries(FileStream PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(FileStream INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)


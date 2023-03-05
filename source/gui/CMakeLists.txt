set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(nlohmann_json 3.11.2 REQUIRED)
find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)

file(GLOB_RECURSE SRC_FILES "*.cpp")
file(GLOB_RECURSE HDR_FILES "*.hpp")

file(GLOB_RECURSE JSON_FILES "*.json")

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# List all the .ui files
file(GLOB UI_FILES *.ui)

# Generate .h files from .ui files
qt6_wrap_ui(UI_HEADERS ${UI_FILES})

add_library(CalculatorGui SHARED ${SRC_FILES} ${HDR_FILES} ${JSON_FILES} ${UI_FILES})

target_include_directories(CalculatorGui INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>)

target_link_libraries(CalculatorGui PUBLIC nlohmann_json::nlohmann_json)
target_link_libraries(CalculatorGui PRIVATE EquationSolution)
target_link_libraries(CalculatorGui PRIVATE EquationStandard)
target_link_libraries(CalculatorGui PUBLIC compiler_flags)
target_link_libraries(CalculatorGui PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)

set_target_properties(CalculatorGui PROPERTIES OUTPUT_NAME "CalculatorGui" VERSION ${PROJECT_VERSION} SOVERSION ${PROJECT_VERSION_MAJOR})

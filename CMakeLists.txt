# CMakeList.txt : CMake project for phluyd-studio, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("phluyd-studio")

# Add source to this project's executable.
add_executable (phluyd-studio 
	# Source files
    "src/main.cpp"
    "physics/src/verlet_solver.cpp"

	#Header files
    "include/main.hpp"
    "physics/include/vec2d.hpp"
    "physics/include/moving_object.hpp"
    "physics/include/verlet_solver.hpp")

if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(TARGET_ARCHITECTURE x64)
else()
    set(TARGET_ARCHITECTURE x86)
endif()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED) 

target_include_directories(phluyd-studio
    PUBLIC ${SDL2_INCLUDE_DIRS}
    PUBLIC ${SDL2IMAGE_INCLUDE_DIRS}
)

if(WIN32 AND NOT MSVC)
    target_link_libraries(phluyd-studio PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image mingw32)
else()
    target_link_libraries(phluyd-studio PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image)
endif()

file(GLOB BUILD_DLLS
    "dependencies/runtime/*.dll"
)

# add_custom_command(
#   TARGET ${PROJECT_NAME} POST_BUILD
#   COMMAND ${CMAKE_COMMAND} -E copy 
#     ${BUILD_DLLS}
#     $<TARGET_FILE_DIR:${PROJECT_NAME}>
# )

file(GLOB BUILD_ASSETS
    "assets/*.png"
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    ${BUILD_ASSETS}
    $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET phluyd-studio PROPERTY CXX_STANDARD 20)
endif()

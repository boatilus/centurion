cmake_minimum_required(VERSION 3.15)

# ---- Project ----

# Note: update this to your new project's name and version
project(centuron 
  VERSION 7.3.0
  HOMEPAGE_URL "https://github.com/albin-johansson/centurion"
  LANGUAGES CXX
)

if (${CMAKE_CXX_STANDARD} STREQUAL "")
  set(CMAKE_CXX_STANDARD 17)
endif ()

# ---- Include guards ----

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.")
endif()

# --- Import tools ----

include(cmake/tools.cmake)

# ---- Add dependencies via CPM ----
# see https://github.com/TheLartians/CPM.cmake for more info

include(cmake/CPM.cmake)

# PackageProject.cmake will be used to make our target installable
CPMAddPackage(
  NAME PackageProject.cmake
  GITHUB_REPOSITORY TheLartians/PackageProject.cmake
  VERSION 1.0
)

# ---- Add source files ----

FILE(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp")

# ---- Create library ----

add_library(${PROJECT_NAME} INTERFACE)
set_target_properties(${PROJECT_NAME} PROPERTIES INTERFACE_COMPILE_FEATURES cxx_std_20)

# beeing a cross-platform target, we enforce enforce standards conformance on MSVC
target_compile_options(${PROJECT_NAME} INTERFACE "$<$<BOOL:${MSVC}>:/permissive->")

target_include_directories(${PROJECT_NAME}
INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}-${PROJECT_VERSION}>
)

# ---- Create an installable target ----
# this allows users to install and find the library via `find_package()`.

packageProject(
  NAME ${PROJECT_NAME}
  VERSION ${PROJECT_VERSION}
  BINARY_DIR ${PROJECT_BINARY_DIR}
  INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include
  INCLUDE_DESTINATION include/${PROJECT_NAME}-${PROJECT_VERSION}
)

option(USE_SDL2_IMAGE "Require SDL2_image" ON)
option(USE_SDL2_MIXER "Require SDL2_mixer" ON)
option(USE_SDL2_TTF "Require SDL2_ttf" ON)

# System dependencies
find_package(SDL2 REQUIRED)

# if (USE_SDL2_IMAGE)
#   find_package(SDL2_image REQUIRED)
# endif()

# if (USE_SDL2_MIXER)
#   find_package(SDL2_mixer REQUIRED)
# endif()

# if (USE_SDL2_TTF)
#   find_package(SDL2_ttf REQUIRED)
# endif()
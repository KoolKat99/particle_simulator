cmake_minimum_required(VERSION 3.15)
project(PS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Disable ALL non-graphics modules of SFML (Audio and Network)
set(SFML_BUILD_AUDIO OFF CACHE BOOL "Disable SFML Audio module" FORCE)
set(SFML_BUILD_NETWORK OFF CACHE BOOL "Disable SFML Network module" FORCE)
set(SFML_BUILD_WINDOW ON CACHE BOOL "Disable SFML Window module" FORCE)
set(SFML_BUILD_SYSTEM ON CACHE BOOL "Disable SFML System module" FORCE)
set(SFML_BUILD_GRAPHICS ON CACHE BOOL "Enable SFML Graphics module" FORCE)

# adding libraries
include(FetchContent)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)


# Define file extensions
set(file_extensions
    ".hpp"
    ".h"
    ".cpp"
    ".c"
)

# Get all files in the 'src' directory
file(GLOB src_directory "src/*")

# Initialize an empty list to store matching files
set(src_files)

# Iterate over each file in the directory
foreach(src_file IN LISTS src_directory)
    # Iterate over each file extension
    foreach(extension IN LISTS file_extensions)
        # Check if the file ends with the current extension
        if("${src_file}" MATCHES "${extension}$")
            # If it matches, add it to the list
            list(APPEND src_files "${src_file}")
            # Stop searching further extensions for this file
            break()
        endif()
    endforeach()
endforeach()

# Print the matched files
message(STATUS "Matched source files: ${src_files}")


add_executable(${PROJECT_NAME} ${src_files})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)


#lets test everything at the test directory level so improt gtest there


add_subdirectory(test)

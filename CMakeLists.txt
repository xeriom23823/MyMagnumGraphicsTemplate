#
# Copyright 2020 Nghia Truong <nghiatruong.vn@gmail.com>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

cmake_minimum_required(VERSION 3.5)
project(GraphicsTemplateApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/Externals/imgui" ${CMAKE_PREFIX_PATH})

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/Modules/" ${CMAKE_MODULE_PATH})
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/Externals/magnum-integration/modules" ${CMAKE_MODULE_PATH})

####################################################################################################
set_directory_properties(PROPERTIES CORRADE_USE_PEDANTIC_FLAGS ON)

# Add Assimp as a subproject
set(ASSIMP_BUILD_ASSIMP_TOOLS OFF CACHE BOOL "" FORCE)
set(ASSIMP_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(ASSIMP_NO_EXPORT ON CACHE BOOL "" FORCE)

# If you won't be accessing Assimp outside of the plugin, build it as static to
# have the plugin binary self-contained
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)

set(INJECT_DEBUG_POSTFIX OFF CACHE BOOL "" FORCE)
set(ASSIMP_INJECT_DEBUG_POSTFIX OFF CACHE BOOL "" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/Externals/assimp EXCLUDE_FROM_ALL)

# Add Corrade as a subproject
set(BUILD_DEPRECATED OFF CACHE BOOL "" FORCE)
set(BUILD_STATIC ON CACHE BOOL "" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/Externals/corrade EXCLUDE_FROM_ALL)

## Add openal-soft as a subproject
set(CMAKE_POSITION_INDEPENDENT_CODE ON) # needed if building dynamic libraries
set(WITH_AUDIO ON CACHE BOOL "" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/Externals/openal-soft EXCLUDE_FROM_ALL)

# Add GLFW as a subproject
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/Externals/glfw EXCLUDE_FROM_ALL)

# Add Magnum as a subproject
set(MAGNUM_BUILD_DEPRECATED OFF CACHE BOOL "" FORCE)
set(MAGNUM_BUILD_STATIC ON CACHE BOOL "" FORCE)
set(WITH_GLFWAPPLICATION ON CACHE BOOL "" FORCE)
set(WITH_ANYAUDIOIMPORTER ON CACHE BOOL "" FORCE)
set(WITH_ANYIMAGEIMPORTER ON CACHE BOOL "" FORCE)
set(WITH_ANYSCENEIMPORTER ON CACHE BOOL "" FORCE)
set(WITH_OBJIMPORTER ON CACHE BOOL "" FORCE)
set(WITH_WAVAUDIOIMPORTER ON CACHE BOOL "" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/Externals/magnum EXCLUDE_FROM_ALL)

# Add Magnum-integration as a subproject
set(WITH_IMGUI ON CACHE BOOL "" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/Externals/magnum-integration EXCLUDE_FROM_ALL)

# Add Magnum-plugins as a subproject
set(WITH_ASSIMPIMPORTER ON CACHE BOOL "" FORCE)
set(WITH_DRMP3AUDIOIMPORTER ON CACHE BOOL "" FORCE)
set(WITH_STBIMAGEIMPORTER ON CACHE BOOL "" FORCE)
set(WITH_STBVORBISAUDIOIMPORTER ON CACHE BOOL "" FORCE)
set(WITH_TINYGLTFIMPORTER ON CACHE BOOL "" FORCE)
add_subdirectory(${PROJECT_SOURCE_DIR}/Externals/magnum-plugins EXCLUDE_FROM_ALL)

####################################################################################################
include_directories(${PROJECT_SOURCE_DIR}/Externals/ImGuizmo)
include_directories(${PROJECT_SOURCE_DIR}/Source)

find_package(Corrade REQUIRED Main)
find_package(Magnum REQUIRED
    AnyAudioImporter
    AnySceneImporter
    AnyImageImporter
    Audio
    DebugTools
    GlfwApplication
    GL
    MeshTools
    ObjImporter
    Primitives
    SceneGraph
    Shaders
    Trade
    WavAudioImporter
)
find_package(MagnumIntegration REQUIRED ImGui)

find_package(MagnumPlugins REQUIRED
    DrMp3AudioImporter
    AssimpImporter
    StbImageImporter
    StbVorbisAudioImporter
    TinyGltfImporter)

file(GLOB_RECURSE H_FILES ${PROJECT_SOURCE_DIR}/Source/*.h)
file(GLOB_RECURSE CPP_FILES ${PROJECT_SOURCE_DIR}/Source/*.cpp)

add_executable(${PROJECT_NAME} WIN32
    ${PROJECT_SOURCE_DIR}/Externals/ImGuizmo/ImGuizmo.cpp
    ${H_FILES}
    ${CPP_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE
    Corrade::Main
    Magnum::Application
    Magnum::AnyAudioImporter
    Magnum::AnyImageImporter
    Magnum::AnySceneImporter
    Magnum::Audio
    Magnum::DebugTools
    Magnum::GL
    Magnum::Magnum
    Magnum::MeshTools
    Magnum::ObjImporter
    Magnum::Primitives
    Magnum::SceneGraph
    Magnum::Shaders
    Magnum::Trade
    Magnum::WavAudioImporter
    MagnumIntegration::ImGui
    MagnumPlugins::AssimpImporter
    MagnumPlugins::DrMp3AudioImporter
    MagnumPlugins::StbImageImporter
    MagnumPlugins::StbVorbisAudioImporter
    MagnumPlugins::TinyGltfImporter
)

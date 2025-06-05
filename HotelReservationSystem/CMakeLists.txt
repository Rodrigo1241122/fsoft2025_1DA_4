cmake_minimum_required(VERSION 3.22)
project(HotelReservationSystem)

set(CMAKE_CXX_STANDARD 17)

# Incluir todos os headers
include_directories(
    ${PROJECT_SOURCE_DIR}/headers
    ${PROJECT_SOURCE_DIR}/headers/controller
    ${PROJECT_SOURCE_DIR}/headers/data
    ${PROJECT_SOURCE_DIR}/headers/exceptions
    ${PROJECT_SOURCE_DIR}/headers/model
    ${PROJECT_SOURCE_DIR}/headers/utils
    ${PROJECT_SOURCE_DIR}/headers/views
)

# Incluir todos os sources
include_directories(
    ${PROJECT_SOURCE_DIR}/sources
    ${PROJECT_SOURCE_DIR}/sources/controller
    ${PROJECT_SOURCE_DIR}/sources/data
    ${PROJECT_SOURCE_DIR}/sources/exceptions
    ${PROJECT_SOURCE_DIR}/sources/model
    ${PROJECT_SOURCE_DIR}/sources/utils
    ${PROJECT_SOURCE_DIR}/sources/views
)

# Agrupar todos os ficheiros fonte
file(GLOB_RECURSE SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/sources/*.cpp
    ${PROJECT_SOURCE_DIR}/main.cpp
)

# Criar o executável
add_executable(HotelReservationSystem ${SOURCE_FILES})

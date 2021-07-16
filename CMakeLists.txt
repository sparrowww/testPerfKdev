cmake_minimum_required(VERSION 3.0)

set (PROJECT_NAME testPj)

project(${PROJECT_NAME})

set(HEADERS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCES_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src)
###############################################
include_directories(${HEADERS_DIRECTORY} ${SOURCES_DIRECTORY})
###############################################
set(HEADERS
${HEADERS_DIRECTORY}/ccout.hpp
${HEADERS_DIRECTORY}/testFile.hpp
)

##############################################

set(SOURCES
${SOURCES_DIRECTORY}/main.cpp
${SOURCES_DIRECTORY}/testFile.cpp
)

add_executable(${PROJECT_NAME}  ${HEADERS} ${SOURCES})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

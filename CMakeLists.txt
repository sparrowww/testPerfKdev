cmake_minimum_required(VERSION 3.0)

set (PROJECT_NAME testPj)

project(${PROJECT_NAME})

###############################################
set(LIBRARIES_TEST_PJ_NAME
pthread
)

set(HEADERS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(SOURCES_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src)
###############################################
include_directories(${HEADERS_DIRECTORY} ${SOURCES_DIRECTORY})
###############################################
set(HEADERS
${HEADERS_DIRECTORY}/ccout.hpp
${HEADERS_DIRECTORY}/testFile.hpp
${HEADERS_DIRECTORY}/testFile2.hpp
${HEADERS_DIRECTORY}/testFile3.hpp
)

##############################################

set(SOURCES
${SOURCES_DIRECTORY}/main.cpp
${SOURCES_DIRECTORY}/testFile.cpp
${SOURCES_DIRECTORY}/testFile2.cpp
${SOURCES_DIRECTORY}/testFile3.cpp
)

add_executable(${PROJECT_NAME}  ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${LIBRARIES_TEST_PJ_NAME})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

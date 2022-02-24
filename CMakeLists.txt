cmake_minimum_required(VERSION 3.5)

project(Algorithm-4th)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIRS ${PROJECT_SOURCE_DIR})
include_directories(${INCLUDE_DIRS})

aux_source_directory(${PROJECT_SOURCE_DIR}/utils UTILS_SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/chapter1 CHAPTER1_SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/chapter2 CHAPTER2_SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/chapter3 CHAPTER3_SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/chapter4 CHAPTER4_SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/chapter5 CHAPTER5_SRC_LIST)
set(SRC_LIST
    main.cpp
    ${UTILS_SRC_LIST}
    ${CHAPTER1_SRC_LIST}
    ${CHAPTER2_SRC_LIST}
    ${CHAPTER3_SRC_LIST}
    ${CHAPTER4_SRC_LIST}
    ${CHAPTER5_SRC_LIST})

message(STATUS "SRC_LIST:")
foreach(SRC_NAME ${SRC_LIST})
    message(STATUS ${SRC_NAME})
endforeach(SRC_NAME)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(algorithm_test ${SRC_LIST})
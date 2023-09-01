cmake_minimum_required(VERSION 3.15)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project ( testovoe_kode )

include( ${CMAKE_CURRENT_SOURCE_DIR}/cmakefunctions/Loader.cmake )
Loader( ${CMAKE_CURRENT_SOURCE_DIR} )

ADD_SUBDIRECTORY ( APP )
ADD_SUBDIRECTORY ( ObjectLib )

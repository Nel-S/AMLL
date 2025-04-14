cmake_minimum_required(VERSION 3.5)

if (TARGET amll)
	return()
endif()

project(amll)

if (NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()
if (WIN32)
	set(CMAKE_C_FLAGS "-D_WIN32")
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -fwrapv -ffast-math -Wall -Wextra -pedantic")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g3 -DDEBUG")

set(HEADERS
	enums.h
	src/abstractPRNG.h
	src/attribute.h
	src/entry.h
	src/pool.h
	src/table.h
	loot.h
)
set(SOURCES
	src/abstractPRNG.c
	src/attribute.c
	src/entry.c
	src/pool.c
	src/table.c
	loot.c
)

if (NOT TARGET chunkbiomes)
	add_subdirectory(chunkbiomes)
endif()

add_library(amllObjects OBJECT ${SOURCES})
set_property(TARGET amllObjects PROPERTY POSITION_INDEPENDENT_CODE 1)

add_library(amll SHARED $<TARGET_OBJECTS:amllObjects>)
add_library(amll_static STATIC $<TARGET_OBJECTS:amllObjects>)

target_link_libraries(amll PUBLIC chunkbiomes)
target_include_directories(amll PRIVATE HEADERS)

install(TARGETS amll amll_static DESTINATION lib)
install(FILES ${HEADERS} DESTINATION include)
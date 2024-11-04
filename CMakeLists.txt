cmake_minimum_required(VERSION 3.5)

project(
	LuaCAPITeste
	VERSION 0.0.1
	LANGUAGES C
)

file(COPY main.lua module.lua DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")

add_executable(LuaCAPITeste main.c)
target_include_directories(LuaCAPITeste PUBLIC .)
target_link_libraries(LuaCAPITeste PUBLIC m)

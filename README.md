# CLuaExample
Small example using C and Lua and integration of both. C calls a function from main.lua and Lua calls 2 functions from the C code and other from a lua module (module.lua).

This uses MiniLua (https://github.com/edubart/minilua), under MIT, instead of linking against Lua libraries for simplicity reasons, such as not needing to have those libraries installed first.

You can use CMake to build it.

This repository exists for reference purposes and as an example for anyone needing it, including myself. Do what you want, but keep in mind MiniLua is under MIT licence.

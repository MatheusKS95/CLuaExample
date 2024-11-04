#include <stdio.h>

#define LUA_IMPL
#include "minilua.h"

static int cprintint(lua_State *L)
{
	int value = lua_tonumber(L, 1);
	printf("%d\n", value);
	return 0;
}

static int cprintstr(lua_State *L)
{
	const char* value = lua_tostring(L, 1);
	printf("%s\n", value);
	return 0;
}

int main()
{
	lua_State *L = luaL_newstate();
	if(L == NULL) return -1;

	luaL_openlibs(L);

	lua_register(L, "cprintint", cprintint);
	lua_register(L, "cprintstr", cprintstr);

	//Loading main.lua
	if (luaL_dofile(L, "main.lua") != LUA_OK)
	{
		fprintf(stderr, "Failed to load main.lua: %s\n", lua_tostring(L, -1));
		lua_close(L);
		return -1;
	}

	//Calling test_init from main.lua and sending a parameter
	lua_getglobal(L, "test_init");
	lua_pushstring(L, "test");  //Sending "test" but could be anything
	if (lua_pcall(L, 1, 0, 0) != LUA_OK) {
		fprintf(stderr, "Failed to call test_init: %s\n", lua_tostring(L, -1));
	}

	//Calling "test_callc" with 2 arguments - keep in mind Lua uses stack
	lua_getglobal(L, "test_callc");
	lua_pushinteger(L, 4);  //1st arg
	lua_pushinteger(L, 8); //2nd arg
	if (lua_pcall(L, 2, 0, 0) != LUA_OK) {
		fprintf(stderr, "Failed to call test_callc: %s\n", lua_tostring(L, -1));
	}

	lua_close(L);
	return 0;
}
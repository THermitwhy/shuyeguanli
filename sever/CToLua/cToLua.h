#ifndef CTOLUA_H
#define CTOLUA_H
extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int sqlToLua(lua_State *L);
//int idToLua(lua_State *L);
//int doToLua(lua_State *L);
extern "C" int luaopen_libcToLua(lua_State *L);

#endif
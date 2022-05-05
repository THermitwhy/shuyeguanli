#ifndef LUA_CPP_H
#define LUA_CPP_H
extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include <iostream>
#include <string>
#include <vector>

int loadLua(std::vector<std::string> &vec_field,std::vector<std::vector<std::string> > &vec_result,int &param,int sqlid,std::vector<std::string> params);
#endif
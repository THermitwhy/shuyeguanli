#include "cToLua.h"
#include "sql_lua.h"


int sqlToLua(lua_State *L)
{
    int row,column;
	std::cout<<"sqlToLua"<<std::endl;
    std::vector<std::string> vec_field;
    std::vector<std::vector<std::string> > vec_result;
    int num = lua_gettop(L);
	std::cout<<"num="<<num<<std::endl;
    if(num!=1)
    {
        lua_pushstring(L,"error");
        return 1;
    }
    std::string sql=lua_tostring(L,num);
	std::cout<<"sql="<<sql<<std::endl;
    if(getSelect(vec_result,sql,vec_field,row,column)!=1)
    {
        lua_pushstring(L,"error");
        return 1;
    }
 
 	lua_newtable(L);
	
    for(int i = 0; i < vec_field.size(); i++)
	{
		lua_pushinteger(L, i + 1);   //压入表key值，这里是1~n的整数
		lua_pushstring(L, vec_field[i].c_str());  // 压入key对应的value值
		lua_settable(L, -3);  //此时表位于-3
	}
	
	
	lua_newtable(L);
	for(int k = 0; k < vec_result.size(); k++)
	{
		lua_pushinteger(L, k + 1);  //压入主表key值，为1~K的连续整数
		lua_newtable(L);  //创建一个子表
		
		// 构造主表key值对应的value值，该value值是一个子表 
		for(int i = 0; i < vec_result[k].size(); i++)
		{
			lua_pushinteger(L, i + 1);   //压入表key值，这里是1~n的整数
			lua_pushstring(L, vec_result[k][i].c_str());  // 压入key对应的value值
			lua_settable(L, -3);  //此时表位于-3
		}
			
		lua_settable(L, -3);   //主表位于-3	
	}
    
    return 2;
}







//使用luaL_Reg注册新的C函数到Lua中
static luaL_Reg test_functions[] = 
{
	{"sqlToLua", sqlToLua},
	{NULL, NULL}   //数组中最后一对必须是{NULL, NULL}，用来表示结束 
};
 
 
/* luaopen_XXX，XXX为库名称，若库名称为testlib.so，XXX即为testlib */
int luaopen_libcToLua(lua_State *L)
{
	SQL_INIT();
	luaL_newlib(L, test_functions);  //Lua 5.2之后用luaL_newlib代替了luaL_register
	return 1;
}
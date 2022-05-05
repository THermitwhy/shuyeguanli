extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include <iostream>
#include <string>
#include <vector>

int loadLua(std::vector<std::string> &vec_field,std::vector<std::vector<std::string> > &vec_result,int &param,int sqlid,std::vector<std::string> params){
    lua_State *L = luaL_newstate();
    if(!L)
    {
        std::cout<<"lua_State error"<<std::endl;
        return -1;
    }
    luaL_openlibs(L);
    int bRet = luaL_loadfile(L, "/home/luatest/test.lua");
    if(bRet)
    {
        std::cout<<"luaL_loadfile error"<<std::endl;
        return -2;
    }
    
    bRet = lua_pcall(L, 0,0,0);
    if(bRet)
    {
        std::cout<<"lua_pcall error"<<std::endl;
        return -3;
    }
    
    std::vector<std::string> vec1;
    vec1.push_back("why");
    vec1.push_back("12345");
    lua_getglobal(L,"TypeJudgment");
    lua_pushinteger(L,sqlid);
    lua_newtable(L);
    for(int i=0;i<params.size();i++)
    {
        lua_pushinteger(L, i+1);
        lua_pushstring(L, params[i].c_str());
        lua_settable(L, -3);
    }
    bRet = lua_pcall(L, 2,3,0);
    if(bRet)
    {
        std::cout<<"lua_pcall error"<<std::endl;
        return -4;
    }
    param=lua_tointeger(L, -1);
    lua_pop(L, 1);
    std::cout<<"param:"<<param<<std::endl;
    if(lua_istable(L,-1))
    {
        std::cout<<"lua_istable"<<std::endl;
    }
    int size=lua_rawlen(L,-1);
    
    for(int i=1;i<=size;i++)
    {
        std::vector<std::string> vec_unuse;
        std::cout<<"size="<<size<<std::endl;
        lua_pushinteger(L, i);
        lua_gettable(L, -2);
        int  nIndex  =  lua_gettop( L ); 
        std::cout<<"nIndex="<<nIndex<<std::endl;  //  取 table 索引值 
        lua_pushnil( L );   //  nil 入栈作为初始 key 
        while (  0   !=  lua_next( L, nIndex ) ) 
        { 
            std::string x = lua_tostring( L, -1 );   //  取出 value
            vec_unuse.push_back(x);
            std::cout<<x<<std::endl;
            // 这里可以判断 key 是什么并且对 value 进行各种处理 
            lua_pop( L, 1 );  // 弹出 value，让 key 留在栈顶 
        } 
        vec_result.push_back(vec_unuse);
        lua_pop(L,1);
    }
    int  nIndex  =  lua_gettop( L );
    std::cout<<"n_Index="<<nIndex<<std::endl;
    if(int bRett=lua_istable(L,-1))
    {
        std::cout<<"lua_istable"<<std::endl;
        std::cout<<lua_rawlen(L,-1)<<std::endl;
    }
    lua_pop(L,1);
    size=lua_rawlen(L,-1);
    std::cout<<"size_new="<<size<<std::endl;
    nIndex  =  lua_gettop( L ); 
    std::cout<<"nIndex_new="<<nIndex<<std::endl;  //  取 table 索引值
    lua_pushnil( L );   //  nil 入栈作为初始 key
    while (  0   !=  lua_next( L, nIndex ) ) 
    { 
        std::string x = lua_tostring( L, -1 );   //  取出 value
        vec_field.push_back(x);
        std::cout<<x<<std::endl;
        // 这里可以判断 key 是什么并且对 value 进行各种处理 
        lua_pop( L, 1 );  // 弹出 value，让 key 留在栈顶 
    }
    lua_close(L);
    return 1;
}

/*
int main()
{
    std::vector<std::string> vec_field;
    std::vector<std::vector<std::string> > vec_result;
    int param;
    int sqlid=1;
    std::vector<std::string> params;
    params.push_back("why");
    params.push_back("1234567");
    loadLua(vec_field,vec_result,param,sqlid,params);
    std::cout<<"param:"<<param<<"field:"<<vec_field[0]<<"result"<<vec_result[0][0]<<std::endl;
    return 0;
}
*/

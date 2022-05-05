cmake_minimum_required (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "-std=c++0x")
project (cToLua)
#include_directories(include_directories)
#lua通过该动态库执行sql语句
add_library(cToLua SHARED  sql_lua.cpp cToLua.cpp)

#include_libraries(${LUA_INCLUDE_DIR})
#add_executable(vec ${lua_src})
target_link_libraries(cToLua  liblua.a dl )


execute_process(COMMAND mysql_config --cflags 
    OUTPUT_VARIABLE MYSQL_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE) 
execute_process(COMMAND mysql_config --libs 
    OUTPUT_VARIABLE MYSQL_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE) 

target_compile_options(cToLua PUBLIC ${MYSQL_CFLAGS}) 
target_link_libraries(cToLua ${MYSQL_LIBS}) 

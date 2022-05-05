cmake_minimum_required (VERSION 2.6)
SET(CMAKE_CXX_FLAGS "-std=c++0x")
project (test_lua)
add_executable(test_lua sql_sy.cpp json.cpp lua_CPP.cpp  socket.cpp)

target_link_libraries(test_lua  liblua.a dl )

execute_process(COMMAND mysql_config --cflags 
    OUTPUT_VARIABLE MYSQL_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE) 
execute_process(COMMAND mysql_config --libs 
    OUTPUT_VARIABLE MYSQL_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE) 

target_compile_options(test_lua PUBLIC ${MYSQL_CFLAGS}) 
target_link_libraries(test_lua ${MYSQL_LIBS}) 

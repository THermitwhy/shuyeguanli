#ifndef JSON_H
#define JSON_H
#include <iostream>
#include <string>
#include <vector>
#include "rapidjson/writer.h"
#include "rapidjson/document.h"
//#include "include/rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "sql_sy.h"
#include <regex>


std::string vec2json(std::vector<std::string>& vec1, std::vector<std::vector <std::string> >& vec,std::string sqlid);
int str2sql(std::vector<std::string> str,std::string &sql);
int json2param(std::string json_str,int &sqlid, int &count, std::vector<std::string> &param);
#endif
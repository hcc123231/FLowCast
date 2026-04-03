#pragma once
#include<unordered_map>
#include<iostream>
#include<string>
//配置数据模型
struct ConfigModel{
    std::string operator []( std::string key)const{return m_kv_.at(key);}
    std::unordered_map<std::string,std::string> m_kv_;
};
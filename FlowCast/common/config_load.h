#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include<sstream>
#include "config_model.h"
// 配置加载
class ConfigLoader
{
public:
    ConfigLoader(const std::string &url, ConfigModel &model) : m_url_{url}, m_model_{model} {}
    ~ConfigLoader() {}
    void load()
    {
        std::ifstream ifs{m_url_, std::ios::in};
        if (!ifs.is_open())
        {
            std::cout << "ConfigLoader::load\n";
            exit(-1);
        }
        std::string lineStr{""};

        while (std::getline(ifs, lineStr))
        {
            removeSpaceLine(lineStr);
            std::istringstream iss{lineStr};
            std::string key{""};
            std::string value{""};
            iss>>key>>value;
            m_model_.m_kv_[key]=value;
        }
    }
    // 去除getLine读到的整行前缀空格和后缀空格
    void removeSpaceLine(std::string &str)
    {
        // 去除左侧空格
        str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
        // 去除右侧空格
        str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);
    }

private:
    const std::string m_url_;
    ConfigModel &m_model_;
};
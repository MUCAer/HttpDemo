#pragma once 
#include <string>

class StrategyManager {
public:
  static StrategyManager& get_instance() {
    static StrategyManager instance;
    return instance;
  };  

  std::string do_response(const std::string& cmd) {
    std::string ret("{\"url\":\"");
    ret += cmd;
    
    return ret;
  }

  int init() {
    return 0;    
  }
  
};

//
//  main.cpp
//  vlib
//
//  Created by Vasyl Mykhalchuk on 15/09/2019.
//  Copyright © 2019 Vasyl Mykhalchuk. All rights reserved.
//

#include <iostream>
#include <vector>
#include "string_parser.h"

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  
  using namespace atlib;
  using namespace std;
  
//  string_parser<vector<int>>::parse("df", ",.");
  auto v = vector<int>(0);
  auto s = std::string(".df,s,");
  auto d = ".,";
  auto c = string_parser::countWords(s, d);
  
  auto words = string_parser::split<vector<string>>(s, d);
  
  return 0;
}

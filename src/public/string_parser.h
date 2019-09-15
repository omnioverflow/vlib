#pragma once

#include <string>
#include <sstream>

namespace atlib {
  
  class string_parser {
  public:
    
    template <class T>
    static T split(const std::string& s, const std::string& delims) {
      if (delims.empty())
        return T{s};
      else if (delims.size() == 1) {
        T words;
        const auto delim = delims.front();
        std::stringstream sstream(s);
        std::string word;
        while (std::getline(sstream, word, delim))
          if (!word.empty())
            words.emplace_back(word);
        
        return words;
      }
      
      T words;
      std::size_t prev = 0u;
      std::size_t curr = s.find_first_of(delims);
      while (curr != std::string::npos) {
        const auto word = s.substr(prev, curr - prev);
        if (!word.empty())
          words.emplace_back(word);
        
        prev = curr + 1;
        curr = s.find_first_of(delims, prev);
      }
      const auto lastWord = s.substr(prev, curr - prev);
      if (!lastWord.empty())
        words.emplace_back(lastWord);
      
      return words;
    }
    
    static size_t countWords(const std::string& s, const std::string& delims) {
      if (delims.empty())
        return 0u;
      
      size_t count = 0u;
      size_t prev = 0u;
      size_t curr = s.find_first_of(delims);
      while (curr != std::string::npos) {
        const auto word = s.substr(prev, curr - prev);
        if (!word.empty())
          ++count;
        
        prev = curr + 1;
        curr = s.find_first_of(delims, prev);
      }
      const auto lastWord = s.substr(prev, curr - prev);
      if (!lastWord.empty())
        ++count;
      
      return count;
    };
  }; // class string_parser
} // namespace

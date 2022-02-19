#pragma mark once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace atl {
  namespace text {
    class TextAnalyzer {
    public:
      TextAnalyzer(const std::string& s, bool ingoreCase);
      TextAnalyzer(const std::string& s,
                   const std::vector<std::string>& banned,
                   bool ignoreCase);
      
      void setBannedWords(const std::vector<std::string>& banned);
      void buildWordFreq();
      std::string freqRankWord(size_t rank) const;
    private:
      
      inline std::string defaultDelims() { return " ,."; }
      
      std::string mText;
      std::unordered_set<std::string> mBanned;
      bool mIgnoreCase;
      std::unordered_map<std::string, size_t> mWordFreq;
    }; // class TextAnalyzer
  } // namespace text
} // namespace atl

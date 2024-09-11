/// @copyright 2024 HX

#include "n49.h"
#include "unordered_map"
#include "hash_set"
#include "algorithm"

vector<vector<string>> Solution::groupAnagrams(vector<string>& strs) {
  vector<vector<string>> result;
  std::unordered_map<std::string, std::vector<std::string>> hash;
  for (auto& str : strs) {
    std::string s = str;
    std::sort(s.begin(), s.end());
    hash[s].emplace_back(str);
  }

  for (const auto& it : hash) {
    result.emplace_back(it.second);
  }
  return result;
}

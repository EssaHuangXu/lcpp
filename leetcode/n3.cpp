// @copyright 2024 HX
#include "n3.h"

#include <algorithm>
#include <map>

int Solution::lengthOfLongestSubstring(const std::string s) {
  std::map<char, int> map;
  auto result = -1;
  auto begin = 0;
  for (auto i = 0; i < s.size(); i++) {
    auto cur = s.at(i);
    if (map.count(cur) == false) {
      map.emplace(cur, i);
    } else {
      if (map.at(cur) < begin) {
        map[cur] = i;
        continue;
      }
      result = std::max(result, i - begin);
      begin = map.at(cur) + 1;
      map[cur] = i;
    }
  }

  result = std::max(result, static_cast<int>(s.size()) - begin);
  return result;
}

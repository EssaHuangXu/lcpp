// @copyright 2024 HX

#include "n483.h"

#include <unordered_set>

std::vector<int> Solution::findAnagrams(const std::string s,
                                        const std::string p) {
  auto pSize = p.size();
  auto sSize = s.size();
  std::vector<int> result;
  if (pSize > sSize) {
    return result;
  }
  std::vector<int> target(26);
  std::vector<int> compare(26);
  for (const auto& c : p) {
    target[c - 'a']++;
  }

  for (auto index = 0; index < sSize; index++) {
    compare[s.at(index) - 'a']++;
    if (index >= pSize) {
      compare[s.at(index - pSize) - 'a']--;
    }

    if (compare == target) {
      result.emplace_back(index - pSize + 1);
    }
  }
  return result;
}

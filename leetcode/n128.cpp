/// @copyright 2024 HX

#include "n128.h"
#include <unordered_set>
#include <algorithm>


int Solution::longestConsecutive(vector<int>& nums) {
  std::unordered_set<int> set;
  for (auto& num : nums) {
    set.emplace(num);
  }

  int maxLength = 0;
  for (const auto& num : set) {
    if (set.count(num - 1) == false) {
      int curLength = 1;
      while (set.count(num + curLength) == true) {
        curLength++;
      }

      maxLength = std::max(maxLength, curLength);
    }
  }
  return maxLength;
}

// @copyright 2024 HX

#include "n41.h"

#include <unordered_set>

int Solution::firstMissingPositive(const std::vector<int>& nums) {
  int result = 1;
  std::unordered_set<int> set;
  for (auto num : nums) {
    if (set.count(num) == false) {
      set.emplace(num);
    }
  }

  for (auto i = 0; i < set.size(); i++) {
    if (set.count(result) == true) {
      result++;
    } else {
      break;
    }
  }
  return result;
}

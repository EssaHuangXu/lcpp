// @copyright 2024 HX

#include "n560.h"

int Solution::subarraySum(const std::vector<int>& nums, const int k) {
  int count = 0;
  for (auto i = 0; i < nums.size(); i++) {
    auto target = k - nums[i];
    for (auto j = i + 1; j < nums.size(); j++) {
      target = target - nums[j];
      if (target < 0) {
        break;
      }
      if (target == 0) {
        count++;
      }
    }
  }
  return count;
}

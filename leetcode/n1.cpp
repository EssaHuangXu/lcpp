// @copyright 2024 HX

#include "n1.h"

#include <vector>
#include <map>

vector<int> Solution::twoSum(vector<int>& nums, int target) {
  std::map<int, int> map;
  for (size_t i = 0; i < nums.size(); i++) {
    if (map.count(target - nums[i])) {
      return { map[target - nums[i]], static_cast<int>(i) };
    } else {
      map.emplace(nums[i], i);
    }
  }
  return { 0 };
}

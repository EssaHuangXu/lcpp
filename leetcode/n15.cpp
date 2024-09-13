// @copyright 2024 HX

#include "n15.h"

#include <algorithm>
#include <map>
#include <unordered_set>

std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums) {
  std::vector<std::vector<int>> result;
  std::sort(nums.begin(), nums.end());
  for (auto i = 0; i < nums.size(); i++) {
    if (i > 0 && nums[i] == nums[i - 1]) {
      continue;
    }

    const auto target = -nums[i];

    auto begin = i + 1;
    auto end = nums.size() - 1;
    while (begin < end) {
      auto left = nums[begin];
      auto right = nums[end];

      if (begin > i + 1 && nums[begin] == nums[begin - 1]) {
        begin++;
        continue;
      }

      if (left + right == target) {
        std::vector<int> v = {-target, left, right};
        result.emplace_back(v);
        begin++;
        end--;
      } else if (left + right < target) {
        begin++;
      } else if (left + right > target) {
        end--;
      }
    }
  }
  return result;
}

// @copyright 2024 HX

#include "n53.h"

#include <algorithm>

int Solution::maxSubArray(const std::vector<int>& nums) {
  auto result = nums[0];
  auto dpmax = nums[0];  // dp i - 1  dp[i] = max(dp[i - 1] + current, current)
  for (auto index = 1; index < nums.size(); index++) {
    auto num = nums[index];
    dpmax = std::max(dpmax + num, num);
    result = std::max(dpmax, result);  // record max value
  }
  return result;
}

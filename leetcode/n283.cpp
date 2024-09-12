// @copyright 2024 HX

#include "n283.h"
#include <utility>
#include <algorithm>

void Solution::moveZeroes(vector<int>& nums) {
  if (nums.size() <= 0) {
    return;
  }

  size_t zeroIndex = -1;
  for (size_t i = 0; i < nums.size(); i++) {
    if (nums[i] != 0) {
      if (zeroIndex == -1) {
        // find first zero
        continue;
      } else {
        std::swap(nums[zeroIndex], nums[i]);
        zeroIndex = std::min(zeroIndex + 1, i);
      }
    } else {
      if (zeroIndex == -1) {
        zeroIndex = i;
      }
    }
  }
}

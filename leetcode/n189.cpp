// @copyright 2024 HX

#include "n189.h"

#include <numeric>

void Solution::rotate(std::vector<int>& nums, int k) {
  auto size = nums.size();
  auto count = std::gcd(k, size);
  for (auto i = 0; i < count; i++) {
    auto moveIndex = i;
    auto temp = nums[moveIndex];
    do {
      auto target = (moveIndex + k) % size;
      auto swap = nums[target];
      nums[target] = temp;
      temp = swap;
      moveIndex = target;
    } while (moveIndex != i);
  }
}

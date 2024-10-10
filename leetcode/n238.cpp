// @copyright 2024 HX

#include "n238.h"

std::vector<int> Solution::productExceptSelf(const std::vector<int>& nums) {
  std::vector<int> result;
  const auto size = nums.size();
  if (size == 0) return result;

  if (size <= 1) {
    result.push_back(0);
    return result;
  }

  // set first leftmul(0) is 1
  result.push_back(1);
  for (int i = 1; i < size; i++) {
    result.push_back(result.at(i - 1) * nums.at(i - 1));
  }

  int rightMulti = 1;
  for (int j = size - 2; j >= 0; j--) {
    rightMulti = rightMulti * nums.at(j + 1);
    result[j] = result.at(j) * rightMulti;
  }

  return result;
}

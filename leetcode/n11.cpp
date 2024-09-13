// @copyright 2024 HX

#include "n11.h"

#include <algorithm>

int Solution::maxArea(const std::vector<int>& height) {
  int left = 0;
  int right = height.size() - 1;
  int szie = 0;
  while (left < right) {
    int area = std::min(height[left], height[right]) * (right - left);
    szie = std::max(szie, area);
    if (height[left] <= height[right]) {
      ++left;
    } else {
      --right;
    }
  }
  return szie;
}

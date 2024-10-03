// @copyright 2024 HX

#include "n56.h"

#include <algorithm>

std::vector<std::vector<int>> Solution::merge(
    std::vector<std::vector<int>>& intervals) {
  std::vector<std::vector<int>> res;
  std::sort(intervals.begin(), intervals.end());

  for (auto intr : intervals) {
    if (res.empty() || res.back()[1] < intr[0]) {
      res.push_back(intr);
    } else {
      res.back()[1] = std::max(res.back()[1], intr[1]);
    }
  }
  return res;
}

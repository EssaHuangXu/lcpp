// @copyright 2024 HX

#include "n560.h"

#include <unordered_map>

int Solution::subarraySum(const std::vector<int>& nums, const int k) {
  int result = 0;
  std::unordered_map<int, int> map;
  auto sum = 0;
  map.emplace(0, 1);

  // map <sum[j - 1], count>, when sum[cur] - sum[j - 1] = k  ===> sum[j -1] =
  // sum[cur] - k
  for (auto cur = 0; cur < nums.size(); cur++) {
    sum += nums[cur];
    auto target = sum - k;
    if (map.count(target)) {
      result += map[target];
    }
    map[sum]++;
  }

  return result;
}

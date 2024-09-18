// @copyright 2024 Hx

#include "fibonacci.h"


std::vector<int> Solution::GetFibonacci(int count) {
  std::vector<int> result;

  result.emplace_back(1);
  if (count == 0) {
    return result;
  }

  result.emplace_back(1);
  if (count == 1) {
    return result;
  }
  
  int dp[2];
  dp[0] = 1;
  dp[1] = 1;

  for (auto i = 2; i < count - 1; i++) {
    auto d = dp[1];
    dp[1] = dp[0] + dp[1];
    dp[0] = d;
    result.emplace_back(dp[1]);
  }

  return result;
}

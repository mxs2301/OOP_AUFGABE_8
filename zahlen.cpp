#include "zahlen.h"
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> sum(const std::vector<int> &nums, int n) {

  std::vector<int> points;

  int x = 0;

  for (int i = 0; i < nums.size() - 1; i++) {
    for (int j = i; j < nums.size() - 1; j++) {
      if (nums[j] + nums[i] == n) {
        points.push_back(i);
        points.push_back(j);
      }
    }
  }

  return points;
}

std::vector<int> sumMap(const std::vector<int> &nums, int n) {
  std::vector<int> points;
  std::unordered_map<int, int> karte;

  for (int i = 0; i < nums.size(); i++) {
    if (karte.find(n - nums[i]) != karte.end()) {
      points.emplace_back(i);
      points.emplace_back(karte[n - nums[i]]);
      return points;
    }
    karte[nums[i]] = i;
  }
  return points;
  return points;
}

void print(const std::vector<int> &input) {

  std::cout << "{ ";
  for (int i = 0; i < input.size(); i++) {
    std::cout << input.at(i) << " ";
  }
  std::cout << "}\n";
}

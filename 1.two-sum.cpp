/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (45.15%)
 * Likes:    13911
 * Dislikes: 509
 * Total Accepted:    2.7M
 * Total Submissions: 5.9M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * Example:
 *
 *
 * Given nums = [2, 7, 11, 15], target = 9,
 *
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 *
 *
 */
#include "common.h"
// @lc code=start
class Solution {
 public:
  vector<int> twoSum(const vector<int>& nums, int target) {
    map<int, int> index_map;
    for(auto i = 0; i < nums.size(); i++){
      auto diff = target - nums[i];
      if(index_map.find(diff) != index_map.end()){
        return {index_map[diff], i};
      }
      index_map[nums[i]] = i;
    }
    return {};
  }
};
// @lc code=end

int main() {
  put(Solution().twoSum({2,7,11,15}, 9));
  return 0;
}

/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 *
 * https://leetcode.com/problems/search-insert-position/description/
 *
 * algorithms
 * Easy (41.50%)
 * Likes:    1884
 * Dislikes: 225
 * Total Accepted:    533.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,3,5,6]\n5'
 *
 * Given a sorted array and a target value, return the index if the target is
 * found. If not, return the index where it would be if it were inserted in
 * order.
 *
 * You may assume no duplicates in the array.
 *
 * Example 1:
 *
 *
 * Input: [1,3,5,6], 5
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: [1,3,5,6], 2
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: [1,3,5,6], 7
 * Output: 4
 *
 *
 * Example 4:
 *
 *
 * Input: [1,3,5,6], 0
 * Output: 0
 *
 *
 */
#include "common.h"
// @lc code=start
class Solution {
 public:
  int partial(const vector<int>& nums, int target, int head, int end) {
    if (head >= end) return (nums[head] < target) ? head + 1 : head;
    auto mid = (end - head) / 2 + head;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      return partial(nums, target, head, mid - 1);
    } else {
      return partial(nums, target, mid + 1, end);
    }
  }
  int searchInsert(const vector<int>& nums, int target) {
    return partial(nums, target, 0, nums.size() - 1);
  }
};
// @lc code=end
int main() {
  put(Solution().searchInsert({1, 3, 4, 5}, 6));
  return 0;
}

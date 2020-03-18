/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 *
 * https://leetcode.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (46.88%)
 * Likes:    1989
 * Dislikes: 1488
 * Total Accepted:    828.8K
 * Total Submissions: 1.8M
 * Testcase Example:  '121'
 *
 * Determine whether an integer is a palindrome. An integer is a palindrome
 * when it reads the same backward as forward.
 *
 * Example 1:
 *
 *
 * Input: 121
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: -121
 * Output: false
 * Explanation: From left to right, it reads -121. From right to left, it
 * becomes 121-. Therefore it is not a palindrome.
 *
 *
 * Example 3:
 *
 *
 * Input: 10
 * Output: false
 * Explanation: Reads 01 from right to left. Therefore it is not a
 * palindrome.
 *
 *
 * Follow up:
 *
 * Coud you solve it without converting the integer to a string?
 *
 */
#include "common.h"
// @lc code=start
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x < 10) return true;
    if (x % 10 == 0) return false;
    auto reverse = 0;
    while (x > reverse) {
      auto unit = x % 10;
      x /= 10;
      if (x == reverse) return true;
      reverse *= 10;
      reverse += unit;
      if (x == reverse) return true;
    }
    return false;
  }
};
// @lc code=end
int main() {
  put(Solution().isPalindrome(123210));
  return 0;
}
